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
  
  shiftOut(dataPin, shiftPin, LSBFIRST, 0b10101100);
  
  digitalWrite(latchPin, HIGH);
  
}