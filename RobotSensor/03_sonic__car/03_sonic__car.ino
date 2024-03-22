//왼쪽모터
#define PIN_MA1A 5
#define PIN_MA1B 6

//오른쪽 모터
#define PIN_MB1A 9
#define PIN_MB1B 10

//초음파센서
#define PIN_SONIC_TRIG 14
#define PIN_SONIC_ECHO 15

const int ledPin = 13;

#define WHEEL_DIFF_VALUE -15

int iSpeed = 150;
int leftWheelSpeed = iSpeed;
int rightWheelSpeed = leftWheelSpeed + WHEEL_DIFF_VALUE;

#define SONIC_DISTANSE 15

void setup() {
  //모터 핀 정의
  pinMode(PIN_MA1A, OUTPUT);
  pinMode(PIN_MA1B, OUTPUT);
  pinMode(PIN_MB1A, OUTPUT);
  pinMode(PIN_MB1B, OUTPUT);
  //초음파센서 핀 정의
  pinMode(PIN_SONIC_TRIG, OUTPUT);
  pinMode(PIN_SONIC_ECHO, INPUT);

  pinMode(ledPin, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  long distance = getDistance();
  Serial.println(String(distance) + "cm");

  if (distance < SONIC_DISTANSE) {
    digitalWrite(ledPin, HIGH);
    backward();
    delay(500);
    left();
    delay(500);
  }
  else {
    digitalWrite(ledPin, LOW);
    forward();
  }
}
//초음파 거리
long getDistance() {
  digitalWrite(PIN_SONIC_TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(PIN_SONIC_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(PIN_SONIC_TRIG, LOW);

  long duration = pulseIn(PIN_SONIC_ECHO, HIGH);
  long distance = (duration / 2) / 29.1;

  return distance;
}

//자동차 이동
void carMove(int aa, int ab, int ba, int bb) {
  analogWrite(PIN_MA1A, aa);
  analogWrite(PIN_MA1B, ab);
  analogWrite(PIN_MB1A, ba);
  analogWrite(PIN_MB1B, bb);
}
void forward(){
  carMove(leftWheelSpeed, 0, rightWheelSpeed, 0);
}

void backward(){
  carMove(0, leftWheelSpeed, 0, rightWheelSpeed);
}

void left(){
  carMove(0, 0, rightWheelSpeed, 0);
}

void right(){
  carMove(leftWheelSpeed, 0, 0, 0);
}

void stop(){
  carMove(0, 0, 0, 0);
}


















