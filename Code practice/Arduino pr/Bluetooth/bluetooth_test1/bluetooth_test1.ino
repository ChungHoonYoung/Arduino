#include <SoftwareSerial.h>

#define tx 3
#define rx 2

SoftwareSerial blue(3, 2);

void setup() {
  Serial.begin(9600);
  blue.begin(9600);
}

void loop() {
  if(blue.available()) {
    Serial.write(blue.read());
  }
  if(Serial.available()) {
    blue.write(Serial.read());
  }
}