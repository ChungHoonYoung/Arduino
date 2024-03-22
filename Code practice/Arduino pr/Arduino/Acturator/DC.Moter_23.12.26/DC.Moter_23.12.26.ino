const int trig_pin = 11;
const int echo_pin = 12;
int SPEED = 10;
int WHEEL = 9;
int val = 127;

void setup() {
  pinMode(trig_pin, OUTPUT);
  pinMode(echo_pin, INPUT);
  Serial.begin(9600);
  pinMode(SPEED, OUTPUT);
  pinMode(WHEEL, OUTPUT);
  digitalWrite(WHEEL, LOW);
  analogWrite(SPEED, 0);
}

void loop() {
  digitalWrite(trig_pin, LOW);
  delayMicroseconds(2);
  digitalWrite(trig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_pin, LOW);

  long duration = pulseIn(echo_pin, HIGH);
  long distance = (duration/2) / 29.1;

  if(Serial.available() > 0) {
    int c = Serial.read(distance);
    if(c > 10) {
      digitalWrite(WHEEL, LOW);
      analogWrite(SPEED, val);
    }
    else if(c <= 10) {
      digitalWrite(WHEEL, HIGH);
      analogWrite(SPEED, val);
    }
    else if(c = 0) {
      digitalWrite(WHEEL, LOW);
      analogWrite(SPEED, 0);
    }
  }
}
