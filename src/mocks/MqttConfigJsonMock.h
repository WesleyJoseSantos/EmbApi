/**
 * @file MqttConfigJsonMock.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-04-23
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef __MQTTCONFIGJSONMOCK__H__
#define __MQTTCONFIGJSONMOCK__H__

#include "EmbapiMessage/MqttConfigJson.h"

MqttConfig mqttConfig = MqttConfig(
    "mqtt://broker.com.br",
    1883,
    "mqttuser",
    "mqttpass"
);

MqttConfigJson mqtt(mqttConfig);

#endif  //!__MQTTCONFIGJSONMOCK__H__