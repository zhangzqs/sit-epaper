#include "generated.h"

namespace GENERATED {
namespace WIFI {
const char* SSID = "PDCN";
const char* PASSWORD = "18521077169";
}  // namespace WIFI
namespace MQTT {
const char* HOST = "broker.emqx.io";
const int PORT = 1883;
const char* NAMESPACE = "esp32-epaper/";
const char* CLIENT_ID = "MY_ESP32_EPAPER";
const char* USERNAME = "admin";
const char* PASSWORD = "public";
}  // namespace MQTT
namespace DEBUG {
const int DEBUG_SERIAL_BAUD = 115200;
}
namespace PIN {
namespace SPI {
const int SCK = 18;
const int MISO = 23;
const int MOSI = 19;
}  // namespace SPI
namespace EPD {
const int DC = 17;
const int RST = 16;
const int BUSY = 4;
const int CS = 5;
}  // namespace EPD
namespace BUTTON {
const int BUTTON_1 = 0;
const int BUTTON_2 = 33;
const int BUTTON_3 = 32;
}  // namespace BUTTON
namespace SD {
const int DET = 15;
const int CS = 13;
}  // namespace SD
namespace LED {
const int LED_1 = 22;
}
}  // namespace PIN
}  // namespace GENERATED
