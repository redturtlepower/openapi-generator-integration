#ifndef IAPIINTEGRATION_H
#define IAPIINTEGRATION_H

#include <QFuture>
#include <QString>

class ClientApiInterface{
public:
    virtual ~ClientApiInterface() = default;
    virtual QFuture<QString> loadPetById(const QString &) = 0;
};
#endif // IAPIINTEGRATION_H
