/**
 * @file EmbapiConfigJson.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-04-21
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef __EMBAPICONFIGJSON__H__
#define __EMBAPICONFIGJSON__H__

#include "EmbapiError.h"
#include "EmbapiConfig.h"

class EmbapiConfigJson : public EmbapiConfig
{
private:

public:
    EmbapiConfigJson(){}
    char *toJson();
    EmbapiError fromJson(char *json);
};

#endif  //!__EMBAPICONFIGJSON__H__