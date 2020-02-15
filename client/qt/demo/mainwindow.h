#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
class ClientApiImpl;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    ClientApiImpl *api_;
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void requestExistingPet();
    void requestNonExistingPet();
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
