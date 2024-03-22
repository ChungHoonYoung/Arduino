#include <Bounce2.h>

int rightButton = 7;
int leftButton = 8;
Bounce debouncer_r = Bounce();
Bounce debouncer_l = Bounce();

void setup() {
  pinMode(rightButton, INPUT_PULLUP);
  debouncer_r.attach(7);
  debouncer_r.interval(5);
  pinMode(leftButton, INPUT_PULLUP);
  debouncer_l.attach(8);
  debouncer_l.interval(5);
  Serial.begin(9600);
}

void loop() {
  debouncer_r.update();
  if(debouncer_r.fell()) {
    Serial.println("Right Button");
  }
    debouncer_l.update();
  if(debouncer_l.fell()) {
    Serial.println("Left Button");
  }
}
