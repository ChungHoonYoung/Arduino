#include <DHT.h>
#include <SoftwareSerial.h>

DHT myDHT (A0, DHT11);

SoftwareSerial myBlueT(2, 3);

void setup() {
  Serial.begin(9600);
  myBlueT.begin(9600);
  myDHT.begin();
}

void loop() {
  float temper = myDHT.readTemperature();
  myBlueT.println("t"+String(temper));
  Serial.print("temp : "+String(temper)+"℃  ");
  delay(1000);
  float humid = myDHT.readHumidity();
  myBlueT.println("h"+String(humid));
  Serial.println("hum : "+String(humid)+"%");
  delay(1000);
}
