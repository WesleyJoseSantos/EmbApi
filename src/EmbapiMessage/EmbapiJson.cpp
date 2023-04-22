/**
 * @file EmbapiJson.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-04-22
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "EmbapiMessage/EmbapiJson.h"

char *EmbapiJson::toString() {
    StaticJsonDocument<386> doc;
    static char str[256];
    toJson(&doc);
    serializeJsonPretty(doc, str);
    return str;
}

void EmbapiJson::fromString(const char *str)
{
    StaticJsonDocument<386> doc;
    deserializeJson(doc, str);
    fromJson(&doc);
}
