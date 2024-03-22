int BLU = 9;
int GRE = 10;
int RED = 11;

void setup() {
  // put your setup code here, to run once:
  pinMode(BLU, OUTPUT);
  pinMode(GRE, OUTPUT);
  pinMode(RED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int x=random(10);
  digitalWrite(BLU, x);
  delay(50);  
  int y=random(10);
  digitalWrite(GRE, y);
  delay(50);  
  int z=random(10);
  digitalWrite(RED, z);
  delay(50);  
/*
  int x = random(256);
  int y = random(256);
  int z = random(256);  
  digitalWrite(BLU, x);
  digitalWrite(GRE, y);
  digitalWrite(RED, z);
  delay(100);
  */
}
