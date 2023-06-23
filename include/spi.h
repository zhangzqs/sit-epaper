#pragma once

#include <SPI.h>
#include "component.h"
class SpiComponent : public AppComponent {
 public:
  SpiComponent();
  const char* name() override { return "SpiComponent"; }
  void loop() override;
};