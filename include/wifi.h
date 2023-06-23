#include <Ticker.h>
#include "common.h"

class WiFiComponent : public AppComponent {
 private:
  Ticker ticker;

 protected:
  void onWiFiConnected();

 public:
  WiFiComponent();
  const char* name() override { return "WiFiComponent"; }
};