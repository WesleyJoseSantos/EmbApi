/**
 * @file MqttConfigJson.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-04-22
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef __MQTTCONFIGJSON__H__
#define __MQTTCONFIGJSON__H__

#include "MqttConfig.h"
#include "EmbapiJson.h"

class MqttConfigJson : public MqttConfig, public EmbapiJson
{
public:
    MqttConfigJson(){}
    void toJson(JsonDocument *doc) override;
    void fromJson(JsonDocument *doc) override;
};

#endif  //!__MQTTCONFIGJSON__H__