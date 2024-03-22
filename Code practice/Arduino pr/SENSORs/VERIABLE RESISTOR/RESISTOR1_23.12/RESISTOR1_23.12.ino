/*
const int analogPin = A0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  int analogValue = analogRead(analogPin);
  Serial.println(analogValue);
}
*/

/*
//가변저항 값에 따라 LED 밝기 변화
const int ledPin = 10;
const int analogPin = A0;

void setup() {

}

void loop () {
  int analogValue = analogRead(analogPin);
  analogWrite(ledPin, analogValue/4);
}
*/

/*
//디지털 LED 막대 그래프

const int led[6] = { 3, 5, 6, 9, 10, 11 };
const int analogPin = A0;

void setup() {
}

void loop() {
  int sensorInput = analogRead(analogPin);

  for(int n=0; n<=5; n++) {
    if(sensorInput/171 >= 1+n)
      analogWrite(led[n], 255);
    else if (sensorInput/171 >= 0+n)
      analogWrite(led[n], int(sensorInput%171/171.0*255));
  }
}
*/

//map 함수 활용

const int led[6] = { 3, 5, 6, 9, 10, 11 };
const int analogPin = A0;

void setup() {
}

void loop() {
  int sensorInput = analogRead(analogPin);
  int level = map(sensorInput, 0, 1024, 0, 255);
  for(int n=0; n<6; n++) {
    if(n<level) {
      analogWrite(led[n], 255);
    }
    else {
      analogWrite(led[n], 0);
    }
  }
}