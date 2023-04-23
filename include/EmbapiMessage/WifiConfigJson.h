/**
 * @file WifiConfigJson.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-04-22
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef __WIFICONFIGJSON__H__
#define __WIFICONFIGJSON__H__

#include "WifiConfig.h"
#include "EmbapiJson.h"

class WifiConfigJson : public WifiConfig, public EmbapiJson
{
public:
    WifiConfigJson(const WifiConfig& config) : WifiConfig(config) {}
    WifiConfigJson(JsonDocument *doc){ fromJson(doc); }
    void toJson(JsonDocument *doc) override;
    void fromJson(JsonDocument *doc) override;
};

#endif  //!__WIFICONFIGJSON__H__