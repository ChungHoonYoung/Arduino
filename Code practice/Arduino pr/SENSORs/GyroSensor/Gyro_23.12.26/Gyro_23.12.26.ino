// A demo of the sleep modes for the Adafruit MPU6050

#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

Adafruit_MPU6050 mpu;

/* Create new sensor events */

sensors_event_t a, g, temp;
void setup(void) {
  Serial.begin(115200);
  while(!Serial)
    delay(10); //will pause Zero, Leonardo, etc untill serial console open

  Serial.println("Adafruit MPU6050 test!");

  // Try to initialize!
  if(!mpu.begin()) {
    Serial.println("Failed to find MPU6050 chip");
    while (1) {
      delay(10);
    }
  }
  Serial.println("MPU6050 Found!");
}

void loop() {

}
