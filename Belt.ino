#include <Wire.h>
#include "Adafruit_DRV2605.h"
#define TCAADDR 0x70
Adafruit_DRV2605 drv1;
Adafruit_DRV2605 drv2;
Adafruit_DRV2605 drv3;
Adafruit_DRV2605 drv0;


const int trigPin1 = 9;
const int echoPin1 = 10;
float duration1, distance1;

const int trigPin2 = 11;
const int echoPin2 = 12;
float duration2, distance2;

void tcaselect(uint8_t i) {
  if (i > 7) return;
 
  Wire.beginTransmission(TCAADDR);
  Wire.write(1 << i);
  Wire.endTransmission();  
}

#define ledPin 7
//uint8_t effect = 1;
int leftFlag, leftValue, rightValue = 0;
int rightFlag = 1;
void setup() {
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);

  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  drv1.begin();
  drv2.begin();
  drv3.begin();
  drv0.begin();
  
  Serial.begin(38400);
  
  
  drv1.selectLibrary(1);
  drv2.selectLibrary(1);
  drv3.selectLibrary(1);
  drv0.selectLibrary(1);

  drv1.setMode(DRV2605_MODE_INTTRIG);
  drv2.setMode(DRV2605_MODE_INTTRIG);
  drv3.setMode(DRV2605_MODE_INTTRIG);
  drv0.setMode(DRV2605_MODE_INTTRIG); 
   
  tcaselect(1);
  Wire.begin(1);
  tcaselect(2);
  Wire.begin(2);
  tcaselect(3);
  Wire.begin(3);
  tcaselect(0);
  Wire.begin(0);
}
void loop() {
  if(Serial.available() > 0) { //Detected message from master
    //Serial.println("Test");
    if(leftFlag == 0 && rightFlag == 1) {
      leftValue = Serial.read();
      if(leftValue < 30) {
          tcaselect(3);
          drv3.begin();
          drv3.setWaveform(0, 64);
          drv3.setWaveform(1,0);
          drv3.go();
      }
      
      else if(leftValue > 30) {
          tcaselect(3);
          drv3.begin();
          drv3.setWaveform(0, 68);
          drv3.setWaveform(1,0);
          drv3.go();
      }
      
      Serial.print("Read left value: ");
      Serial.println(leftValue);
      leftFlag = 1;
      rightFlag = 0;
    }
    else if(rightFlag == 0 && leftFlag == 1) {
      rightValue = Serial.read();
      if(rightValue < 30) {
          tcaselect(1);
          drv1.begin();
          drv1.setWaveform(0, 64);
          drv1.setWaveform(1,0);
          drv1.go();
      }
      
      else if(rightValue > 30) {
          tcaselect(1);
          drv1.begin();
          drv1.setWaveform(0, 68);
          drv1.setWaveform(1,0);
          drv1.go();
      }

      
      Serial.print("Read right value: ");
      Serial.println(rightValue);
      leftFlag = 0;
      rightFlag = 1;    
    } 
  }
}
/*
    
  }

  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);   
  duration1 = pulseIn(echoPin1, HIGH);
  distance1 = (duration1*.0343)/2;

  if (distance1 < 20){
          tcaselect(0);
          drv0.begin();
          drv0.setWaveform(0, 64);
          drv0.setWaveform(1,0);
          drv0.go();    
    //delayMicroseconds(500);
    //delayMicroseconds(4000);
  }
  else if(distance1 > 20) {
          tcaselect(0);
          drv0.begin();
          drv0.setWaveform(0, 68);
          drv0.setWaveform(1,0);
          drv0.go();
  }
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);   
  duration2 = pulseIn(echoPin2, HIGH);
  distance2 = (duration2*.0343)/2;

  if (distance2 < 20){
          tcaselect(2);
          drv2.begin();
          drv2.setWaveform(0, 64);
          drv2.setWaveform(1,0);
          drv2.go();    
    //delayMicroseconds(500);
    //delayMicroseconds(4000);
  }
  else if(distance2 > 20) {
          tcaselect(2);
          drv2.begin();
          drv2.setWaveform(0, 68);
          drv2.setWaveform(1,0);
          drv2.go();
  }

} 
*/
