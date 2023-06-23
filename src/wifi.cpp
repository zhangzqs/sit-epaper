#include "common.h"
WiFiComponent::WiFiComponent() {
  log_debug("WiFiComponent::setup");
  WiFi.mode(WIFI_STA);
  WiFi.begin(GENERATED::WIFI::SSID, GENERATED::WIFI::PASSWORD);
  log_info("连接到WiFi: %s", GENERATED::WIFI::SSID);
  ticker.attach_ms<WiFiComponent*>(
      500,
      [](WiFiComponent* thiz) {
        switch (WiFi.status()) {
          case WL_CONNECTED:
            thiz->runOnLoopOnce([thiz]() { thiz->onWiFiConnected(); });
            thiz->ticker.detach();
          case WL_IDLE_STATUS:
            break;
          case WL_CONNECT_FAILED:
            log_error("WiFi连接失败");
            break;
          case WL_CONNECTION_LOST:
            log_error("WiFi连接丢失");
            break;
          default:
            log_error("WiFi状态未知: %d", WiFi.status());
        }
      },
      this);
}

void WiFiComponent::onWiFiConnected() {
  log_info("WiFi连接成功");
  log_info("IP地址: %s", WiFi.localIP().toString().c_str());
  log_info("子网掩码: %s", WiFi.subnetMask().toString().c_str());
  log_info("网关: %s", WiFi.gatewayIP().toString().c_str());
  log_info("DNS: %s", WiFi.dnsIP().toString().c_str());
  log_info("MAC地址: %s", WiFi.macAddress().c_str());
  log_info("主机名: %s", WiFi.getHostname());
  log_info("信号强度: %d", WiFi.RSSI());
  log_info("频道: %d", WiFi.channel());
  log_info("连接速率: %d", WiFi.getTxPower());
}