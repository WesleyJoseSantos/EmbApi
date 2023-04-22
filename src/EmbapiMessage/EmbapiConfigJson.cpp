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

#include "EmbapiMessage/EmbapiConfigJson.h"
#include "ArduinoJson.h"

#define JSON_DOC_SIZE (sizeof(EmbapiConfigJson)*2)
#define JSON_CHAR_SIZE (sizeof(EmbapiConfigJson)*2)

static StaticJsonDocument<JSON_DOC_SIZE> doc;
static char json[JSON_CHAR_SIZE];

char *EmbapiConfigJson::toJson()
{
    EmbapiMessageType id = (EmbapiMessageType)this->id;

    doc["id"] = id;

    switch (id)
    {
    case EMBAPI_CONFIG_ID_UNKNOWN:
        doc["error"] = EmbapiError::UNKNOWN_ID;
        break;
    case EMBAPI_CONFIG_ID_WIFI:
        doc["ssid"] = this->config.wifiConfig.getSSID();
        doc["password"] = this->config.wifiConfig.getPassword();
        break;
    case EMBAPI_CONFIG_ID_ETHERNET:
        doc["error"] = EmbapiError::NOT_IMPLEMENTED;
        break;
    case EMBAPI_CONFIG_ID_SERIAL:
        doc["error"] = EmbapiError::NOT_IMPLEMENTED;
        break;
    case EMBAPI_CONFIG_ID_BLUETOOTH:
        doc["error"] = EmbapiError::NOT_IMPLEMENTED;
        break;
    case EMBAPI_CONFIG_ID_NTP:
        doc["interval"] = this->config.ntp.getInterval();
        doc["server"] = this->config.ntp.getServer();
        break;
    case EMBAPI_CONFIG_ID_MQTT:
        doc["url"] = this->config.mqtt.getUrl();
        doc["port"] = this->config.mqtt.getPort();
        doc["user"] = this->config.mqtt.getUser();
        doc["password"] = this->config.mqtt.getPassword();
        break;
    }

    serializeJson(doc, json);
    return json;
}

EmbapiError EmbapiConfigJson::fromJson(char *json)
{
    deserializeJson(doc, json);

    EmbapiConfigId id = (EmbapiConfigId)doc["id"].as<uint8_t>();

    switch (id)
    {
    case EMBAPI_CONFIG_ID_UNKNOWN:
        return EmbapiError::UNKNOWN_ID;
    case EMBAPI_CONFIG_ID_WIFI:
        this->config.wifiConfig.setSSID(doc["ssid"]);
        this->config.wifiConfig.setPassword(doc["password"]);
        return EmbapiError::NO_ERROR;
    case EMBAPI_CONFIG_ID_ETHERNET:
        return EmbapiError::NOT_IMPLEMENTED;
    case EMBAPI_CONFIG_ID_SERIAL:
        return EmbapiError::NOT_IMPLEMENTED;
    case EMBAPI_CONFIG_ID_BLUETOOTH:
        return EmbapiError::NOT_IMPLEMENTED;
    case EMBAPI_CONFIG_ID_NTP:
        this->config.ntp.setInterval(doc["interval"]);
        this->config.ntp.setServer(doc["server"]);
        return EmbapiError::NO_ERROR;
    case EMBAPI_CONFIG_ID_MQTT:
        this->config.mqtt.setUrl(doc["url"]);
        this->config.mqtt.setPort(doc["port"]);
        this->config.mqtt.setUser(doc["user"]);
        this->config.mqtt.setPassword(doc["password"]);
        return EmbapiError::NO_ERROR;
    }

    return EmbapiError::NO_ERROR;
}
