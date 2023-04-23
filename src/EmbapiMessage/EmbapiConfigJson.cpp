/**
 * @file EmbapiConfigJson.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-04-21
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "EmbapiCore/EmbapiError.h"
#include "EmbapiMessage/EmbapiConfigJson.h"
#include "EmbapiMessage/WifiConfigJson.h"
#include "EmbapiMessage/NtpConfigJson.h"
#include "EmbapiMessage/MqttConfigJson.h"

void EmbapiConfigJson::toJson(JsonDocument *doc)
{
    (*doc)["id"] = this->id;

    switch (id)
    {
        case EMBAPI_CONFIG_ID_UNKNOWN:
            this->error = EmbapiError::UNKNOWN_ID;
            break;
        case EMBAPI_CONFIG_ID_WIFI:
            WifiConfigJson(this->config.wifi).toJson(doc);
            break;
        case EMBAPI_CONFIG_ID_ETHERNET:
            this->error = EmbapiError::NOT_IMPLEMENTED;
            break;
        case EMBAPI_CONFIG_ID_SERIAL:
            this->error = EmbapiError::NOT_IMPLEMENTED;
            break;
        case EMBAPI_CONFIG_ID_BLUETOOTH:
            this->error = EmbapiError::NOT_IMPLEMENTED;
            break;
        case EMBAPI_CONFIG_ID_NTP:
            NtpConfigJson(this->config.ntp).toJson(doc);
            break;
        case EMBAPI_CONFIG_ID_MQTT:
            MqttConfigJson(this->config.mqtt).toJson(doc);
            break;
    }
}

void EmbapiConfigJson::fromJson(JsonDocument *doc)
{
    this->id = (*doc)["id"];

    switch (id)
    {
        case EMBAPI_CONFIG_ID_UNKNOWN:
            (*doc)["error"] = EmbapiError::UNKNOWN_ID;
            break;
        case EMBAPI_CONFIG_ID_WIFI:
            this->config.wifi = WifiConfigJson(doc);
            break;
        case EMBAPI_CONFIG_ID_ETHERNET:
            (*doc)["error"] = EmbapiError::NOT_IMPLEMENTED;    
            break;
        case EMBAPI_CONFIG_ID_SERIAL:
            (*doc)["error"] = EmbapiError::NOT_IMPLEMENTED;    
            break;
        case EMBAPI_CONFIG_ID_BLUETOOTH:
            (*doc)["error"] = EmbapiError::NOT_IMPLEMENTED;    
            break;
        case EMBAPI_CONFIG_ID_NTP:
            this->config.ntp = NtpConfigJson(doc);
            break;
        case EMBAPI_CONFIG_ID_MQTT:
            this->config.mqtt = MqttConfigJson(doc);
            break;
    }
}