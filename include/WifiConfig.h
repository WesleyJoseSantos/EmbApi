/**
 * @file WifiConfig.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-04-20
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef __WIFICONFIG__H__
#define __WIFICONFIG__H__

#include <string.h>

class WifiConfig
{
private:
    char ssid[32];
    char password[32];
public:
    WifiConfig(){}

    WifiConfig(char ssid[32], char password[32])
    {
        strncpy(this->ssid, ssid, sizeof(this->ssid));
        strncpy(this->password, password, sizeof(this->ssid));
    }
    
    char *getSSID() { return ssid; }
    char *getPassword() { return password; }
    void setSSID(const char ssid[32]) { strncpy(this->ssid, ssid, sizeof(this->ssid)); }
    void setPassword(const char password[32]) { strncpy(this->password, password, sizeof(this->password)); }
};

#endif  //!__WIFICONFIG__H__