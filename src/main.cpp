#include <Log.h>
#include "common.h"

void setup() {
  std::unique_ptr<SerialComponent> m_serial(new SerialComponent());
  Global::serial = std::move(m_serial);

  std::unique_ptr<Button1Component> m_button1(new Button1Component());
  Global::button1 = std::move(m_button1);

  std::unique_ptr<Button2Component> m_button2(new Button2Component());
  Global::button2 = std::move(m_button2);

  std::unique_ptr<Button3Component> m_button3(new Button3Component());
  Global::button3 = std::move(m_button3);

  std::unique_ptr<EPaperComponent> m_epaper(new EPaperComponent());
  Global::epaper = std::move(m_epaper);

  std::unique_ptr<LEDComponent> m_led(new LEDComponent());
  Global::led = std::move(m_led);
}

void loop() {
  Global::serial->loop();
  Global::button1->loop();
  Global::button2->loop();
  Global::button3->loop();
  Global::epaper->loop();
  Global::led->loop();
}