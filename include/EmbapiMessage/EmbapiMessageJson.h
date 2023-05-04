/**
 * @file EmbapiMessageJson.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-04-22
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "EmbapiMessage.h"
#include "EmbapiJson.h"

class EmbapiMessageJson : public EmbapiMessage, public EmbapiJson
{
private:
    
public:
    EmbapiMessageJson(){}
    EmbapiMessageJson(const EmbapiMessage &message):EmbapiMessage(message){}
    EmbapiMessageJson(JsonDocument *doc) { this->fromJson(doc); }
    EmbapiError toJson(JsonDocument *doc) override;
    EmbapiError fromJson(JsonDocument *doc) override;
};