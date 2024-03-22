#define PIN_LED 9
#define PIN_BUZZER 3

void setup() {
  Serial.begin(115200);
  pinMode(PIN_LED, OUTPUT);
  pinMode(PIN_BUZZER, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    int ledBrightness = Serial.read();
    ledBrightness = constrain(ledBrightness, 0, 255);
    analogWrite(PIN_LED, ledBrightness);

    analogWrite(PIN_BUZZER, ledBrightness);
  }
}
