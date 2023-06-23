#pragma once

namespace GENERATED {
namespace WIFI {
extern const char* SSID;
extern const char* PASSWORD;
}  // namespace WIFI
namespace MQTT {
extern const char* HOST;
extern const int PORT;
extern const char* CLIENT_ID;
extern const char* NAMESPACE;
extern const char* USERNAME;
extern const char* PASSWORD;
}  // namespace MQTT
namespace DEBUG {
extern const int DEBUG_SERIAL_BAUD;
}
namespace PIN {
namespace SPI {
extern const int SCK;
extern const int MISO;
extern const int MOSI;
}  // namespace SPI
namespace EPD {
extern const int DC;
extern const int RST;
extern const int BUSY;
extern const int CS;
}  // namespace EPD
namespace BUTTON {
extern const int BUTTON_1;
extern const int BUTTON_2;
extern const int BUTTON_3;
}  // namespace BUTTON
namespace SD {
extern const int DET;
extern const int CS;
}  // namespace SD
namespace LED {
extern const int LED_1;
}
}  // namespace PIN
}  // namespace GENERATED
