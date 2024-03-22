void setup() {
  Serial.begin(115200);
}

void loop() {
  int baseA, shoulderA, upperA, foreA;

  while (Serial.available() > 0) {
    baseA     = Serial.parseInt();
    shoulderA = Serial.parseInt();
    upperA    = Serial.parseInt();
    foreA     = Serial.parseInt();

    if (Serial.read() == 'd') {
      Serial.println("Received Signal");
    }

    String base     = "base     : " + String(baseA);
    String shoulder = "shoulder : " + String(shoulderA);
    String upperArm = "upperArm : " + String(upperA);
    String foreArm  = "foreArm  : " + String(foreA);

    Serial.println(base);
    Serial.println(shoulder);
    Serial.println(upperArm);
    Serial.println(foreArm);
  }
}
