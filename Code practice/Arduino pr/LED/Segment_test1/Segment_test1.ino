int seg[] = {2, 3, 4, 5, 6, 7, 8, 9};

byte digits[10][8] = {
  { 1, 1, 1, 1, 1, 1, 0, 0 }, //0
  { 0, 1, 1, 0, 0, 0, 0, 0 }, //1
  { 1, 1, 0, 1, 1, 0, 1, 0 }, //2
  { 1, 1, 1, 1, 0, 0, 1, 0 }, //3
  { 0, 1, 1, 0, 0, 1, 1, 0 }, //4
  { 1, 0, 1, 1, 0, 1, 1, 0 }, //5
  { 0, 0, 1, 1, 1, 1, 1, 0 }, //6
  { 1, 1, 1, 0, 0, 0, 0, 0 }, //7
  { 1, 1, 1, 1, 1, 1, 1, 0 }, //8
  { 1, 1, 1, 0, 0, 1, 1, 0 }, //9
};
void setup(){
  for(int i = 0; i < 8; i++) {
    pinMode(seg[i], OUTPUT);
  }
 }

void loop(){
  for(int i=0; i<10; i++) {
    for(int j=0; j<8; j++) {
      digitalWrite(seg[j], digits[i][j]);
    }
    delay(1000);
  }
}