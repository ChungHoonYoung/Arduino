/* const int LED = 13;

void setup()
{
  pinMode(LED, OUTPUT);
}

void loop()
{
  for(int t_high=0;t_high<=10;t_high++){
    digitalWrite(LED, HIGH);
  	delay(t_high);
  }
  
  
  
} */

/* // C++ code
//
const int LED1 = 13;
const int LED2 = 12;

void setup(){
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
}

void loop(){
  for(int t_high=0;t_high<=10;t_high++){
    digitalWrite(LED1, HIGH);
  	delay(t_high);
    digitalWrite(LED1, LOW);
    delay(10-t_high);
  }
  for(int t_high=0;t_high<=10;t_high++){
    digitalWrite(LED2, HIGH);
  	delay(t_high);
    digitalWrite(LED2, LOW);
    delay(10-t_high);
  }
} */

const int LED = 13;

void setup() {
  pinMode(LED, OUTPUT)
7}

void loop() {
  for(int t_high=0; t_high<=10; t_high++) {
    int cnt = 0;
    while(true) {
      digitalWrite(LED, HIGH)
      delay(t_high)
      digitalWrite(LED, LOW)
      delay(10-t_high)

      cnt++;
      if(cnt==10) break;
    }
  }
}