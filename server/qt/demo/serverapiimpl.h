#ifndef SERVERAPIIMPL_H
#define SERVERAPIIMPL_H

#include <QObject>

#include "qhttpengine/server.h"
#include "OAIApiRouter.h"
#include "customapirouter.h"

class ServerApiImpl : public QObject
{
    Q_OBJECT
    QSharedPointer<OpenAPI::OAIApiRequestHandler> handler;
    QSharedPointer<OpenAPI::OAIApiRouter> router;
    QSharedPointer<QHttpEngine::Server> server;
    int port_;
    bool isListening_ = false;
public:
    ServerApiImpl(QObject *parent = nullptr);
};

#endif // SERVERAPIIMPL_H
