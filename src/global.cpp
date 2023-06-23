#include "global.h"

namespace Global {
std::unique_ptr<SerialComponent> serial;
std::unique_ptr<SpiComponent> spi;
std::unique_ptr<WiFiComponent> wifi;
std::unique_ptr<MqttComponent> mqtt;

std::unique_ptr<Button1Component> button1;
std::unique_ptr<Button2Component> button2;
std::unique_ptr<Button3Component> button3;

std::unique_ptr<EPaperComponent> epaper;
std::unique_ptr<LEDComponent> led;

};  // namespace Global