#define PIN_RGB_R 3
#define PIN_RGB_G 5
#define PIN_RGB_B 6


void setup() {
  Serial.begin(9600);
  pinMode(PIN_RGB_R, OUTPUT);
  pinMode(PIN_RGB_G, OUTPUT);
  pinMode(PIN_RGB_B, OUTPUT);
}

void contralLED(int r, int g, int b) {
  analogWrite(PIN_RGB_R, r);
  analogWrite(PIN_RGB_G, g);
  analogWrite(PIN_RGB_B, b);
}


void loop() {
  //R, G, B, Y, X
  if (Serial.available() > 0) {
    char data = Serial.read();
    if (data == 'R') {
      contralLED(255, 0, 0);
    }
    else if (data == 'G') {
      contralLED(0, 255, 0);
    }
    else if (data == 'B') {
      contralLED(0, 0, 255);
    }
    else if (data == 'Y') {
      contralLED(255, 225, 0);
    }
    else if (data == 'W') {
      contralLED(255, 255, 255);
    }
    else if (data == 'X') {
      contralLED(0, 0, 0);
    }
  }
}









