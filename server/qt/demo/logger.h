#ifndef LOGGER_H
#define LOGGER_H

#include <QPlainTextEdit>

class Logger{
    Logger() = default;
    QPlainTextEdit *output_;
public:
    Logger(const Logger &) = delete;
    void operator=(const Logger &) = delete;
    static Logger &getLogger(){
        static Logger logger;
        return logger;
    }
    void setOutput(QPlainTextEdit *t){
        output_ = t;
    }
    void log(const QString &t){
        Q_ASSERT(output_);
        output_->appendPlainText(t);
    }
};

#endif // LOGGER_H
