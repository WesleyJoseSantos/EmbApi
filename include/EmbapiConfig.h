/**
 * @file EmbapiConfig.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-04-20
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef __EMBAPICONFIG__H__
#define __EMBAPICONFIG__H__

#include <inttypes.h>
#include "MqttConfig.h"
#include "NtpConfig.h"
#include "WifiConfig.h"

enum EmbapiConfigType
{
    EMBAPI_CONFIG_TYPE_UNKNOWN,
    EMBAPI_CONFIG_TYPE_HARDWARE,
    EMBAPI_CONFIG_TYPE_SOFTWARE,
};

enum EmbapiConfigHardwareId
{
    EMBAPI_CONFIG_ID_HARDWARE_UNKNOWN,
    EMBAPI_CONFIG_ID_WIFI,
    EMBAPI_CONFIG_ID_ETHERNET,
    EMBAPI_CONFIG_ID_SERIAL,
    EMBAPI_CONFIG_ID_BLUETOOTH,
};

enum EmbapiConfigSoftwareId
{
    EMBAPI_CONFIG_ID_SOFTWARE_UNKNOWN,
    EMBAPI_CONFIG_ID_NTP=1,
    EMBAPI_CONFIG_ID_MQTT,
};

union EmbapiHardwareConfig
{
    WifiConfig wifiConfig;
};

union EmbapiSoftwareConfig
{
    MqttConfig mqtt;
    NtpConfig ntp;
};

union EmbapiConfigData
{
    EmbapiHardwareConfig hardware;
    EmbapiSoftwareConfig software;

    EmbapiConfigData(){}
    ~EmbapiConfigData(){}
};

class EmbapiConfig
{
protected:
    uint8_t type;
    uint8_t id;
    EmbapiConfigData config;
public:
    EmbapiConfig(){}

    EmbapiConfig(uint8_t type, uint8_t id, EmbapiConfigData config)
    {
        this->type = type;
        this->id = id;
        this->config = config;
    }

    uint8_t getType() { return type; }
    uint8_t getId() { return id; }
    EmbapiConfigData getData() { return this->config; }
};

#endif  //!__EMBAPICONFIG__H__