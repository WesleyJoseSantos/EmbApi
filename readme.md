EmbAPI v0.1.0
===

EmbAPI - A Standard API for IoT Firmware Development

> **Advise:** This is an work in progress. Don't use it on production environments.

EmbAPI is an open-source library for developing firmware  in the IoT space. It is compatible with arduino, and Linux/Windows and is designed to simplify and accelerate the development of IoT projects by providing a standard API accessible via HTTP client or MQTT client for configuring devices.

One of the main advantages of EmbAPI is its compatibility with Linux/Windows, which allows to develop and test a large part of the firmware on a PC before deploying it on the bare metal. This feature greatly simplifies debugging, as debugging code directly on the hardware can be quite challenging.

The main differentiator of EmbAPI is its implementation of a standard API that can be accessed via different protocols, making it easier for developers to integrate their devices with another frameworks and languages such as Flutter, JavaScript/TypeScript, Rust, and more. The library is designed to be modular and extensible, allowing it to support additional protocols such as Modbus, OPC UA, CAN Bus, and others in the future.

The main software API is implemented as a separate layer that can be accessed by the device's HTTP server, MQTT client, or any other protocol that is implemented in the future. It is designed to be flexible and capable of integrating different IoT devices with industrial automation technologies, making it a valuable tool for developers in both the IoT and industrial automation industries. The main software API can be easily extended to include your own specific device messages to send custom configurations and requests. 

The library is initially developed on the Arduino platform, but it is designed to be portable to other platforms as well. It is fully open-source, allowing developers to use, modify, and contribute to the codebase as they see fit.

In summary, EmbAPI is a powerful and flexible library for IoT firmware development that provides a standard API accessible via different protocols, making it easier for developers to integrate their devices into different systems. Its modularity, extensibility, and compatibility with Linux/Windows make it a valuable tool for developing and debugging IoT projects. The library's ability to integrate with industrial automation technologies further expands its use cases.

## Roadmap:

EmbapiMessage v0.1.0: Library to handle EmbAPI messages on Arduino/Linux/Windows

 - [X] Implement WifiConfigJson
 - [X] Implement NtpConfigJson
 - [X] Implement MqttConfigJson
 - [X] Implement EmbapiConfigJson
 - [X] Implement EmbapiMessageJson
 - [X] Compile source code in arduino (ESP8266/ESP32)
 - [X] Compile source code on linux
 - [X] Compile source code on windows
 - [X] Implement UNIT Tests

EmbapiCore v0.1.0: Library to handle EmbAPI IoT protocols on Arduino/Linux/Windows

 - [ ] Implement MqttClientWrapper
 - [ ] Implement NtpClientWrapper
 - [ ] Implement HttpServerWrapper
 - [ ] Implement Embapi
 - [ ] Compile source code in arduino (ESP8266/ESP32)
 - [ ] Compile source code on linux
 - [ ] Compile source code on windows
 - [ ] Implement UNIT Tests

EmbapiFlutterSDK v0.1.0: Library to integrate EmbAPI devices to flutter applications
 - [ ] Implement EmbapiFlutterSDK
 - [ ] Implement UNIT Tests

EmbapiFlutterApp v0.1.0: Application example using EmbapiFlutterSDK
 - [ ] Implement EmbapiApp
 - [ ] Implement UNIT Tests

EmbapiJS v0.1.0: Library to integrate EmbAPI devices to javascript applications
 - [ ] Implement EmbapiJS
 - [ ] Implement UNIT Tests

EmbapiJSApp v0.1.0: Application example using EmbapiJS
 - [ ] Implement EmbAPI Web APP (html/css)

embapi_idf v0.1.0: Implement embapi on espressif-idf
 - [ ] Implement embapi_message
 - [ ] Implement embapi_core
 - [ ] Implement embapi

EmbapiTA v0.1.0: EmbAPI TA initial stack for Arduino/Linux/Windows

- [ ] Implement ModbusWrapper for arduino/linux
- [ ] Implement UNIT Tests

EmbapiNet v0.1.0: Library to integrate EmbAPI devices to .NET framework applications

- [ ] Implement EmbapiNET
- [ ] Implement UNIT Tests

EmbapiSCADA v0.1.0: SCADA example using .NET framework

- [ ] Implement EmbapiSCADA Modbus Sample
