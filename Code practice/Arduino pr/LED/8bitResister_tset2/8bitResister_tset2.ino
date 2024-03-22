int dataPin = 7;
int latchPin = 6;
int shiftPin = 5;

void setup() {
  pinMode(dataPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
  pinMode(shiftPin, OUTPUT);
}

void loop() {
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, shiftPin, LSBFIRST, random(0, 256));
  digitalWrite(latchPin, HIGH);
  delay(1000);
  
}