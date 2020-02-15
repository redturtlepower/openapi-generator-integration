#include "ClientApiImpl.h"

#include "asyncfuture.h"
#include "OAIPetsApi.h"
#include "testserverdefinition.h"

using namespace OpenAPI;

ClientApiImpl::ClientApiImpl(QObject *parent)
    : QObject(parent)
{
}

QFuture<QString> ClientApiImpl::loadPetById(const QString &id)
{
    qDebug()<<"loadPetById";
    auto defer = AsyncFuture::deferred<QString>();
    auto api = createApiInstance();
    api->showPetById(id);
    connect(api,&OAIPetsApi::showPetByIdSignalFull,this,
            [api,defer](OAIHttpRequestWorker *worker, OAIPet summary) mutable
    {
        qDebug()<<"Response error:"<<worker->error_type;
        qDebug()<<"Response headers:"<<worker->getResponseHeaders();
        qDebug()<<"Pet arrived:";
        qDebug().noquote()<<summary.asJson();
        defer.complete(summary.asJson());
        api->deleteLater();
    });
    return defer.future();
}

OAIPetsApi *ClientApiImpl::createApiInstance()
{
    //auto api = QSharedPointer<OAIPetsApi>::create();
    auto api = new OAIPetsApi;
    api->setScheme(ServerConstants::scheme);
    api->setHost(ServerConstants::host);
    api->setPort(ServerConstants::port);
    return api;
}
