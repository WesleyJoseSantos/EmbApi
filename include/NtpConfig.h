/**
 * @file NtpConfig.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-04-20
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef __NTPCONFIG__H__
#define __NTPCONFIG__H__

#include <inttypes.h>
#include <string.h>

class NtpConfig
{
private:
    char server[64];
    uint32_t interval;
public:
    NtpConfig(){}

    NtpConfig(char server[64], uint32_t interval)
    {
        strncpy(this->server, server, sizeof(this->server));
        this->interval = interval;
    }

    char *getServer() { return server; }
    uint32_t getInterval() { return interval; }
    void setServer(const char server[64]) { strncpy(this->server, server, sizeof(this->server)); }
    void setInterval(uint32_t interval) { this->interval = interval; }
};

#endif  //!__NTPCONFIG__H__