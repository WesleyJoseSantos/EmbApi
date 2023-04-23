/**
 * @file NtpConfigJson.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-04-22
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef __NTPCONFIGJSON__H__
#define __NTPCONFIGJSON__H__

#include "NtpConfig.h"
#include "EmbapiJson.h"

class NtpConfigJson : public NtpConfig, public EmbapiJson
{
public:
    NtpConfigJson(const NtpConfig& config) : NtpConfig(config) {}
    NtpConfigJson(JsonDocument *doc){ fromJson(doc); }
    void toJson(JsonDocument *doc) override;
    void fromJson(JsonDocument *doc) override;
};

#endif  //!__NTPCONFIGJSON__H__