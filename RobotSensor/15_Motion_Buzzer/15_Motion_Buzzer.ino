int buzzerPin = 12;


void setup() {
  Serial.begin(9600);
  //부저
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  //부저 울림
  if (Serial.available() > 0) {
    char data = Serial.read();
    if (data == '1') {
      tone(buzzerPin, 500);
      delay(500);
      noTone(buzzerPin);
    }
  }
}

