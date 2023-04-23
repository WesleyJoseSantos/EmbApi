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

#include "EmbapiConfig.h"
#include "EmbapiJson.h"

class EmbapiConfigJson : public EmbapiConfig, public EmbapiJson
{
private:

public:
    EmbapiConfigJson(const EmbapiConfig &config):EmbapiConfig(config){}
    EmbapiConfigJson(JsonDocument *doc) { this->fromJson(doc); }
    void toJson(JsonDocument *doc) override;
    void fromJson(JsonDocument *doc) override;
};

#endif  //!__EMBAPICONFIGJSON__H__