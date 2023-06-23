#pragma once

#include <Ticker.h>
#include <WiFi.h>
#include "component.h"

class WiFiComponent : public AppComponent {
 private:
  Ticker ticker;

 protected:
  void onWiFiConnected();

 public:
  WiFiComponent();
  bool isWiFiConnected() { return WiFi.status() == WL_CONNECTED; }
  const char* name() override { return "WiFiComponent"; }
};