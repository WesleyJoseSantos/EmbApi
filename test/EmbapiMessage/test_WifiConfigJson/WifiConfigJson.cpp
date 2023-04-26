/**
 * @file WifiConfigJson.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-04-25
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "unity.h"
#include "EmbapiMessage\WifiConfigJson.h"

WifiConfig wifiConfig = WifiConfig(
    "my_wifi_ssid",
    "my_wifi_password"
);

const char *wifiJsonStr = "{ \
  \"ssid\": \"my_wifi_ssid\", \
  \"password\": \"my_wifi_password\" \
}";

WifiConfigJson wifi(wifiConfig);

void setUp(void) {
  // set stuff up here
}

void tearDown(void) {
  // clean stuff up here
}

void toJsonMustAddMembersToDocument(void)
{
  StaticJsonDocument<256> doc;
  wifi.toJson(&doc);
  TEST_ASSERT_EQUAL_STRING(wifiConfig.getSSID(), doc["ssid"]);
  TEST_ASSERT_EQUAL_STRING(wifiConfig.getPassword(), doc["password"]);
}

void fromJsonMustParseJsonToObject(void)
{
  StaticJsonDocument<256> doc;
  deserializeJson(doc, wifiJsonStr);
  wifi.fromJson(&doc);
  TEST_ASSERT_EQUAL_STRING(wifiConfig.getSSID(), doc["ssid"]);
  TEST_ASSERT_EQUAL_STRING(wifiConfig.getPassword(), doc["password"]);
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
