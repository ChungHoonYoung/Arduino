#include <Bounce2.h>

int button = 2;
Bounce debouncer = Bounce();

void setup() {
  pinMode(button, INPUT_PULLUP);
  debouncer.attach(button);
  debouncer.interval(5);
  Serial.begin(9600);
}

void loop() {
  debouncer.update();

  if(debouncer.fell()) {
    Serial.println("Pressed");
  }

  if(debouncer.rose()) {
    Serial.println("Released");
  }

}
