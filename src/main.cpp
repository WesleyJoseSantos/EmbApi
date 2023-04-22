/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-04-21
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#if defined(ESP32) || defined(ESP8266)
#include <Arduino.h>
#else
#include <stdio.h>
#endif
#include "EmbapiMessage/MqttConfigJson.h"

MqttConfigJson mqtt = MqttConfigJson();

void setup() {
  // put your setup code here, to run once:
  printf("Setup\n");
  const char* jsonStr = "{\"url\":\"mqtt://broker.com.br\",\"port\":1883,\"user\":\"mqtt username\",\"password\":\"mqtt password\"}";
  mqtt.fromString(jsonStr);
  printf("%s\n", mqtt.toString());
}

void loop() {
  // put your main code here, to run repeatedly:
  printf("Loop\n");
}

#ifndef Arduino_h
int main() {
  setup();
  // while (true) {
  //   loop();
  // }
  return 0;
}
#endif
