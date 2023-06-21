#include <Arduino.h>
#include <U8g2_for_Adafruit_GFX.h>
#include <GxEPD2_420c_1680.h>
#include <OneButton.h>

#include "Log.h"

#define MAX_DISPLAY_BUFFER_SIZE (81920ul - 34000ul - 5000ul) // ~34000 base use, change 5000 to your application use
#define MAX_HEIGHT(EPD) (EPD::HEIGHT <= (MAX_DISPLAY_BUFFER_SIZE / 2) / (EPD::WIDTH / 8) ? EPD::HEIGHT : (MAX_DISPLAY_BUFFER_SIZE / 2) / (EPD::WIDTH / 8))
GxEPD2_3C<GxEPD2_420c_1680, MAX_HEIGHT(GxEPD2_420c_1680)> display(GxEPD2_420c_1680(/*CS=D8*/ 5, /*DC=D2*/ 17, /*RST=D4*/ 16, /*BUSY=D1*/ 4));
// 对象定义
U8G2_FOR_ADAFRUIT_GFX u8g2Fonts; // 汉字输出对象


void on_button1_click()
{
  Serial.println("button1 click");

    // display.setFullWindow();
    // Serial.println("setFullWindow");
    // u8g2Fonts.setFont(u8g2_font_wqy16_t_gb2312);
    // Serial.println("setFont");
    // u8g2Fonts.setForegroundColor(GxEPD_BLACK);
    // Serial.println("setForegroundColor");
    // u8g2Fonts.setBackgroundColor(GxEPD_RED); 
    // Serial.println("setBackgroundColor");
    // u8g2Fonts.setCursor(30, 160);
    // Serial.println("setCursor");
    // u8g2Fonts.print("这是一个示例");
    // Serial.println("print");
  display.setFullWindow();
  
  display.drawCircle(10, 10, 50, GxEPD_BLACK);
  display.drawFastHLine(10, 10, 100, GxEPD_BLACK);
  display.drawFastVLine(10, 10, 100, GxEPD_BLACK);

  display.display();
  display.hibernate();

  Serial.println("hibernate");
}

void setup()
{
  SPI.begin(SCK, MISO, MOSI, -1);
  Serial.begin(115200);

  log_trace("trace%s", "test");
  // pinMode(SD_DET, INPUT_PULLUP);
  
  display.init(); // 初始化屏幕

  // btn1.attachClick(on_button1_click);

  u8g2Fonts.begin(display);
  display.setRotation(0); // 设置屏幕旋转方向，分别有0，1，2，3这四个方向
  display.firstPage();
  
  Serial.println("start sleep");
}

void loop()
{
  // btn1.tick();
}
