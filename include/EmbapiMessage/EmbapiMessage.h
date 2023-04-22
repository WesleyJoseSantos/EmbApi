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

#include <inttypes.h>

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
    uint8_t type; /**< Message type */
    uint8_t id; /**< Message ID */
public:

    /**
     * @brief Get the message type
     * 
     * @return uint8_t Message type
     */
    uint8_t getType() { return type; }

    /**
     * @brief Get the message ID
     * 
     * @return uint8_t Message ID
     */
    uint8_t getId() { return id; }
};

#endif  //!__EMBAPIMESSAGE__H__