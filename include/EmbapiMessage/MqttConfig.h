/**
 * @file MqttConfig.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-04-20
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef __MQTTCONFIG__H__
#define __MQTTCONFIG__H__

#include <inttypes.h>
#include <string.h>

class MqttConfig
{
private:
    char url[64];
    uint32_t port;
    char user[48];
    char password[48];
public:
    MqttConfig(){}

    MqttConfig(const char url[64], uint32_t port, const char user[48], const char password[48])
    {
        strncpy(this->url, url, sizeof(this->url));
        this->port = port;
        strncpy(this->password, password, sizeof(this->password));
        strncpy(this->user, user, sizeof(this->user));
    }

    char *getUrl() { return url; }
    uint32_t getPort() { return port; }
    char *getUser() { return user; }
    char *getPassword() { return password; }

    void setUrl(const char url[64]) { strncpy(this->url, url, sizeof(this->url)); }
    void setPort(uint32_t port) { this->port = port; }
    void setPassword(const char password[48]) { strncpy(this->password, password, sizeof(this->password)); }
    void setUser(const char user[48]){ strncpy(this->user, user, sizeof(this->user)); }
};

#endif  //!__MQTTCONFIG__H__