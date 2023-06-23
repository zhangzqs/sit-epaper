#include "common.h"

LEDComponent::LEDComponent() : pin(GENERATED::PIN::LED::LED_1) {
  log_debug("LED::setup");

  pinMode(pin, OUTPUT);
  off();
}
void LEDComponent::on() {
  digitalWrite(pin, HIGH);
}
void LEDComponent::off() {
  digitalWrite(pin, LOW);
}
void LEDComponent::toggle() {
  digitalWrite(pin, !digitalRead(pin));
}

void LEDComponent::loop() {}