#pragma once

#include <PubSubClient.h>
#include <Ticker.h>
#include <WiFi.h>
#include "component.h"

enum BUTTON_ID {
  BUTTON_ID_1 = 1,
  BUTTON_ID_2 = 2,
  BUTTON_ID_3 = 3,
};

enum BUTTON_EVENT_ID {
  BUTTON_EVENT_ID_CLICK = 1,
  BUTTON_EVENT_ID_DOUBLE_CLICK = 2,
  BUTTON_EVENT_ID_LONG_PRESS_START = 3,
  BUTTON_EVENT_ID_LONG_PRESS_STOP = 4,
};
class MqttComponent : public AppComponent {
 private:
  Ticker pollingWiFiStatusTicker;

  WiFiClient wifiClient;
  std::unique_ptr<PubSubClient> mqttClient;

  void onWiFiConnected();
  void subscribe();
  void publish(const char* topic, const char* payload);

 protected:
  void onReceiveSubscribeMessage(const char* topic,
                                 const char* payload,
                                 unsigned int length);

  void onReceiveFrameMessage(const char* payload, unsigned int length);
  void onReceiveLedMessage(const char* payload, unsigned int length);

 public:
  MqttComponent();
  const char* name() override { return "MqttComponent"; };
  void loop() override;

  void publishButtonEvent(BUTTON_ID buttonId, BUTTON_EVENT_ID buttonEventId);
};