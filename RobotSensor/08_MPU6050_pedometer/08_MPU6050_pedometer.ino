#include <MPU6050_tockn.h>
#include <Wire.h>

MPU6050 mpu6050(Wire);

int stepCount = 0;

bool isStepPeak = false;

const float tiltThreshold = 1.5;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  mpu6050.begin();
  mpu6050.calcGyroOffsets(true);
}

void loop() {
  mpu6050.update();

  float accelY = mpu6050.getAccY();
    Serial.print("accY : ");
    Serial.println(accelY);

    if (isStepPeak && accelY < 0) {
      isStepPeak = false;
    }

    if (accelY > tiltThreshold && !isStepPeak) {
      isStepPeak = true;
      stepCount++;
      Serial.println("걸음수 : " + String(stepCount));
    }
    delay(500);
}














