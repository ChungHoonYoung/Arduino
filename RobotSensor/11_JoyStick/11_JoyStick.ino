#define PIN_JX A0
#define PIN_JY A1
#define PIN_JSW 2

volatile bool isbuttonPressed = false;

void ISRbutton() {
  isbuttonPressed = true;
}

void setup() {
  pinMode(PIN_JSW, INPUT_PULLUP);
  Serial.begin(9600);
  attachInterrupt(INT0, ISRbutton, FALLING);
}

void loop() {
  int xVal = analogRead(PIN_JX);
  int yVal = analogRead(PIN_JY);
  int bVal = digitalRead(PIN_JSW);

  Serial.println("X :" + String(xVal) + "Y :" + String(yVal));

  if (isbuttonPressed == true) {
    isbuttonPressed = false;
    Serial.println("Button is Pressed!");
    delay(500);
  }
}
