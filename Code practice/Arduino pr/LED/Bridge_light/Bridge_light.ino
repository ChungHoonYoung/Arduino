const unsigned int LED[6] = { 3, 5, 6, 9, 10, 11 };

void setup() {
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int x=0; x<=5; x++) {
    for(int a=0; a<=255; a++) {
      analogWrite(LED[x], a);
      delay(10);
    }
    for(int a=255; a>=0; a--) {
      analogWrite(LED[x], a);
      delay(10);
    }
  }
}
