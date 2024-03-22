#include <Servo.h>

const int basePin = 4;
const int shoulderPin = 5;
const int upperArmPin = 6;
const int foreArmPin = 7;

const int servoInitAngle = 90;

Servo base;
Servo shoulder;
Servo upperArm;
Servo foreArm;

void setup() {
  Serial.begin(9600);

  base.attach(basePin);
  shoulder.attach(shoulderPin);
  upperArm.attach(upperArmPin);
  foreArm.attach(foreArmPin);
}

void loop() {
  base.write(servoInitAngle);
  shoulder.write(servoInitAngle);
  upperArm.write(servoInitAngle);
  foreArm.write(servoInitAngle);
}


##로봇암 Sweep 예제
#include <Servo.h>
const int baseP = 4;
const int shoulerP = 5;
const int upperP=6;
const int forearP=7;
const int serInitAngle =40;
Servo base;
Servo shouler;
Servo upper;
Servo forear;
int pos = 0;
void setup(){
  Serial.begin(9600);
  base.attach(baseP);
  shouler.attach(shoulerP);
  upper.attach(upperP);
  forear.attach(forearP);
  base.write(serInitAngle);
  shouler.write(serInitAngle);
  upper.write(serInitAngle);
  forear.write(serInitAngle);
}
void loop() {
  for (pos = 30; pos <= 150; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    base.write(pos);
    shouler.write(pos);
    upper.write(pos);
    forear.write(pos);
    delay(15);                       // waits 15 ms for the servo to reach the position
  }
  for (pos = 150; pos >= 30; pos -= 1) { // goes from 180 degrees to 0 degrees
    base.write(pos);
    shouler.write(pos);
    upper.write(pos);
    forear.write(pos);
    delay(15);                       // waits 15 ms for the servo to reach the position
  }
}