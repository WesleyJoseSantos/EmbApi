EmbAPI v0.1.0
===

EmbAPI - A Standard API for IoT Firmware Development

> **Advise:** This is an work in progress. Don't use it on production environments.

EmbAPI is an open-source library for developing firmware for embedded devices in the IoT space. It is compatible with ESP32, ESP8266, and Linux and is designed to simplify and accelerate the development of IoT projects by providing a standard API accessible via HTTP client or MQTT client for configuring devices.

One of the main advantages of EmbAPI is its compatibility with Linux, which allows developers to develop and test a large part of the firmware on a PC before deploying it on the bare metal. This feature greatly simplifies debugging, as debugging code directly on the hardware can be quite challenging.

The main differentiator of EmbAPI is its implementation of a standard API that can be accessed via different protocols, making it easier for developers to integrate their devices into different frameworks and languages such as Flutter, JavaScript/TypeScript, Rust, and more. The library is designed to be modular and extensible, allowing it to support additional protocols such as Modbus, OPC UA, CAN Bus, and others in the future.

The main software API is implemented as a separate layer that can be accessed by the device's HTTP server, MQTT client, or any other protocol that is implemented in the future. It is designed to be flexible and capable of integrating different IoT devices with industrial automation technologies, making it a valuable tool for developers in both the IoT and industrial automation industries. The main software API can be easily extended to include your own specific device messages to send custom configurations and requests. 

The library is initially developed on the Arduino platform, but it is designed to be portable to other platforms as well. It is fully open-source, allowing developers to use, modify, and contribute to the codebase as they see fit.

In summary, EmbAPI is a powerful and flexible library for IoT firmware development that provides a standard API accessible via different protocols, making it easier for developers to integrate their devices into different systems. Its modularity, extensibility, and compatibility with Linux make it a valuable tool for developing and debugging IoT projects. The library's ability to integrate with industrial automation technologies further expands its use cases.

 TO-DO List (EmbapiMessage):

 - [X] Implement WifiConfigJson
 - [X] Implement NtpConfigJson
 - [X] Implement MqttConfigJson
 - [ ] Implement EmbapiConfigJson
 - [ ] Implement EmbapiMessageJson
 - [ ] Document header files
 - [ ] Compile source code to ESP8266
 - [ ] Compile source code to ESP32
 - [ ] Compile source code on Linux
 - [ ] Implement UNIT Tests

 TO-DO List (EmbapiCore):

 - [ ] Implement HttpServerWrapper for arduino/linux
 - [ ] Implement NtpClientWrapper for arduino/linux
 - [ ] Implement MqttClientWrapper for arduino/linux
 - [ ] Implement EmbapiHttpServer for arduino/linux
 - [ ] Document header files