
/* Arduino_GFX Hello World example für waveshare ESP32-C6 TFT 1.91" */

#include <Arduino.h>
#include <Arduino_GFX_Library.h>

#define GFX_BL 15 // default backlight pin, you may replace DF_GFX_BL to actual backlight pin

Arduino_DataBus *bus = new Arduino_HWSPI(6 /* DC */, 7 /* CS */, 5 /* SCK */, 4 /* MOSI */);
Arduino_GFX *gfx = new Arduino_ST7789(bus, 14 /* RST */, 0 /*rotation*/, 0 /*IPS屏*/, 170 /*w*/, 320 /*h*/, 35 /*起始列偏移（左边）*/, 0 /*起始行偏移（上边）*/, 35 /*结束列偏移（右边）*/, 0 /*结束行偏移（下边）*/);

void setup(void)
{
  Serial.begin(115200);
  // Serial.setDebugOutput(true);
  // while(!Serial);
  Serial.println("Arduino_GFX Hello World example");

#ifdef GFX_EXTRA_PRE_INIT
  GFX_EXTRA_PRE_INIT();
#endif

  // Init Display
  if (!gfx->begin())
  {
    Serial.println("gfx->begin() failed!");
  }
  gfx->fillScreen(WHITE);

#ifdef GFX_BL
  pinMode(GFX_BL, OUTPUT);
  digitalWrite(GFX_BL, LOW);
#endif

  gfx->setCursor(0, 0);
  gfx->setTextSize(2, 2, 1);
  ;
  gfx->setRotation(1);
  gfx->setTextColor(RED);
  gfx->println("Hello World!");
  printf("w:%d,h:%d\n", gfx->width(), gfx->height());
  delay(5000); // 5 seconds
}

void loop()
{
  // gfx->setCursor(random(gfx->width()), random(gfx->height()));
  // gfx->setTextColor(random(0xffff), random(0xffff));
  // gfx->setTextSize(random(6) /* x scale */, random(6) /* y scale */, random(2) /* pixel_margin */);

  gfx->setCursor(0, 0);
  gfx->fillScreen(WHITE);
  for (int i = 0; i < 5; i++)
  {

    gfx->println("Hello World!");
    delay(1000); // 1 second
  }
}
