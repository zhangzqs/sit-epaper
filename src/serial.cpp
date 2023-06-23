#include "common.h"

SerialComponent::SerialComponent() {
  log_debug("SerialComponent::setup");
  Serial.begin(GENERATED::DEBUG::DEBUG_SERIAL_BAUD);
  setLogPrintTarget(std::shared_ptr<Print>(&Serial));
  log_info("初始化串口完成");
}
void SerialComponent::loop() {}