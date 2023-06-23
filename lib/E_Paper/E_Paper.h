#pragma once

#include <Arduino.h>
#include <GxEPD2_420c_1680.h>
#include "FrameBuffer.h"
#define MAX_DISPLAY_BUFFER_SIZE \
  (81920ul - 34000ul -          \
   5000ul)  // ~34000 base use, change 5000 to your application use
#define MAX_HEIGHT(EPD)                                            \
  (EPD::HEIGHT <= (MAX_DISPLAY_BUFFER_SIZE / 2) / (EPD::WIDTH / 8) \
       ? EPD::HEIGHT                                               \
       : (MAX_DISPLAY_BUFFER_SIZE / 2) / (EPD::WIDTH / 8))

using EPaperDriver = GxEPD2_3C<GxEPD2_420c_1680, MAX_HEIGHT(GxEPD2_420c_1680)>;
class EPaper {
 private:
  EPaperDriver display;

 public:
  EPaper(int cs, int dc, int rst, int busy)
      : display(GxEPD2_420c_1680(cs, dc, rst, busy)) {
    display.init();
    display.setRotation(0);  // 设置屏幕旋转方向，分别有0，1，2，3这四个方向
    display.firstPage();
  }

  void showFrameBuffer(FrameBuffer& frame) {
    static const uint16_t colorMap[] = {GxEPD_WHITE, GxEPD_BLACK, GxEPD_RED,
                                        GxEPD_BLACK};
    display.setFullWindow();
    log_info("width: %d, height: %d", frame.getWidth(), frame.getHeight());
    for (int y = 0; y < frame.getHeight(); y++) {
      for (int x = 0; x < frame.getWidth(); x++) {
        auto pixel = colorMap[frame.getPixel(x, y)];
        display.drawPixel(x, y, pixel);
      }
    }
    display.display();
    display.hibernate();
  }

  void showTest() {
    display.setFullWindow();
    display.drawCircle(50, 50, 50, GxEPD_BLACK);
    display.display();
    display.hibernate();
  }
};