#include <SoftwareSerial.h>

#define tx 2
#define rx 3

SoftwareSerial blue(2, 3);

int leftSPEED = 6;
int leftWHEEL = 7;
int rightSPEED = 9;
int rightWHEEL = 10;

void setup() {
  Serial.begin(9600);
  blue.begin(9600);
  pinMode(leftSPEED, OUTPUT);
  pinMode(leftWHEEL, OUTPUT);
  //digitalWrite(leftWHEEL, LOW);
 // analogWrite(leftSPEED, 0);
  pinMode(rightSPEED, OUTPUT);
  pinMode(rightWHEEL, OUTPUT);
  //digitalWrite(rightWHEEL, LOW);
 // analogWrite(rightSPEED, 0);
}

void loop() {
  if(blue.available()) {
    int a;

    a = blue.read();
    Serial.write(a);
  
    if (a=='1') {
      digitalWrite(leftWHEEL, HIGH);
      analogWrite(leftSPEED, 127);
      digitalWrite(rightWHEEL, HIGH);
      analogWrite(rightSPEED, 127);
    }
    if (a=='2') {
      digitalWrite(leftWHEEL, HIGH);
      analogWrite(leftSPEED, 0);
      digitalWrite(rightWHEEL, HIGH);
      analogWrite(rightSPEED, 127);
    }
    if(a=='3') {
      digitalWrite(leftWHEEL, HIGH);
      analogWrite(leftSPEED, 127);
      digitalWrite(rightWHEEL, HIGH);
      analogWrite(rightSPEED, 0);
    }
    if(a=='7') {
      digitalWrite(leftWHEEL, LOW);
      analogWrite(leftSPEED, 0);
      digitalWrite(rightWHEEL, LOW);
      analogWrite(rightSPEED, 0);
    }
    if(a=='4') {
      digitalWrite(leftWHEEL, LOW);
      analogWrite(leftSPEED, 127);
      digitalWrite(rightWHEEL, LOW);
      analogWrite(rightSPEED, 127);
    }
    if(a=='5') {
      digitalWrite(leftWHEEL, LOW);
      analogWrite(leftSPEED, 127);
      digitalWrite(rightWHEEL, HIGH);
      analogWrite(rightSPEED, 127);
    }
    if(a=='6') {
      digitalWrite(leftWHEEL, HIGH);
      analogWrite(leftSPEED, 127);
      digitalWrite(rightWHEEL, LOW);
      analogWrite(rightSPEED, 127);
    }
    if(a=='8') {
      digitalWrite(leftWHEEL, HIGH);
      analogWrite(leftSPEED, 255);
      digitalWrite(rightWHEEL, HIGH);
      analogWrite(rightSPEED, 255);
    }
  }
  if(Serial.available()) {
    blue.write(Serial.read());
  }
}