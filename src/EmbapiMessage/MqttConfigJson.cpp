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

EmbapiError MqttConfigJson::toJson(JsonDocument *doc)
{
    (*doc)["url"] = this->getUrl();
    (*doc)["port"] = this->getPort();
    (*doc)["user"] = this->getUser();
    (*doc)["password"] = this->getPassword();
    return EmbapiError::NO_ERROR;
}

EmbapiError MqttConfigJson::fromJson(JsonDocument *doc)
{
    this->setUrl((*doc)["url"]);
    this->setPort((*doc)["port"]);
    this->setUser((*doc)["user"]);
    this->setPassword((*doc)["password"]);
    return EmbapiError::NO_ERROR;
}