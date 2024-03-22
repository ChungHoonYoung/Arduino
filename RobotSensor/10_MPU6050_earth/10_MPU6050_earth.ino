#define PIN_BUZZER 13

#include <MPU6050_tockn.h>
#include <Wire.h>

MPU6050 mpu6050(Wire);

#define MIN_VAL -3
#define MAX_VAL 3

void setup() {
  Serial.begin(9600);
  Wire.begin();
  mpu6050.begin();
  mpu6050.calcGyroOffsets(true);
  Serial.println("\nStart!!");

  pinMode(PIN_BUZZER, OUTPUT);
  digitalWrite(PIN_BUZZER, LOW);
}

void loop() {
  mpu6050.update();
  signed int GyroX = mpu6050.getGyroX();
  signed int GyroY = mpu6050.getGyroY();
  signed int GyroZ = mpu6050.getGyroZ();

  if ((GyroX > MAX_VAL || GyroX < MIN_VAL) 
  && (GyroY > MAX_VAL || GyroY < MIN_VAL) 
  && (GyroZ > MAX_VAL || GyroZ < MIN_VAL)) {
    Serial.println(String(GyroX) + ":" + String(GyroY) + ":" + String(GyroZ));
    digitalWrite(PIN_BUZZER, HIGH);
    delay(1000);
    digitalWrite(PIN_BUZZER, LOW);
  }
}
