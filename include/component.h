#pragma once

class AppComponent {
 public:
  virtual const char* name() = 0;
  virtual void loop() = 0;
};