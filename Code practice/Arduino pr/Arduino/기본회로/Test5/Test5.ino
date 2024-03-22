const int LED1 = 2;
const int LED2 = 3;
const int LED3 = 4;
const int LED4 = 5;
const int LED5 = 6;
const int LED6 = 7;
const int LED7 = 8;
const int LED8 = 9;

void setup(){
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(LED6, OUTPUT);
  pinMode(LED7, OUTPUT);
  pinMode(LED8, OUTPUT);
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
  for(int t_high=0;t_high<=10;t_high++){
    digitalWrite(LED3, HIGH);
  	delay(t_high);
    digitalWrite(LED3, LOW);
    delay(10-t_high);
  }
  for(int t_high=0;t_high<=10;t_high++){
    digitalWrite(LED4, HIGH);
  	delay(t_high);
    digitalWrite(LED4, LOW);
    delay(10-t_high);
  }
  for(int t_high=0;t_high<=10;t_high++){
    digitalWrite(LED5, HIGH);
  	delay(t_high);
    digitalWrite(LED5, LOW);
    delay(10-t_high);
  }
  for(int t_high=0;t_high<=10;t_high++){
    digitalWrite(LED6, HIGH);
  	delay(t_high);
    digitalWrite(LED6, LOW);
    delay(10-t_high);
  }
  for(int t_high=0;t_high<=10;t_high++){
    digitalWrite(LED7, HIGH);
  	delay(t_high);
    digitalWrite(LED7, LOW);
    delay(10-t_high);
  }
  for(int t_high=0;t_high<=10;t_high++){
    digitalWrite(LED8, HIGH);
  	delay(t_high);
    digitalWrite(LED8, LOW);
    delay(10-t_high);
  }
}