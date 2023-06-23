#include "common.h"

SpiComponent::SpiComponent() {
  log_debug("SpiComponent::setup");
  SPI.begin(GENERATED::PIN::SPI::SCK, GENERATED::PIN::SPI::MISO,
            GENERATED::PIN::SPI::MOSI, -1);
  log_info("初始化SPI完成");
}

void SpiComponent::loop() {}