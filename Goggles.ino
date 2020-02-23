//#include <Wire.h>
//#include "Adafruit_DRV2605.h"
//Adafruit_DRV2605 drv;
#define buttonPin 5
/* Things to implement: 
 * Get rid of random data - If too far, no need to send.
 * If things do not change, don't send.
 */
int buttonState = 0;
const int trigPin1 = 9;
const int echoPin1 = 10;
const int trigPin2 = 11;
const int echoPin2= 12;
float duration1, distance1, duration2, distance2;
void setup() {
  Serial.begin(38400);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(3, OUTPUT); // Left motor (1)
  pinMode(4, OUTPUT); // Right motor (2)
  pinMode(buttonPin, INPUT);
/*
  drv.begin();
  
  drv.selectLibrary(1);
  drv.setMode(DRV2605_MODE_INTTRIG); 
*/
}
uint8_t effect = 1;
int value = 0;
void loop() {
    // set the effect to play
  //drv.setWaveform(0, effect);  // play effect 
  //drv.setWaveform(1, 0);       // end waveform
  /*
  buttonState = digitalRead(buttonPin);
  if(buttonState == HIGH) {
    Serial.write('1');
  }
  else if(buttonState == LOW) {
    Serial.write('0');
  }
  */
  
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  digitalWrite(3, LOW); //L
  digitalWrite(4, LOW); //R
  duration1 = pulseIn(echoPin1, HIGH);
  distance1 = (duration1*.0343)/2;
  //Serial.write((int)distance1);
    //Serial.println("sending data");
    /*
  else {
    //Serial.println("Not working");
  }
  delay(50);
  */
  //delay(100); //Exaggerated delay
  
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  //digitalWrite(6, LOW); //0
  duration2 = pulseIn(echoPin2, HIGH);
  distance2 = (duration2*.0343)/2;
  //Serial.write((int)distance2);
  if(Serial.availableForWrite() && distance1 < 2000 && distance2 < 2000) {
    Serial.write((int)distance1);
    Serial.write((int)distance2);
    //Serial.println("sending data");
  }
  else if(!Serial.availableForWrite()) {
    Serial.write(111);
    
  }
  //delay(50); 
  
  //Serial.print("***Distance1: ");
  //Serial.print(distance1);
  //Serial.println("***");
  //delay(100);
  /*
  Serial.print("***Distance2: ");
  Serial.print(distance2);
  Serial.println("***");
  delay(500);
  */
  /*
//*****************************************************LEFT
  if(distance2 < 60 && distance2 > 50){
    effect = 69;
    drv.go();
  }
  if(distance2 < 50 && distance2 > 40){
    effect = 68;f
    drv.go();
  } 
  if(distance2 < 40 && distance2 > 30){
    effect = 67;
    drv.go();
  }  
  if(distance2 < 30 && distance2 > 20){
    effect = 66;
    drv.go();
  }
  if(distance2 < 20 && distance2 > 10){
    effect = 65;
    drv.go();
  }
  if(distance2 < 10){
    effect = 64;
    drv.go();
  }
//*******************************************************RIGHT
  if(distance2 < 60 && distance2 > 50){
    effect = 69;
    drv.go();
  }
  if(distance2 < 50 && distance2 > 40){
    effect = 68;
    drv.go();
  } 
  if(distance2 < 40 && distance2 > 30){
    effect = 67;
    drv.go();
  }  
  if(distance2 < 30 && distance2 > 20){
    effect = 66;
    drv.go();
  }
  if(distance2 < 20 && distance2 > 10){
    effect = 65;
    drv.go();
  }
  if(distance2 < 10){
    effect = 64;
    drv.go();
  }
*/
}
