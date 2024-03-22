#define PIN_IR_L 7
#define PIN_IR_R 8

#define LINE 1
#define NO_LINE 0

#define GET_IR_L digitalRead(PIN_IR_L)
#define GET_IR_R digitalRead(PIN_IR_R)

//왼쪽모터
#define PIN_MA1A 5
#define PIN_MA1B 6

//오른쪽 모터
#define PIN_MB1A 9
#define PIN_MB1B 10

#define WHEEL_DIFF_VALUE -15

int iSpeed = 150;
int leftWheelSpeed = iSpeed;
int rightWheelSpeed = leftWheelSpeed + WHEEL_DIFF_VALUE;

void setup() {
  pinMode(PIN_IR_L, INPUT);
  pinMode(PIN_IR_R, INPUT);
  //모터 핀 정의
  pinMode(PIN_MA1A, OUTPUT);
  pinMode(PIN_MA1B, OUTPUT);
  pinMode(PIN_MB1A, OUTPUT);
  pinMode(PIN_MB1B, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  if (GET_IR_L == LINE&&GET_IR_R == NO_LINE) {
    left();
  }
  else if (GET_IR_R == LINE&&GET_IR_L == NO_LINE) {
    right();
  }
  else if (GET_IR_L == LINE&&GET_IR_R == LINE){
    stop();
  }
  else {
    forward();
  }
}

//자동차 이동
void carMove(int aa, int ab, int ba, int bb) {
  analogWrite(PIN_MA1A, aa);
  analogWrite(PIN_MA1B, ab);
  analogWrite(PIN_MB1A, ba);
  analogWrite(PIN_MB1B, bb);
}
void forward() {
  carMove(leftWheelSpeed, 0, rightWheelSpeed, 0);
}

void backward() {
  carMove(0, leftWheelSpeed, 0, rightWheelSpeed);
}

void left() {
  carMove(0, leftWheelSpeed, rightWheelSpeed*0.8, 0);
}

void right() {
  carMove(leftWheelSpeed*0.8, 0, 0, rightWheelSpeed);
}

void stop() {
  carMove(0, 0, 0, 0);
}
