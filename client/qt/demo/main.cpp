#include <QApplication>
#include <QTimer>

#include "mainwindow.h"
#include "OAIPetsApi.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.show();

//    OpenAPI::OAIPetsApi api;
//    api.setHost("127.0.0.1");
//    api.setPort(9230);
//    api.showPetById("Pet_1");

//    QNetworkAccessManager man;
//    QNetworkRequest req(QUrl("http://127.0.0.1:9230/v1/pets/Pet_1"));
//    qDebug()<<"Call api:"<<req.url();
//    auto reply = man.get(req);


    return a.exec();
}
