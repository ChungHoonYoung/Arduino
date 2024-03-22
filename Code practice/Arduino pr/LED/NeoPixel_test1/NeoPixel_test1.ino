#include <Adafruit_NeoPixel.h>

Adafruit_NeoPixel neo1(4, 6, NEO_GBR + NEO_KHZ800);

void setup() {
  neo1.begin();
}

void loop() {
  neo1.setPixelColor(random(4), random(256), random(256), random(256));
  neo1.show();
  delay(1000);
  neo1.clear();
}