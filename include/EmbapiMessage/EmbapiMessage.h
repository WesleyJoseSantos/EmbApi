/**
 * @file EmbapiMessage.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-04-22
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef __EMBAPIMESSAGE__H__
#define __EMBAPIMESSAGE__H__

#include "EmbapiCore/EmbapiError.h"
#include "EmbapiMessage/EmbapiConfig.h"

/**
 * @brief Union for storing Embapi messages
 * 
 * This union is used to store different types of messages in the EmbapiMessage class.
 * 
 */
union EmbapiMessageData
{
    EmbapiConfig config;

    /**
     * @brief Constructor for EmbapiMessageData class
     * 
     */
    EmbapiMessageData(){}
    EmbapiMessageData(EmbapiConfig config){ this->config = config; }

    /**
     * @brief Destructor for EmbapiMessageData class
     * 
     */
    ~EmbapiMessageData(){}
};

/**
 * @enum EmbapiMessageType
 * @brief Enumerates the types of Embapi messages.
 */
enum EmbapiMessageType
{
    EMBAPI_MESSAGE_TYPE_UNKNOWN, ///< Unknown message type.
    EMBAPI_MESSAGE_TYPE_CONFIG,  ///< Configuration message type.
};

/**
 * @brief Base class for Embapi messages
 * 
 * This class provides the type and ID fields that are common to all Embapi messages.
 * 
 */
class EmbapiMessage
{
private:

protected:
    EmbapiMessageType type; /**< Message type */
    EmbapiError error; /**< Message error code*/
    EmbapiMessageData data; /**< Message data*/
public:

    /**
     * @brief Default constructor for EmbapiConfig class
     * 
     */
    EmbapiMessage(){}

    /**
     * @brief Constructor for EmbapiMessage class
     * 
     * @param type Message type
     * @param data Message data
     */
    EmbapiMessage(EmbapiMessageType type, EmbapiMessageData data)
    {
        this->type = type;
        this->data = data;
    }

    /**
     * @brief Get the message type
     * 
     * @return uint8_t Message type
     */
    uint8_t getType() { return type; }

    /**
     * @brief Get the message error code
     * 
     * @return uint8_t Error code
     */
    uint8_t getError() { return error; }

    /**
     * @brief Get the message data
     * 
     * @return EmbapiMessageData Message data
     */
    EmbapiMessageData getData() { return data; }
};

#endif  //!__EMBAPIMESSAGE__H__