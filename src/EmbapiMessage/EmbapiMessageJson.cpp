/**
 * @file EmbapiMessageJson.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-04-22
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "EmbapiMessage/EmbapiMessageJson.h"
#include "EmbapiMessage/EmbapiConfigJson.h"

EmbapiError EmbapiMessageJson::toJson(JsonDocument *doc) {
    (*doc)["type"] = this->type;
    (*doc)["error"] = this->error;

    switch (type)
    {
        case EMBAPI_MESSAGE_TYPE_UNKNOWN:
            return EmbapiError::UNKNOWN_TYPE;
        case EMBAPI_MESSAGE_TYPE_CONFIG:
            return EmbapiConfigJson(this->data.config).toJson(doc);
    }

    return EmbapiError::NO_ERROR;
}

EmbapiError EmbapiMessageJson::fromJson(JsonDocument *doc) {
    this->type = (*doc)["type"];
    this->error = (*doc)["error"];

    switch (type)
    {
        case EMBAPI_MESSAGE_TYPE_UNKNOWN:
            this->error = EmbapiError::UNKNOWN_TYPE;
            return EmbapiError::UNKNOWN_TYPE;
        case EMBAPI_MESSAGE_TYPE_CONFIG:
            this->data.config = EmbapiConfigJson(doc);
            break;
    }
    
    return EmbapiError::NO_ERROR;
}
