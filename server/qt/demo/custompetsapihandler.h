#ifndef CUSTOMPETSAPIHANDLER_H
#define CUSTOMPETSAPIHANDLER_H

#include "OAIPetsApiRequest.h"
#include "logger.h"

using namespace OpenAPI;
class CustomPetsApiHandler : public OAIPetsApiHandler{
public slots:
    void showPetById(QString pet_id) override{
        Logger::getLogger().log("CustomPetsApiHandler::showPetById "+pet_id);
        auto reqObj = qobject_cast<OAIPetsApiRequest*>(sender());
        if( reqObj != nullptr )
        {
            OAIPet res = loadPetFromDataBase(pet_id);
            QMultiMap<QString, QString> headers;
            headers.insert("Content-Type","application/json");
            reqObj->setResponseHeaders(headers);
            reqObj->showPetByIdResponse(res);
        }
    }
private:
    OAIPet loadPetFromDataBase(const QString &pet_id){
        bool pet_is_found = (pet_id == QString("Pet_1").toLower());
        OAIPet pet;
        if ( pet_is_found ){
            Logger::getLogger().log("Found pet with id "+pet_id );
            pet.setId(pet_id.toInt());
            pet.setName("Doggy dog");
            pet.setTag("bigfoot");
        }else{
            Logger::getLogger().log("Did not find pet with id "+pet_id );
        }
        return pet;
    }
};

#endif // CUSTOMPETSAPIHANDLER_H
