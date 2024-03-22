/* 
//버튼 눌러서 시리얼 신호받기
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()) {
    char userInput = Serial.read();
    Serial.print(userInput);
  }
}

//입력값 출력 통신
void setup() {
  Serial.begin(115200);
}

void loop() {
  if(Serial.available()) {
    int userInput = Serial.read();

    switch(userInput) {
      case '1' :
        Serial.println(1);
        break;
      case '2' :
        Serial.println(2);
        break;
      case '3' :
        Serial.println(3);
        break;
      default:
        break;
    }
  }
}

//입력 값에 따라 점차 밝아지기
const int LED = 9;

void setup() {
  Serial.begin(115200);
}

void loop() {
  if(Serial.available()) {
    int userInput = Serial.read();

    switch(userInput) {
      case '0' : analogWrite(LED, 0); break;
      case '1' : analogWrite(LED, 25); break;
      case '2' : analogWrite(LED, 50); break;
      case '3' : analogWrite(LED, 75); break;
      case '4' : analogWrite(LED, 100); break;
      case '5' : analogWrite(LED, 125); break;
      case '6' : analogWrite(LED, 150); break;
      case '7' : analogWrite(LED, 175); break;
      case '8' : analogWrite(LED, 200); break;
      case '9' : analogWrite(LED, 225); break;
      default : break;
    }
  }
}

*/

/*
//풀업, 풀다운
int pushButton = 8;

void setup() {
  Serial.begin(115200);
  pinMode(pushButton, INPUT_PULLUP);
}

void loop() {
  int buttonState = digitalRead(pushButton);
  Serial.println(buttonState);
}

*/
/*
//버튼 값에 따라 LED 켜지기
const int ledPin1 = 10;
const int ledPin2 = 11;
const int pushButton1 = 2;
const int pushButton2 = 3;

void setup() {
  Serial.begin(115200);
  pinMode(pushButton1, INPUT_PULLUP);
  pinMode(pushButton2, INPUT_PULLUP);
}

void loop() {
  int buttonState1 = digitalRead(pushButton1);
  if(buttonState1 == LOW) {
    for(int t_high=0; t_high<=255; t_high++) {
      analogWrite(ledPin1, t_high);
      delay(10);
      }
    }
  else {
    analogWrite(ledPin1, 0);
  }
  int buttonState2 = digitalRead(pushButton2);
  if(buttonState2 == LOW) {
    for(int t_high=0; t_high<=255; t_high++) {
      analogWrite(ledPin2, t_high);
      delay(10);
      }
    }
  else {
    analogWrite(ledPin2, 0);
  }
}
*/

/*
//버튼 누르는 동안 순서대로 깜빡이기(슬롯머신)
const unsigned int LED[6] = { 3, 5, 6, 9, 10, 11 };
const int buttonPin = 2;

void setup() {
  for(int x=0; x<=5; x++) {
    pinMode(LED[x], OUTPUT);
  }
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  int buttonInput = digitalRead(buttonPin);
  if(buttonInput == LOW) {
    for(int x=0; x<=5; x++) {
      for(int x=0; x<=5; x++) {
        digitalWrite(LED[x], LOW);
        }
      digitalWrite(LED[x], HIGH);
      buttonInput = digitalRead(buttonPin);
      if(buttonInput == HIGH) break;

      delay(50);
    }
  }
}
*/

//버튼 누르는 동안 순서대로 깜빡이기(슬롯머신) + 징검다리
const unsigned int LED[6] = { 3, 5, 6, 9, 10, 11 };
const int buttonPin = 2;

void setup() {
  for(int x=0; x<=5; x++) {
    pinMode(LED[x], OUTPUT);
  }
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  int buttonInput = digitalRead(buttonPin);
  if(buttonInput == LOW) {
    for(int x=0; x<=5; x+=2) {
      for(int x=0; x<=5; x++) {
        digitalWrite(LED[x], LOW);
        }
      digitalWrite(LED[x], HIGH);
      buttonInput = digitalRead(buttonPin);
      if(buttonInput == HIGH) break;
      delay(200);
    }
    for(int x=1; x<=5; x+=2) {
      for(int x=0; x<=5; x++) {
        digitalWrite(LED[x], LOW);
        }
      digitalWrite(LED[x], HIGH);
      buttonInput = digitalRead(buttonPin);
      if(buttonInput == HIGH) break;
      delay(200);
    }
  }
}
