int SPEED = 9;
int WHEEL = 10;

void setup() {
  Serial.begin(9600);
  pinMode(SPEED, OUTPUT);
  pinMode(WHEEL, OUTPUT);
}

void loop() {
  digitalWrite(WHEEL, HIGH);
  analogWrite(SPEED, HIGH);
}
