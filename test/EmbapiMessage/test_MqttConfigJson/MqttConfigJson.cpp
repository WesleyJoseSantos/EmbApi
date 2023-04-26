/**
 * @file MqttConfigJsonTests.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-04-23
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "unity.h"
#include "EmbapiMessage/MqttConfigJson.h"

MqttConfig mqttConfig = MqttConfig(
    "mqtt://broker.com.br",
    1883,
    "mqttuser",
    "mqttpass"
);

const char *mqttJsonStr = "{ \
  \"url\": \"mqtt://broker.com.br\", \
  \"port\": 1883, \
  \"user\": \"mqttuser\", \
  \"password\": \"mqttpass\" \
}";

MqttConfigJson mqtt(mqttConfig);

void setUp(void) {
  // set stuff up here
}

void tearDown(void) {
  // clean stuff up here
}

void toJsonMustAddMembersToDocument(void)
{
  StaticJsonDocument<256> doc;
  mqtt.toJson(&doc);
  TEST_ASSERT_EQUAL_STRING(mqtt.getUrl(), doc["url"]);
  TEST_ASSERT_EQUAL(mqtt.getPort(), doc["port"]);
  TEST_ASSERT_EQUAL_STRING(mqtt.getUser(), doc["user"]);
  TEST_ASSERT_EQUAL_STRING(mqtt.getPassword(), doc["password"]);
}

void fromJsonMustParseJsonToObject(void)
{
  StaticJsonDocument<256> doc;
  deserializeJson(doc, mqttJsonStr);
  mqtt.fromJson(&doc);
  TEST_ASSERT_EQUAL_STRING(mqtt.getUrl(), doc["url"]);
  TEST_ASSERT_EQUAL(mqtt.getPort(), doc["port"]);
  TEST_ASSERT_EQUAL_STRING(mqtt.getUser(), doc["user"]);
  TEST_ASSERT_EQUAL_STRING(mqtt.getPassword(), doc["password"]);
}

int runUnityTests(void) {
  UNITY_BEGIN();

  RUN_TEST(toJsonMustAddMembersToDocument);
  RUN_TEST(fromJsonMustParseJsonToObject);

  return UNITY_END();
}

int main(void) {
  return runUnityTests();
}
