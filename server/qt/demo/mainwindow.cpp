#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "logger.h"

#include "serverapiimpl.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Server");
    ui->plainTextEdit->setReadOnly(true);
    Logger::getLogger().setOutput(ui->plainTextEdit);

    // QObject clean up
    new ServerApiImpl(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

