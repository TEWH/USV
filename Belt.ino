#include <Wire.h>
#include "Adafruit_DRV2605.h"
Adafruit_DRV2605 drv;
#define ledPin 7
uint8_t effect = 1;
int leftFlag, leftValue, rightValue = 0;
int rightFlag = 1;
void setup() {
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  Serial.begin(38400);
  
  drv.begin();
  
  drv.selectLibrary(1);
  drv.setMode(DRV2605_MODE_INTTRIG); 
}
void loop() {
  drv.setWaveform(0, effect);  // play effect 
  drv.setWaveform(1, 0);       // end waveform
  
  if(Serial.available() > 0) { //Detected message from master
    //Serial.println("Test");
    if(leftFlag == 0 && rightFlag == 1) {
      leftValue = Serial.read();
      if(leftValue < 20) {
        effect = 64;
        drv.go();
        //Serial.println("Vibrate");
      }
  
      //else if(leftValue > 30) {
        //effect = 69;
        //drv.go();
      //}
      
      Serial.print("Read left value: ");
      Serial.println(leftValue);
      leftFlag = 1;
      rightFlag = 0;
    }
    else if(rightFlag == 0 && leftFlag == 1) {
      rightValue = Serial.read();
      //Serial.print("Read right value: ");
      //Serial.println(rightValue);
      leftFlag = 0;
      rightFlag = 1;
    } 
  }
  
  
  //
/*
  if(state == '1') {
    digitalWrite(ledPin, HIGH);
    state = 0;
  }
  else if(state == '0') {
    digitalWrite(ledPin, LOW);
    state = 0;
  }
  Serial.println(Serial.read());
  Serial.println("Hello");
  */
} 
