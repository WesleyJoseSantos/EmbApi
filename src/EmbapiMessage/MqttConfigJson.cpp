/**
 * @file MqttConfigJson.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-04-22
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "EmbapiMessage/MqttConfigJson.h"

void MqttConfigJson::toJson(JsonDocument *doc)
{
    (*doc)["url"] = this->getUrl();
    (*doc)["port"] = this->getPort();
    (*doc)["user"] = this->getUser();
    (*doc)["password"] = this->getPassword();
}

void MqttConfigJson::fromJson(JsonDocument *doc)
{
    this->setUrl((*doc)["url"]);
    this->setPort((*doc)["port"]);
    this->setUser((*doc)["user"]);
    this->setPassword((*doc)["password"]);
}