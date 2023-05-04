/**
 * @file EmbapiConfig.h
 * @brief Header file for EmbapiConfig class and related enums and unions
 *
 * This file contains the declaration of the EmbapiConfig class and related enums and unions used for configuring
 * hardware and software settings in embedded systems.
 *
 * @version 0.1
 * @date 2023-04-20
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef __EMBAPICONFIG__H__
#define __EMBAPICONFIG__H__

#include <inttypes.h>
#include "MqttConfig.h"
#include "NtpConfig.h"
#include "WifiConfig.h"

/**
 * @brief Enum for different types of Embapi configurations
 *
 * This enum lists the different types of configurations that can be set using the EmbapiConfig class.
 * It includes unknown, WiFi, Ethernet, Serial, Bluetooth, NTP and MQTT types.
 *
 */
enum EmbapiConfigId
{
    // Hardware configurations
    EMBAPI_CONFIG_ID_UNKNOWN,   /**< Unknown hardware type */
    EMBAPI_CONFIG_ID_WIFI,      /**< WiFi hardware type */
    EMBAPI_CONFIG_ID_ETHERNET,  /**< Ethernet hardware type */
    EMBAPI_CONFIG_ID_SERIAL,    /**< Serial hardware type */
    EMBAPI_CONFIG_ID_BLUETOOTH, /**< Bluetooth hardware type */

    // Software configurations
    EMBAPI_CONFIG_ID_NTP = 10, /**< NTP software type */
    EMBAPI_CONFIG_ID_MQTT,     /**< MQTT software type */
};

/**
 * @brief Union for storing Embapi configurations
 *
 * This union is used to store different types of configurations in the EmbapiConfig class.
 * It includes both hardware and software configurations.
 *
 */
union EmbapiConfigData
{
    WifiConfig wifi; /**< WiFi configuration */
    MqttConfig mqtt; /**< MQTT configuration */
    NtpConfig ntp;   /**< NTP configuration */

    /**
     * @brief Constructor for EmbapiConfigData class
     *
     */
    EmbapiConfigData() {}
    EmbapiConfigData(WifiConfig wifi) { this->wifi = wifi; }
    EmbapiConfigData(MqttConfig mqtt) { this->mqtt = mqtt; }
    EmbapiConfigData(NtpConfig ntp) { this-> ntp = ntp; }

    /**
     * @brief Destructor for EmbapiConfigData class
     *
     */
    ~EmbapiConfigData() {}
};

/**
 * @brief Class for Embapi configuration messages
 *
 * This class provides a way to send and receive configuration data using the Embapi protocol.
 *
 */
class EmbapiConfig
{
protected:
    EmbapiConfigId id;       /**< Id that indentify configuration */
    EmbapiConfigData config; /**< Configuration data */
public:
    /**
     * @brief Default constructor for EmbapiConfig class
     *
     */
    EmbapiConfig() {}

    /**
     * @brief Constructor for EmbapiConfig class
     *
     * @param id Message ID
     * @param config Configuration data
     */
    EmbapiConfig(EmbapiConfigId id, EmbapiConfigData config)
    {
        this->id = id;
        this->config = config;
    }

    /**
     * @brief Get the configuration data
     *
     * @return EmbapiConfigData Configuration data
     */
    EmbapiConfigData getData() { return this->config; }
};

#endif //!__EMBAPICONFIG__H__