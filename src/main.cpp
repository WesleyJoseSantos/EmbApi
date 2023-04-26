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
#include "EmbapiMessage/EmbapiMessageJson.h"

EmbapiMessageJson msg;

void setup() {
  // put your setup code here, to run once:
  printf("Setup\n");
  const char* jsonStr = "{\"type\":1,\"id\":11,\"url\":\"mqtt://broker.com.br\",\"port\":1883,\"user\":\"mqtt username\",\"password\":\"mqtt password\"}";
  msg.fromString(jsonStr);
  printf("%s\n", msg.toString());
}

void loop() {
  // put your main code here, to run repeatedly:
  printf("Loop\n");
}

#if !defined(Arduino_h) && !defined(UNIT_TEST)
int main() {
  setup();
  // while (true) {
  //   loop();
  // }
  return 0;
}
#endif
