#include "common.h"

EPaperComponent::EPaperComponent() {
  log_debug("EPaperComponent::setup");
  std::unique_ptr<EPaper> m_p(
      new EPaper(GENERATED::PIN::EPD::CS, GENERATED::PIN::EPD::DC,
                 GENERATED::PIN::EPD::RST, GENERATED::PIN::EPD::BUSY));
  this->epaper = std::move(m_p);
  log_info("初始化电子墨水屏完成");
}

void EPaperComponent::loop() {}