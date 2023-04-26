/**
 * @file EmbapiJson.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-04-22
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef __EMBAPIJSON__H__
#define __EMBAPIJSON__H__

#include "EmbapiCore/EmbapiError.h"
#include <ArduinoJson.h>

class EmbapiJson
{
private:
    
public:
    EmbapiJson() {}
    virtual EmbapiError toJson(JsonDocument *doc) = 0;
    virtual EmbapiError fromJson(JsonDocument *doc) = 0;
    char *toString();
    void fromString(const char *str);
};

#endif  //!__EMBAPIJSON__H__