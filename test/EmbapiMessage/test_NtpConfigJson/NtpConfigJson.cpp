/**
 * @file NtpConfigJsonTests.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-04-25
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "unity.h"
#include "EmbapiMessage/NtpConfigJson.h"

NtpConfig ntpConfig = NtpConfig(
    "pool.ntp.org",
    3600
);

const char *ntpJsonStr = "{ \
  \"interval\": 3600, \
  \"server\": \"pool.ntp.org\" \
}";

NtpConfigJson ntp(ntpConfig);

void setUp(void) {
  // set stuff up here
}

void tearDown(void) {
  // clean stuff up here
}

void toJsonMustAddMembersToDocument(void)
{
  StaticJsonDocument<256> doc;
  ntp.toJson(&doc);
  TEST_ASSERT_EQUAL(ntpConfig.getInterval(), doc["interval"]);
  TEST_ASSERT_EQUAL_STRING(ntpConfig.getServer(), doc["server"]);
}

void fromJsonMustParseJsonToObject(void)
{
  StaticJsonDocument<256> doc;
  deserializeJson(doc, ntpJsonStr);
  ntp.fromJson(&doc);
  TEST_ASSERT_EQUAL(ntpConfig.getInterval(), doc["interval"]);
  TEST_ASSERT_EQUAL_STRING(ntpConfig.getServer(), doc["server"]);
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
