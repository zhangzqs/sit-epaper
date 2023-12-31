#pragma once

#include "component.h"

#include <E_Paper.h>

class EPaperComponent : public AppComponent {
 private:
  std::unique_ptr<EPaper> epaper;

 public:
  EPaperComponent();
  const char* name() override { return "EPaperComponent"; }

  void showFrameBuffer(FrameBuffer& frameBuffer) {
    epaper->showFrameBuffer(frameBuffer);
  }
  void showTest() { epaper->showTest(); }
  void loop() override;
};