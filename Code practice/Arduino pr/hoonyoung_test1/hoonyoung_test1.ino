#include <Wire.h>
#include <Adafruit_SSD1306.h>
Adafruit_SSD1306 display(128, 32, &Wire, 0);
#define SCREEN_ADDRESS 0x3C

const int veriPin = A0;
const int redPin = 11;
const int grePin = 10;
const int bluPin = 9;

int lastVeriValue = 0;

void setup() {
  Serial.begin(9600);
  
  pinMode(redPin, OUTPUT);
  pinMode(grePin, OUTPUT);
  pinMode(bluPin, OUTPUT);
  
  display.begin(128,32);
  display.print("RGB value:");
  display.setCursor(0, 0);
  
}

void loop() {  
  int veriValue = analogRead(veriPin);
  if(veriValue != lastVeriValue) {
    int red = random(256);
    int gre = random(256);
    int blu = random(256);
      
    analogWrite(redPin, red);
    analogWrite(grePin, gre);
    analogWrite(bluPin, blu);
    
    Serial.print("RED : ");
    Serial.println(red);
    Serial.print("GREEN : ");
    Serial.println(gre);
    Serial.print("BLUE : ");
    Serial.println(blu);
      
    display.setCursor(0, 1);
    display.print("RED :");
    display.print(red);
    display.print(" GREEN :");
    display.print(gre);
    display.print(" BLUE :");
    display.print(blu);
    
    lastVeriValue = veriValue;
  }  
} 
