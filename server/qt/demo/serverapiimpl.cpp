#include "serverapiimpl.h"
#include "testserverdefinition.h"

ServerApiImpl::ServerApiImpl(QObject *parent)
    : QObject(parent)
{
    qDebug()<<"Ctor ServerApiImpl";

    handler = QSharedPointer<OpenAPI::OAIApiRequestHandler>::create();

    /* Do not use the default router!
       We use our customized router to demonstrate how to
       make use of generic API code generation whilst still being
       able to customize business logic. */
    //router = QSharedPointer<OpenAPI::OAIApiRouter>::create();
    router = QSharedPointer<CustomApiRouter>::create();
    router->setUpRoutes();

    QObject::connect(handler.data(), &OpenAPI::OAIApiRequestHandler::requestReceived,
                     [&](QHttpEngine::Socket *socket) {
        router->processRequest(socket);
    });
    server = QSharedPointer<QHttpEngine::Server>::create(handler.data());

    QHostAddress address(ServerConstants::host);
    int port = ServerConstants::port;
    qDebug() << "Serving on " << address.toString() << ":" << port;
    // Attempt to listen on the specified port
    isListening_ = server->listen(address, port);
    if (!isListening_){
        qCritical("Unable to listen on the specified port.");
        Logger::getLogger().log("Unable to listen on the specified port "+QString::number(port) );
    }else{
        Logger::getLogger().log("The server is running on " + ServerConstants::host +":" + QString::number(port));
        qDebug()<<"The mock server is running.";
    }
}
