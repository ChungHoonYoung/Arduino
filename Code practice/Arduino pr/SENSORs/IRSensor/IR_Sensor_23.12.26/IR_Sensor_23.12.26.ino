int IR = 2;
int LED = 8;


void setup() {
  pinMode(IR, INPUT);
  pinMode(LED, OUTPUT);
  Serial.begin(115200);

}

void loop() {
  int IRSensor = digitalRead(IR);
  Serial.println(IRSensor);
  if(IRSensor==LOW) {
    digitalWrite(LED, HIGH);
  }
  else {
    digitalWrite(LED, LOW);
  }
}
