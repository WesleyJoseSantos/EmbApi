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
#include "EmbapiMessage/EmbapiMessageJson.h"
#include "EmbapiMessage/WifiConfigJson.h"
#include "EmbapiMessage/NtpConfigJson.h"
#include "EmbapiMessage/MqttConfigJson.h"

EmbapiError EmbapiConfigJson::toJson(JsonDocument *doc)
{
    (*doc)["id"] = this->id;

    switch (id)
    {
        case EMBAPI_CONFIG_ID_UNKNOWN:
            return EmbapiError::UNKNOWN_ID;
        case EMBAPI_CONFIG_ID_WIFI:
            return WifiConfigJson(this->config.wifi).toJson(doc);
        case EMBAPI_CONFIG_ID_ETHERNET:
            return EmbapiError::NOT_IMPLEMENTED;
        case EMBAPI_CONFIG_ID_SERIAL:
            return EmbapiError::NOT_IMPLEMENTED;
        case EMBAPI_CONFIG_ID_BLUETOOTH:
            return EmbapiError::NOT_IMPLEMENTED;
        case EMBAPI_CONFIG_ID_NTP:
            return NtpConfigJson(this->config.ntp).toJson(doc);
        case EMBAPI_CONFIG_ID_MQTT:
            return MqttConfigJson(this->config.mqtt).toJson(doc);
    }
    return EmbapiError::NO_ERROR;
}

EmbapiError EmbapiConfigJson::fromJson(JsonDocument *doc)
{
    this->id = (*doc)["id"];

    switch (id)
    {
        case EMBAPI_CONFIG_ID_UNKNOWN:
            (*doc)["error"] = EmbapiError::UNKNOWN_ID;
            return EmbapiError::UNKNOWN_ID;;
        case EMBAPI_CONFIG_ID_WIFI:
            this->config.wifi = WifiConfigJson(doc);
            break;
        case EMBAPI_CONFIG_ID_ETHERNET:
            (*doc)["error"] = EmbapiError::NOT_IMPLEMENTED;    
            return EmbapiError::NOT_IMPLEMENTED;;
        case EMBAPI_CONFIG_ID_SERIAL:
            (*doc)["error"] = EmbapiError::NOT_IMPLEMENTED;    
            return EmbapiError::NOT_IMPLEMENTED;;
        case EMBAPI_CONFIG_ID_BLUETOOTH:
            (*doc)["error"] = EmbapiError::NOT_IMPLEMENTED;    
            return EmbapiError::NOT_IMPLEMENTED;;
        case EMBAPI_CONFIG_ID_NTP:
            this->config.ntp = NtpConfigJson(doc);
            break;
        case EMBAPI_CONFIG_ID_MQTT:
            this->config.mqtt = MqttConfigJson(doc);
            break;
    }

    return EmbapiError::NO_ERROR;
}
