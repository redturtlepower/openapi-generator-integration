#ifndef CUSTOMAPIROUTER_H
#define CUSTOMAPIROUTER_H

#include "OAIApiRouter.h"

#include "custompetsapihandler.h"

class CustomApiRouter : public OpenAPI::OAIApiRouter
{
public:
    CustomApiRouter(){
        createApiHandlers();
    }
protected:
    void createApiHandlers() override{
        setOAIPetsApiHandler(
                QSharedPointer<CustomPetsApiHandler>::create());
    }
};

#endif // CUSTOMAPIROUTER_H
