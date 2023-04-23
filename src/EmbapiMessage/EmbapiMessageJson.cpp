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

void EmbapiMessageJson::toJson(JsonDocument *doc) {
    (*doc)["type"] = this->type;

    switch (type)
    {
        case EMBAPI_MESSAGE_TYPE_UNKNOWN:
            this->error = (*doc)["error"];
            break;
        case EMBAPI_MESSAGE_TYPE_CONFIG:
            EmbapiConfigJson(this->data.config).toJson(doc);
            break;
    }
}

void EmbapiMessageJson::fromJson(JsonDocument *doc) {
    this->type = (*doc)["type"];
    this->error = (*doc)["error"];

    switch (type)
    {
        case EMBAPI_MESSAGE_TYPE_UNKNOWN:
            this->error = EmbapiError::UNKNOWN_TYPE;
            break;
        case EMBAPI_MESSAGE_TYPE_CONFIG:
            this->data.config = EmbapiConfigJson(doc);
            break;
    }
}
