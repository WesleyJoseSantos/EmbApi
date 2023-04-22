/**
 * @file NtpConfigJson.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-04-22
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "EmbapiMessage/NtpConfigJson.h"

void NtpConfigJson::toJson(JsonDocument *doc)
{
    (*doc)["interval"] = this->getInterval();
    (*doc)["server"] = this->getServer();
}

void NtpConfigJson::fromJson(JsonDocument *doc)
{
    this->setInterval((*doc)["interval"]);
    this->setServer((*doc)["server"]);
}