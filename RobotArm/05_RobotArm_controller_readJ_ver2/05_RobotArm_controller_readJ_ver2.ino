#define PIN_SERVO_READ_BUTTON 8

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128  // OLED display width, in pixels
#define SCREEN_HEIGHT 64  // OLED display height, in pixels

#define OLED_RESET -1        // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C  ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#include <Servo.h>

const int basePin = 4;
const int shoulderPin = 5;
const int upperArmPin = 6;
const int foreArmPin = 7;

const int servoInitAngle = 90;

Servo base;
Servo shoulder;
Servo upperArm;
Servo foreArm;

int baseA = 0;
int shoulderA = 0;
int upperA = 0;
int foreA = 0;

int baseStatus = 0;
int shoulderStatus = 0;
int upperarmStatus = 0;
int forearmStatus = 0;

void setup() {
  Serial.begin(115200);

  pinMode(PIN_SERVO_READ_BUTTON, INPUT_PULLUP);

  //서보모터
  base.attach(basePin);
  shoulder.attach(shoulderPin);
  upperArm.attach(upperArmPin);
  foreArm.attach(foreArmPin);

  //OLED
  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;)
      ;  // Don't proceed, loop forever
  }

  Serial.println("oled found");
  display.clearDisplay();
  display.display();
}

int servoParallelControl(int thePos, Servo theServo, int speed) {
  int startPos = theServo.read();
  int newPos = startPos;

  if (startPos < (thePos)) {
    newPos = newPos + 1;
    theServo.write(newPos);
    delay(speed);
    return 0;
  } else if (newPos > (thePos)) {
    newPos = newPos - 1;
    theServo.write(newPos);
    delay(speed);
    return 0;
  } else {
    return 1;
  }
}

void readServoAngle() {
  if (digitalRead(PIN_SERVO_READ_BUTTON) == LOW) {
    baseA = base.read();
    shoulderA = shoulder.read();
    upperA = upperArm.read();
    foreA = foreArm.read();

    displayOLED();
  }
}

void displayOLED() {
  String baseStr = "base     : " + String(baseA);
  String shoulderStr = "shoulder : " + String(shoulderA);
  String upperarmStr = "upperArm : " + String(upperA);
  String forearmStr = "foreArm  : " + String(foreA);

  display.setTextSize(1.5);
  display.setTextColor(SSD1306_BLACK, SSD1306_WHITE);

  display.setCursor(0, 0);
  display.println("Robot Arm Move");
  display.setTextColor(SSD1306_WHITE);
  display.println("-----------------");
  display.println(" ");

  display.setTextSize(1);
  display.println(baseStr);
  display.println(shoulderStr);
  display.println(upperarmStr);
  display.println(forearmStr);
  display.println(" ");

  display.display();
}

void loop() {
  display.clearDisplay();
  readServoAngle();

  while (Serial.available() > 0) {
    baseA = Serial.parseInt();
    shoulderA = Serial.parseInt();
    upperA = Serial.parseInt();
    foreA = Serial.parseInt();

    if (Serial.read() == 'd') {
      Serial.println("Received Signal");
    }

    displayOLED();

    // 서보 모터 각도 설정
    base.write(baseA);
    shoulder.write(shoulderA);
    upperArm.write(upperA);
    foreArm.write(foreA);

    delay(100);
  }
}