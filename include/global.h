#pragma once

#include <memory>
#include "button.h"
#include "epaper.h"
#include "led.h"
#include "serial.h"
#include "spi.h"
#include "wifi.h"

namespace Global {
extern std::unique_ptr<SerialComponent> serial;
extern std::unique_ptr<SpiComponent> spi;
extern std::unique_ptr<WiFiComponent> wifi;

extern std::unique_ptr<Button1Component> button1;
extern std::unique_ptr<Button2Component> button2;
extern std::unique_ptr<Button3Component> button3;

extern std::unique_ptr<EPaperComponent> epaper;
extern std::unique_ptr<LEDComponent> led;
};  // namespace Global