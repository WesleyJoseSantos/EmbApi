/**
 * @file WifiConfigJson.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-04-22
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "EmbapiMessage/WifiConfigJson.h"

EmbapiError WifiConfigJson::toJson(JsonDocument *doc)
{
    (*doc)["ssid"] = this->getSSID();
    (*doc)["password"] = this->getPassword();
    return EmbapiError::NO_ERROR;
}

EmbapiError WifiConfigJson::fromJson(JsonDocument *doc)
{
    this->setSSID((*doc)["ssid"]);
    this->setPassword((*doc)["password"]);
    return EmbapiError::NO_ERROR;
}
