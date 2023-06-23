#pragma once

#include "component.h"

class SerialComponent : public AppComponent {
 public:
  SerialComponent();
  const char* name() override { return "SerialComponent"; }
  void loop() override;
};