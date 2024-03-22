#include <Servo.h>
Servo myServo;
const int servoPin = 11;

const int buzzerPin = 12;

int pos = 15;
int direction = 1;

const int min_angle = 15;
const int max_angle = 165;

#include "Adafruit_VL53L0X.h"
Adafruit_VL53L0X lox = Adafruit_VL53L0X();


void setup() {
  Serial.begin(9600);
  //부저
  pinMode(buzzerPin, OUTPUT);

  // wait until serial port opens for native USB devices
  while (!Serial) {
    delay(1);
  }

  Serial.println("Adafruit VL53L0X test.");
  if (!lox.begin()) {
    Serial.println(F("Failed to boot VL53L0X"));
    while (1)
      ;
  }
  // power
  Serial.println(F("VL53L0X API Continuous Ranging example\n\n"));

  // start continuous ranging
  lox.startRangeContinuous();

  //서보모터
  myServo.attach(servoPin);
  myServo.write(90);
}

void loop() {
  int distance;

  pos = analogRead(A0);
  map(pos, 0, 1023, 180, 0);

  myServo.write(pos);

  if (pos >= max_angle) {
    pos = 165;
    direction = -1;
  } else if (pos <= min_angle) {
    pos = 15;
    direction = 1;
  }
  // Serial.println(pos);
  myServo.write(pos);

  distance = getDistance();
  //통신 규약
  Serial.print(pos);
  Serial.print(",");
  Serial.print(distance);
  Serial.print(".");

  if (distance < 10 && distance != 0) digitalWrite(buzzerPin, HIGH);
  else digitalWrite(buzzerPin, LOW);

  delay(30);
}

int getDistance() {
  if (lox.isRangeComplete()) {
    return (lox.readRange() / 10);
  } 
  return 0;
}
