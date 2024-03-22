const unsigned int led[8] = { 6, 7, 8, 9, 10, 11, 12, 13 };

void setup() {
  // put your setup code here, to run once:
  for(int x=0; x<=sizeof(led); x++) {
    pinMode(led[x], OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
 for(int x=0; x<=6; x+=2) {
  digitalWrite(led[x], HIGH);
  delay(100);
  digitalWrite(led[x], LOW);
 }
 for(int x=1; x<=7; x+=2) {
  digitalWrite(led[x], HIGH);
  delay(100);
  digitalWrite(led[x], LOW);
 }
}
