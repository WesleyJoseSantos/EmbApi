/**
 * @file EmbapiConfigJson.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-04-25
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "unity.h"
#include "EmbapiMessage/EmbapiConfigJson.h"

void setUp(void)
{
    // set stuff up here
}

void tearDown(void)
{
    // clean stuff up here
}

void toJsonUnknownId()
{
    EmbapiConfig config(EMBAPI_CONFIG_ID_UNKNOWN, EmbapiConfigData());
    EmbapiConfigJson embapiConfigJson(config);
    StaticJsonDocument<256> doc;
    EmbapiError error = embapiConfigJson.toJson(&doc);
    TEST_ASSERT_EQUAL(EmbapiError::UNKNOWN_ID, error);
    TEST_ASSERT_EQUAL(doc["id"], EMBAPI_CONFIG_ID_UNKNOWN);
}

void fromJsonUnknownId()
{
    const char *jsonStr = "{\"id\":0}";
    StaticJsonDocument<256> doc;
    deserializeJson(doc, jsonStr);
    EmbapiConfigJson embapiConfigJson(&doc);
    TEST_ASSERT_EQUAL(doc["id"], EMBAPI_CONFIG_ID_UNKNOWN);
}

void toJsonWifi()
{
    WifiConfig wifiConfig("ssid", "pass");
    EmbapiConfigData configData;
    configData.wifi = wifiConfig;
    EmbapiConfig config(EMBAPI_CONFIG_ID_WIFI, configData);
    EmbapiConfigJson embapiConfigJson(config);
    StaticJsonDocument<256> doc;
    EmbapiError error = embapiConfigJson.toJson(&doc);
    TEST_ASSERT_EQUAL(EmbapiError::NO_ERROR, error);
    TEST_ASSERT_EQUAL(EMBAPI_CONFIG_ID_WIFI, doc["id"]);
    TEST_ASSERT_EQUAL_STRING(wifiConfig.getSSID(), doc["ssid"]);
    TEST_ASSERT_EQUAL_STRING(wifiConfig.getPassword(), doc["password"]);
}

void fromJsonWifi()
{
    const char *jsonStr = "{\"id\":1,\"ssid\":\"ssid\",\"password\":\"pass\"}";
    StaticJsonDocument<256> doc;
    deserializeJson(doc, jsonStr);
    EmbapiConfigJson embapi(&doc);
    TEST_ASSERT_EQUAL(EMBAPI_CONFIG_ID_WIFI, doc["id"]);
    TEST_ASSERT_EQUAL_STRING(embapi.getData().wifi.getSSID(), doc["ssid"]);
    TEST_ASSERT_EQUAL_STRING(embapi.getData().wifi.getPassword(), doc["password"]);
}

void toJsonNtp()
{
    NtpConfig ntpConfig("pool.ntp.org", 3600);
    EmbapiConfigData configData;
    configData.ntp = ntpConfig;
    EmbapiConfig config(EMBAPI_CONFIG_ID_NTP, configData);
    EmbapiConfigJson embapiConfigJson(config);
    StaticJsonDocument<256> doc;
    EmbapiError error = embapiConfigJson.toJson(&doc);
    TEST_ASSERT_EQUAL(EmbapiError::NO_ERROR, error);
    TEST_ASSERT_EQUAL(EMBAPI_CONFIG_ID_NTP, doc["id"]);
    TEST_ASSERT_EQUAL_STRING(ntpConfig.getServer(), doc["server"]);
    TEST_ASSERT_EQUAL(ntpConfig.getInterval(), doc["interval"]);
}

void fromJsonNtp()
{
    const char *jsonStr = "{\"id\":10,\"server\":\"pool.ntp.org\",\"interval\":3600}";
    StaticJsonDocument<256> doc;
    deserializeJson(doc, jsonStr);
    EmbapiConfigJson embapi(&doc);
    TEST_ASSERT_EQUAL(EMBAPI_CONFIG_ID_NTP, doc["id"]);
    TEST_ASSERT_EQUAL_STRING(embapi.getData().ntp.getServer(), doc["server"]);
    TEST_ASSERT_EQUAL(embapi.getData().ntp.getInterval(), doc["interval"]);
}

void toJsonMqtt()
{
    MqttConfig mqttConfig("mqtt://broker.com.br", 1883, "mqttuser", "mqttpass");
    EmbapiConfigData configData;
    configData.mqtt = mqttConfig;
    EmbapiConfig config(EMBAPI_CONFIG_ID_MQTT, configData);
    EmbapiConfigJson embapiConfigJson(config);
    StaticJsonDocument<256> doc;
    EmbapiError error = embapiConfigJson.toJson(&doc);
    TEST_ASSERT_EQUAL(EmbapiError::NO_ERROR, error);
    TEST_ASSERT_EQUAL(EMBAPI_CONFIG_ID_MQTT, doc["id"]);
    TEST_ASSERT_EQUAL_STRING(mqttConfig.getUrl(), doc["url"]);
    TEST_ASSERT_EQUAL(mqttConfig.getPort(), doc["port"]);
    TEST_ASSERT_EQUAL_STRING(mqttConfig.getUser(), doc["user"]);
    TEST_ASSERT_EQUAL_STRING(mqttConfig.getPassword(), doc["password"]);
}

void fromJsonMqtt()
{
    const char *jsonStr = "{\"id\":11,\"url\":\"mqtt://broker.com.br\",\"port\":1883,\"user\":\"mqttuser\",\"password\":\"mqttpass\"}";
    StaticJsonDocument<256> doc;
    deserializeJson(doc, jsonStr);
    EmbapiConfigJson embapi(&doc);
    TEST_ASSERT_EQUAL(EMBAPI_CONFIG_ID_MQTT, doc["id"]);
    TEST_ASSERT_EQUAL_STRING(embapi.getData().mqtt.getUrl(), doc["url"]);
    TEST_ASSERT_EQUAL(embapi.getData().mqtt.getPort(), doc["port"]);
    TEST_ASSERT_EQUAL_STRING(embapi.getData().mqtt.getUser(), doc["user"]);
    TEST_ASSERT_EQUAL_STRING(embapi.getData().mqtt.getPassword(), doc["password"]);
}

int runUnityTests(void)
{
    UNITY_BEGIN();
    RUN_TEST(toJsonUnknownId);
    RUN_TEST(fromJsonUnknownId);
    RUN_TEST(toJsonWifi);
    RUN_TEST(fromJsonWifi);
    RUN_TEST(toJsonNtp);
    RUN_TEST(fromJsonNtp);
    RUN_TEST(toJsonMqtt);
    RUN_TEST(fromJsonMqtt);
    return UNITY_END();
}

int main(void)
{
    return runUnityTests();
}
