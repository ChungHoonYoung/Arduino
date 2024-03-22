int dataPin = 7;
int latchPin = 6;
int shiftPin = 5;

void setup() {
  pinMode(dataPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
  pinMode(shiftPin, OUTPUT);
 }

void loop(){
  int numDeci[10] = {252, 96, 218, 242, 102, 182, 190, 224, 254, 246};
  
  for(int i=0; i<10; i++){
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, shiftPin, LSBFIRST, numDeci[i]);
    digitalWrite(latchPin, HIGH);
    delay(1000);
  }
}