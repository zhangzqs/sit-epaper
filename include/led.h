#pragma once

#include "component.h"

class LEDComponent : public AppComponent {
 private:
  int pin;

 public:
  LEDComponent();
  void on();
  void off();
  void toggle();

  const char* name() override { return "LED"; }

  void loop() override;
};