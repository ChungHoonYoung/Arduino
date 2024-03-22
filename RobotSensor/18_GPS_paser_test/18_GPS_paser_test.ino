#include <SoftwareSerial.h>

SoftwareSerial gpsSerial(11, 12);

#define TARGET_PROTOCL "GPGGA"

void setup() {
  Serial.begin(9600);
  Serial.println("Start GPS...");
  gpsSerial.begin(9600);
}

void loop() {
  String gpsData = "";

  while (Serial.available()) {
    gpsData = Serial.readStringUntil('\n');

    if (gpsData.indexOf(TARGET_PROTOCL) != -1) {
      Serial.println("Data : " + gpsData);

      int commaIndex1 = gpsData.indexOf(",");
      int commaIndex2 = gpsData.indexOf(",", commaIndex1 + 1);
      int commaIndex3 = gpsData.indexOf(",", commaIndex2 + 1);
      int commaIndex4 = gpsData.indexOf(",", commaIndex3 + 1);
      int commaIndex5 = gpsData.indexOf(",", commaIndex4 + 1);

      //위도 경도 추출
      String Lat = gpsData.substring(commaIndex2 + 1, commaIndex3);
      String Long = gpsData.substring(commaIndex4 + 1, commaIndex5);

      //위도 값 구분
      String Lat1 = Lat.substring(0, 2);
      String Lat2 = Lat.substring(2);

      //경도 값 구분
      String Long1 = Long.substring(0, 3);
      String Long2 = Long.substring(3);

      //좌표 계산
      double LatF = Lat1.toDouble() + Lat2.toDouble()/60;
      double LongF = Long1.toDouble() + Long2.toDouble()/60;

      //좌표 출력
      Serial.print("Lat : ");
      Serial.print(LatF, 15);
      Serial.print(" Long : ");
      Serial.print(LongF, 15);

    }
  }
}
