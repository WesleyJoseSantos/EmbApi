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

#include "EmbapiConfigJson.h"
#include "ArduinoJson.h"

#define JSON_DOC_SIZE (sizeof(EmbapiConfigJson)*2)
#define JSON_CHAR_SIZE (sizeof(EmbapiConfigJson)*2)

static StaticJsonDocument<JSON_DOC_SIZE> doc;
static char json[JSON_CHAR_SIZE];

char *EmbapiConfigJson::toJson()
{
    EmbapiConfigType type = (EmbapiConfigType)this->type;

    doc["id"] = this->id;
    doc["type"] = this->type;

    switch (type)
    {
    case EMBAPI_CONFIG_TYPE_UNKNOWN:
        doc["error"] = EmbapiError::UNKNOWN_TYPE;
        break;
    case EMBAPI_CONFIG_TYPE_HARDWARE:
        hardwareToJson();
        break;
    case EMBAPI_CONFIG_TYPE_SOFTWARE:
        softwareToJson();
        break;
    }

    serializeJson(doc, json);
    return json;
}

EmbapiError EmbapiConfigJson::fromJson(char *json)
{
    deserializeJson(doc, json);
    EmbapiConfigType type = doc["type"];

    switch (type)
    {
    case EMBAPI_CONFIG_TYPE_UNKNOWN:
        return EmbapiError::UNKNOWN_TYPE;
    case EMBAPI_CONFIG_TYPE_HARDWARE:
        return hardwareFromJson();
    case EMBAPI_CONFIG_TYPE_SOFTWARE:
        return softwareFromJson();
    }

    return EmbapiError::NO_ERROR;
}

void EmbapiConfigJson::hardwareToJson()
{
    EmbapiConfigHardwareId id = (EmbapiConfigHardwareId)this->id;

    switch (id)
    {
    case EMBAPI_CONFIG_ID_HARDWARE_UNKNOWN:
        doc["error"] = EmbapiError::UNKNOWN_ID;
        break;
    case EMBAPI_CONFIG_ID_WIFI:
        doc["ssid"] = this->config.hardware.wifiConfig.getSSID();
        doc["password"] = this->config.hardware.wifiConfig.getPassword();
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
    }
}

void EmbapiConfigJson::softwareToJson()
{
    EmbapiConfigSoftwareId id = (EmbapiConfigSoftwareId)this->id;

    switch (id)
    {
    case EMBAPI_CONFIG_ID_SOFTWARE_UNKNOWN:
        doc["error"] = EmbapiError::UNKNOWN_ID;
        break;
    case EMBAPI_CONFIG_ID_NTP:
        doc["interval"] = this->config.software.ntp.getInterval();
        doc["server"] = this->config.software.ntp.getServer();
        break;
    case EMBAPI_CONFIG_ID_MQTT:
        doc["url"] = this->config.software.mqtt.getUrl();
        doc["port"] = this->config.software.mqtt.getPort();
        doc["user"] = this->config.software.mqtt.getUser();
        doc["password"] = this->config.software.mqtt.getPassword();
        break;
    }
}

EmbapiError EmbapiConfigJson::hardwareFromJson()
{
    EmbapiConfigHardwareId id = (EmbapiConfigHardwareId)doc["id"].as<uint8_t>();

    switch (id)
    {
    case EMBAPI_CONFIG_ID_HARDWARE_UNKNOWN:
        return EmbapiError::UNKNOWN_ID;
    case EMBAPI_CONFIG_ID_WIFI:
        this->config.hardware.wifiConfig.setSSID(doc["ssid"]);
        this->config.hardware.wifiConfig.setPassword(doc["password"]);
        return EmbapiError::NO_ERROR;
    case EMBAPI_CONFIG_ID_ETHERNET:
        return EmbapiError::NOT_IMPLEMENTED;
    case EMBAPI_CONFIG_ID_SERIAL:
        return EmbapiError::NOT_IMPLEMENTED;
    case EMBAPI_CONFIG_ID_BLUETOOTH:
        return EmbapiError::NOT_IMPLEMENTED;
    }

    return EmbapiError::NO_ERROR;
}

EmbapiError EmbapiConfigJson::softwareFromJson()
{
    EmbapiConfigSoftwareId id = (EmbapiConfigSoftwareId)doc["id"].as<uint8_t>();

    switch (id)
    {
    case EMBAPI_CONFIG_ID_SOFTWARE_UNKNOWN:
        return EmbapiError::UNKNOWN_ID;
    case EMBAPI_CONFIG_ID_NTP:
        this->config.software.ntp.setInterval(doc["interval"]);
        this->config.software.ntp.setServer(doc["server"]);
        return EmbapiError::NO_ERROR;
    case EMBAPI_CONFIG_ID_MQTT:
        this->config.software.mqtt.setUrl(doc["url"]);
        this->config.software.mqtt.setPort(doc["port"]);
        this->config.software.mqtt.setUser(doc["user"]);
        this->config.software.mqtt.setPassword(doc["password"]);
        return EmbapiError::NO_ERROR;
    }

    return EmbapiError::NO_ERROR;
}
