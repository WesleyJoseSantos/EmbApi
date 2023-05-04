/**
 * @file EmbapiMessageJson.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-04-25
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "unity.h"
#include "EmbapiMessage/EmbapiMessageJson.h"

void setUp(void)
{
    // set stuff up here
}

void tearDown(void)
{
    // clean stuff up here
}

void toJsonUnknownType()
{
    EmbapiMessage message(EMBAPI_MESSAGE_TYPE_UNKNOWN, EmbapiMessageData());
    EmbapiMessageJson messageJson(message);
    StaticJsonDocument<256> doc;
    EmbapiError error = messageJson.toJson(&doc);
    TEST_ASSERT_EQUAL(EmbapiError::UNKNOWN_TYPE, error);
    TEST_ASSERT_EQUAL(doc["type"], EMBAPI_MESSAGE_TYPE_UNKNOWN);
}

void fromJsonUnknownType()
{
    const char *jsonStr = "{\"type\":0}";
    StaticJsonDocument<256> doc;
    deserializeJson(doc, jsonStr);
    EmbapiMessageJson messageJson(&doc);
    TEST_ASSERT_EQUAL(doc["type"], EMBAPI_MESSAGE_TYPE_UNKNOWN);
}

void toJsonWifi()
{
    WifiConfig wifiConfig("ssid", "pass");
    EmbapiMessageJson message = EmbapiMessageJson(
        EmbapiMessage(
            EMBAPI_MESSAGE_TYPE_CONFIG,
            EmbapiMessageData(
                EmbapiConfig(
                    EMBAPI_CONFIG_ID_WIFI,
                    wifiConfig))));
    StaticJsonDocument<256> doc;
    EmbapiError error = message.toJson(&doc);
    TEST_ASSERT_EQUAL(EmbapiError::NO_ERROR, error);
    TEST_ASSERT_EQUAL(EMBAPI_MESSAGE_TYPE_CONFIG, doc["type"]);
    TEST_ASSERT_EQUAL(EMBAPI_CONFIG_ID_WIFI, doc["id"]);
    TEST_ASSERT_EQUAL_STRING(wifiConfig.getSSID(), doc["ssid"]);
    TEST_ASSERT_EQUAL_STRING(wifiConfig.getPassword(), doc["password"]);
}

void fromJsonWifi()
{
    const char *jsonStr = "{\"type\":1,\"id\":1,\"ssid\":\"ssid\",\"password\":\"pass\"}";
    StaticJsonDocument<256> doc;
    deserializeJson(doc, jsonStr);
    EmbapiMessageJson message(&doc);
    TEST_ASSERT_EQUAL(EMBAPI_MESSAGE_TYPE_CONFIG, doc["type"]);
    TEST_ASSERT_EQUAL(EMBAPI_CONFIG_ID_WIFI, doc["id"]);
    TEST_ASSERT_EQUAL_STRING(message.getData().config.getData().wifi.getSSID(), doc["ssid"]);
    TEST_ASSERT_EQUAL_STRING(message.getData().config.getData().wifi.getPassword(), doc["password"]);
}

void toJsonNtp()
{
    NtpConfig ntpConfig("pool.ntp.org", 3600);
    EmbapiMessageJson message = EmbapiMessageJson(
        EmbapiMessage(
            EMBAPI_MESSAGE_TYPE_CONFIG,
            EmbapiMessageData(
                EmbapiConfig(
                    EMBAPI_CONFIG_ID_NTP,
                    ntpConfig))));
    StaticJsonDocument<256> doc;
    EmbapiError error = message.toJson(&doc);
    TEST_ASSERT_EQUAL(EmbapiError::NO_ERROR, error);
    TEST_ASSERT_EQUAL(EMBAPI_MESSAGE_TYPE_CONFIG, doc["type"]);
    TEST_ASSERT_EQUAL(EMBAPI_CONFIG_ID_NTP, doc["id"]);
    TEST_ASSERT_EQUAL_STRING(ntpConfig.getServer(), doc["server"]);
    TEST_ASSERT_EQUAL(ntpConfig.getInterval(), doc["interval"]);
}

void fromJsonNtp()
{
    const char *jsonStr = "{\"type\":1,\"id\":10,\"server\":\"pool.ntp.org\",\"interval\":3600}";
    StaticJsonDocument<256> doc;
    deserializeJson(doc, jsonStr);
    EmbapiMessageJson message(&doc);
    TEST_ASSERT_EQUAL(EMBAPI_MESSAGE_TYPE_CONFIG, doc["type"]);
    TEST_ASSERT_EQUAL(EMBAPI_CONFIG_ID_NTP, doc["id"]);
    TEST_ASSERT_EQUAL_STRING(message.getData().config.getData().ntp.getServer(), doc["server"]);
    TEST_ASSERT_EQUAL(message.getData().config.getData().ntp.getInterval(), doc["interval"]);
}

void toJsonMqtt()
{
    MqttConfig mqttConfig("mqtt://broker.com.br", 1883, "mqttuser", "mqttpass");
    EmbapiMessageJson message = EmbapiMessageJson(
        EmbapiMessage(
            EMBAPI_MESSAGE_TYPE_CONFIG,
            EmbapiMessageData(
                EmbapiConfig(
                    EMBAPI_CONFIG_ID_MQTT,
                    mqttConfig))));
    StaticJsonDocument<256> doc;
    EmbapiError error = message.toJson(&doc);
    TEST_ASSERT_EQUAL(EmbapiError::NO_ERROR, error);
    TEST_ASSERT_EQUAL(EMBAPI_MESSAGE_TYPE_CONFIG, doc["type"]);
    TEST_ASSERT_EQUAL(EMBAPI_CONFIG_ID_MQTT, doc["id"]);
    TEST_ASSERT_EQUAL_STRING(mqttConfig.getUrl(), doc["url"]);
    TEST_ASSERT_EQUAL(mqttConfig.getPort(), doc["port"]);
    TEST_ASSERT_EQUAL_STRING(mqttConfig.getUser(), doc["user"]);
    TEST_ASSERT_EQUAL_STRING(mqttConfig.getPassword(), doc["password"]);
}

void fromJsonMqtt()
{
    const char *jsonStr = "{\"type\":1,\"id\":11,\"url\":\"mqtt://broker.com.br\",\"port\":1883,\"user\":\"mqttuser\",\"password\":\"mqttpass\"}";
    StaticJsonDocument<256> doc;
    deserializeJson(doc, jsonStr);
    EmbapiMessageJson message(&doc);
    TEST_ASSERT_EQUAL(EMBAPI_MESSAGE_TYPE_CONFIG, doc["type"]);
    TEST_ASSERT_EQUAL(EMBAPI_CONFIG_ID_MQTT, doc["id"]);
    TEST_ASSERT_EQUAL_STRING(message.getData().config.getData().mqtt.getUrl(), doc["url"]);
    TEST_ASSERT_EQUAL(message.getData().config.getData().mqtt.getPort(), doc["port"]);
    TEST_ASSERT_EQUAL_STRING(message.getData().config.getData().mqtt.getUser(), doc["user"]);
    TEST_ASSERT_EQUAL_STRING(message.getData().config.getData().mqtt.getPassword(), doc["password"]);
}

int runUnityTest(void)
{
    UNITY_BEGIN();
    RUN_TEST(toJsonUnknownType);
    RUN_TEST(fromJsonUnknownType);
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
    return runUnityTest();
}