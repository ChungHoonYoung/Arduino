#include <MPU6050_tockn.h>
#include <Wire.h>

MPU6050 mpu6050(Wire);

const float tiltThreshold = 1.5;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  mpu6050.begin();
  mpu6050.calcGyroOffsets(true);
}

void loop() {
  mpu6050.update();

  float acclY = mpu6050.getAccY();
    // Serial.print("accY : ");
    // Serial.println(acclY);

    if (acclY > tiltThreshold) {
      Serial.println("위쪽 기울임");
    }
    else if (acclY < -tiltThreshold) {
      Serial.println("아래쪽 기울임");
    }
    delay(500);
}
