#include <SoftwareSerial.h>

#define blueTX 4
#define blueRX 3

SoftwareSerial HC06(blueTX, blueRX);

char ser = 0;
char ble = 0;

void setup() {
  Serial.begin(9600);
  HC06.begin(9600);
}

void loop() {
  //Serial > HC06
  if (Serial.available() > 0 ) {
    ser = Serial.read();
    HC06.write(ser);
  }
  //HC06 > Serial
  if (HC06.available() > 0 ) {
    ble = HC06.read();
    HC06.write(ble);
  }
}
