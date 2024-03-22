const int analogPin = A0;
int BLU = 9;
int GRE = 10;
int RED = 11;
int button = 2;

void setup() {
  Serial.begin(115200);

  pinMode(analogPin, INPUT);
  pinMode(BLU, OUTPUT);
  pinMode(GRE, OUTPUT);
  pinMode(RED, OUTPUT);
  pinMode(button, INPUT_PULLUP);
}

void loop() {
  int a, b, c;
  int sensorInput = analogRead(analogPin);
  int level1 = map(sensorInput, 0, 1024, 0, 255);
  for(int x=0; x<=255; x++) {
    if(x<level1) {
      a = random(level1);\
      analogWrite(BLU, a);
    }
  }
  int level2 = map(sensorInput, 0, 1024, 0, 255);
  for(int y=0; y<=255; y++) {
    if(y<level2) {
      b = random(level2);
      analogWrite(GRE, b);
    }
  }
  int level3 = map(sensorInput, 0, 1024, 0, 255);
  for(int z=0; z<=255; z++) {
    if(z<level3) {
      c = random(level3);
      analogWrite(RED, c);
    }
  }
  if (digitalRead(button)) {
    Serial.println(a);
    Serial.println(b);
    Serial.println(c);
  } 
}
