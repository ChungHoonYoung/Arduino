#include <Bounce2.h>
#include <MsTimer2.h>
#define led 8
#define button 2
Bounce debouncer = Bounce();

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(button, INPUT_PULLUP);
  debouncer.attach(button);
  debouncer.interval(5);
  MsTimer2::set(10, aa);
  MsTimer2::start();
}
void loop() {
  if(button, HIGH) {
    digitalWrite(led, HIGH);
  }
  else {
    digitalWrite(led, LOW);
  }
}
void aa() {
  debouncer.update();
  if(digitalRead(button) == 0) {
    Serial.println("Pressed");
  }
  if(debouncer.rose()) {
    Serial.println("Released");
  }
}
