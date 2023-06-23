#include "common.h"

MqttComponent::MqttComponent() {
  log_info("MqttComponent::MqttComponent()");

  pollingWiFiStatusTicker.attach_ms<MqttComponent*>(
      500,
      [](MqttComponent* thiz) {
        if (Global::wifi->isWiFiConnected()) {
          thiz->runOnLoopOnce([thiz]() { thiz->onWiFiConnected(); });
          thiz->pollingWiFiStatusTicker.detach();
        } else {
          log_debug("Waiting for WiFi connection");
        }
      },
      this);
}

void MqttComponent::onWiFiConnected() {
  log_info("MqttComponent::onWiFiConnected()");
  std::unique_ptr<PubSubClient> m_mqtt(new PubSubClient(this->wifiClient));
  this->mqttClient = std::move(m_mqtt);

  this->mqttClient->setServer(GENERATED::MQTT::HOST, GENERATED::MQTT::PORT);
  this->mqttClient->setBufferSize(1024 * 20);
  this->mqttClient->setCallback(
      [this](char* topic, byte* payload, unsigned int length) {
        String s = topic;
        if (s.startsWith(GENERATED::MQTT::NAMESPACE)) {
          topic += strlen(GENERATED::MQTT::NAMESPACE);
          this->onReceiveSubscribeMessage(topic, (char*)payload, length);
        } else {
          // ignore it
          log_warn("收到未知主题 %s", topic);
          return;
        }
      });
  for (int i = 0; i < 3; i++) {
    bool result = this->mqttClient->connect(GENERATED::MQTT::CLIENT_ID);
    if (result) {
      log_info("MQTT 连接成功");
      this->subscribe();
      break;
    } else {
      log_error("MQTT 连接失败");
    }
  }
}

void MqttComponent::subscribe() {
  log_info("MqttComponent::subscribe()");
  auto subscribeTopic = [this](const char* topic) {
    String s = GENERATED::MQTT::NAMESPACE;
    s += topic;
    bool result = this->mqttClient->subscribe(s.c_str());
    if (result) {
      log_info("订阅主题 %s 成功", s.c_str());
    } else {
      log_error("订阅主题 %s 失败", s.c_str());
    }
    return result;
  };
  subscribeTopic("frame");
  subscribeTopic("led/1");
}

void MqttComponent::publish(const char* topic, const char* payload) {
  String s = GENERATED::MQTT::NAMESPACE;
  s += topic;
  bool result = this->mqttClient->publish(s.c_str(), payload);
  if (result) {
    log_info("发布主题 %s 成功", s.c_str());
  } else {
    log_error("发布主题 %s 失败", s.c_str());
  }
}

void MqttComponent::onReceiveSubscribeMessage(const char* topic,
                                              const char* payload,
                                              unsigned int length) {
  log_info("MqttComponent::onReceiveSubscribeMessage()");
  if (strcmp(topic, "frame") == 0) {
    this->onReceiveFrameMessage(payload, length);
  } else if (strcmp(topic, "led/1") == 0) {
    this->onReceiveLedMessage(payload, length);
  } else {
    log_warn("收到未知主题 %s", topic);
  }
}

void MqttComponent::loop() {
  AppComponent::loop();
  if (this->mqttClient) {
    this->mqttClient->loop();
  }
}

void MqttComponent::publishButtonEvent(BUTTON_ID buttonId,
                                       BUTTON_EVENT_ID buttonEventId) {
  String s = "button/" + String(buttonId);
  String payload = String(buttonEventId);
  this->publish(s.c_str(), payload.c_str());
}

void MqttComponent::onReceiveFrameMessage(const char* payload,
                                          unsigned int length) {
  log_info("MqttComponent::onReceiveFrameMessage()");
  log_debug("payload length: %d", length);
  uint16_t width = (uint16_t)payload[0] << 8 | payload[1];
  uint16_t height = (uint16_t)payload[2] << 8 | payload[3];
  uint8_t* buf = (uint8_t*)malloc(width * height / 8);
  memcpy(buf, payload + 4, width * height / 8);
  FrameBuffer frameBuffer(width, height, buf);
  Global::epaper->showFrameBuffer(frameBuffer);
}

void MqttComponent::onReceiveLedMessage(const char* payload,
                                        unsigned int length) {
  log_info("MqttComponent::onReceiveLedMessage()");
}