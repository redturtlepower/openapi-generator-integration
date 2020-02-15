#ifndef APIINTEGRATION_H
#define APIINTEGRATION_H

#include "ClientApiInterface.h"

namespace OpenAPI{
    class OAIPetsApi;
}

class ClientApiImpl
      : public QObject
      , public ClientApiInterface
{
    Q_OBJECT
public:
    ClientApiImpl(QObject *parent = nullptr);

    // IApiIntegration interface
public:
    QFuture<QString> loadPetById(const QString &);
private:
    //QSharedPointer<OpenAPI::OAIPetsApi> createApiInstance();
    OpenAPI::OAIPetsApi *createApiInstance();
};

#endif // APIINTEGRATION_H
