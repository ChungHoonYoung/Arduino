#include <Servo.h>
#define PIN_SERVO 3
Servo servo;

#include <MPU6050_tockn.h>
#include <Wire.h>

MPU6050 mpu6050(Wire);
float angleZ = 0.0;

unsigned long prevMillis = 0;
const int inteval = 100;


void setup() {
  Serial.begin(9600);
  Wire.begin();
  mpu6050.begin();
  mpu6050.calcGyroOffsets(true);

  servo.attach(PIN_SERVO);
  Serial.println("\nServo 90 setting");
  servo.write(90);
  delay(2000);
}

void loop() {
  unsigned long currMillis = millis();
  if (currMillis - prevMillis >= inteval) {
    prevMillis = currMillis;

    mpu6050.update();
    float angleZ = mpu6050.getAngleZ();

    //서보모터 움직이기
    // +80 ~ -90
    angleZ = map(int(angleZ), -90, 90, 5, 175);
    angleZ = constrain(angleZ, 5, 175);
    Serial.println(angleZ);
    servo.write(angleZ);
  }
}














