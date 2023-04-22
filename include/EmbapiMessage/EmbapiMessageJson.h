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

#include "EmbapiError.h"

class EmbapiMessageJson
{
private:
    
public:
    EmbapiMessageJson() {}
    char *toJson();
    EmbapiError fromJson(char *json);
};