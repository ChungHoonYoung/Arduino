/*
void setup() {
  pinMode(LED, OUTPUT)
}

void loop() {
  for(int t_high=0; t_high<=10; t_high++) {
    digitalWrite(LED, HIGH);
    delay(10-t_high);
    digitalWrite(LED, LOW);
    delay(t_high)

    cnt == 0 break;
  }

  for(intint t_high=0; t_high<=1000; t_high++) {
    digitalWrite(LED, HIGH);
    delay(t_high);
    digitalWrite(LED, LOW);
    delay(1000-t_high)
  }
}
*/
int LED = 5;

void setup() {
  
  Serial.begin(115200);
}

void loop() {
  if(LED == 5) {
    Serial.println("pin number : 5");
  }
  else{
    Serial.println("Reconnect pin number");
  }
}
