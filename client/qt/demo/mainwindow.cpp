#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "ClientApiImpl.h"
#include "asyncfuture.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Client");
    api_ = new ClientApiImpl(this);
    connect(ui->pushButton,&QPushButton::clicked,this,&MainWindow::requestExistingPet);
    connect(ui->pushButton_2,&QPushButton::clicked,this,&MainWindow::requestNonExistingPet);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::requestExistingPet()
{
    QFuture<QString> future = api_->loadPetById("Pet_1");
    auto f =  QSharedPointer<AsyncFuture::Observable<QString>>::create(future);
    f->onCompleted([this, f]() mutable{
        qDebug()<<"Result availabe";
        ui->plainTextEdit->setPlainText(f->future().result());
        f.reset();
    });
}

void MainWindow::requestNonExistingPet()
{
    QFuture<QString> future = api_->loadPetById("Pet_2");
    AsyncFuture::Observable<QString> f(future);
    f.onCompleted([this, f](){
        ui->plainTextEdit->setPlainText(f.future().result());
    });
}
