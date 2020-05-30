#include <Wire.h>
#include "Adafruit_DRV2605.h"
#define TCAADDR 0x70
Adafruit_DRV2605 drv1;
Adafruit_DRV2605 drv2;
Adafruit_DRV2605 drv3;
Adafruit_DRV2605 drv0;

const int trigPin3 = 9;
const int echoPin3 = 10;
float durationLeft, distanceLeft;

const int trigPin4 = 11;
const int echoPin4 = 12;
float durationRight, distanceRight;

void tcaselect(uint8_t i) {
  if (i > 7) return;
 
  Wire.beginTransmission(TCAADDR);
  Wire.write(1 << i);
  Wire.endTransmission();  
}

int leftValue, rightValue, LR = 0;
void setup() {
  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);

  pinMode(trigPin4, OUTPUT);
  pinMode(echoPin4, INPUT);
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
//******************For Upper Vibration Motors*****************
  if(Serial.available() > 0) { //Detected message from master
      LR = Serial.read();
      Serial.println(LR);
      if (LR%2 == 1){
        //Serial.println(LR);
          if(LR < 10) {
            tcaselect(1);
            drv1.begin();
            drv1.setWaveform(0, 64);
            drv1.setWaveform(1,0);
            drv1.go();
        }
          else if(LR >= 10 && LR < 30) {
            tcaselect(1);
            drv1.begin();
            drv1.setWaveform(0, 65);
            drv1.setWaveform(1,0);
            drv1.go();
        }
          else if(LR >= 30 && LR < 50) {
            tcaselect(1);
            drv1.begin();
            drv1.setWaveform(0, 66);
            drv1.setWaveform(1,0);
            drv1.go();
        }
          else if(LR >= 50 && LR < 70) {
            tcaselect(1);
            drv1.begin();
            drv1.setWaveform(0, 67);
            drv1.setWaveform(1,0);
            drv1.go();
        }
          else if(LR >= 70 && LR < 90) {
            tcaselect(1);
            drv1.begin();
            drv1.setWaveform(0, 68);
            drv1.setWaveform(1,0);
            drv1.go();
        }
          else if(LR >= 90 && LR < 110) {
            tcaselect(1);
            drv1.begin();
            drv1.setWaveform(0, 69);
            drv1.setWaveform(1,0);
            drv1.go();
        }        
      }
      else{
        //Serial.println(LR);
        //Serial.print("Right:");
          if(LR < 10) {
            tcaselect(3);
            drv3.begin();
            drv3.setWaveform(0, 64);
            drv3.setWaveform(1,0);
            drv3.go();
        }
          else if(LR >= 10 && LR < 30) {
            tcaselect(3);
            drv3.begin();
            drv3.setWaveform(0, 65);
            drv3.setWaveform(1,0);
            drv3.go();
        }
          else if(LR >= 30 && LR < 50) {
            tcaselect(3);
            drv3.begin();
            drv3.setWaveform(0, 66);
            drv3.setWaveform(1,0);
            drv3.go();
        }
          else if(LR >= 50 && LR < 70) {
            tcaselect(3);
            drv3.begin();
            drv3.setWaveform(0, 67);
            drv3.setWaveform(1,0);
            drv3.go();
        }
          else if(LR >= 70 && LR < 90) {
            tcaselect(3);
            drv3.begin();
            drv3.setWaveform(0, 68);
            drv3.setWaveform(1,0);
            drv3.go();
        }
          else if(LR >= 90 && LR < 110) {
            tcaselect(3);
            drv3.begin();
            drv3.setWaveform(0, 69);
            drv3.setWaveform(1,0);
            drv3.go();
        }                    
      }          
    } 

//***************For Lower Vibration Motors & Ultrasonic Sensors on Belt****************
  digitalWrite(trigPin3, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin3, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin3, LOW);   
  durationLeft = pulseIn(echoPin3, HIGH);
  distanceLeft = (durationLeft*.0343)/2;
  if (distanceLeft < 10){
          tcaselect(0);
          drv0.begin();
          drv0.setWaveform(0, 58);
          drv0.setWaveform(1,0);
          drv0.go();    
  }
  else if(distanceLeft >= 10 && distanceLeft < 30) {
          tcaselect(0);
          drv0.begin();
          drv0.setWaveform(0, 59);
          drv0.setWaveform(1,0);
          drv0.go();
  }
  else if(distanceLeft >= 30 && distanceLeft < 50) {
          tcaselect(0);
          drv0.begin();
          drv0.setWaveform(0, 60);
          drv0.setWaveform(1,0);
          drv0.go();
  }
  else if(distanceLeft >= 50 && distanceLeft < 70) {
          tcaselect(0);
          drv0.begin();
          drv0.setWaveform(0, 61);
          drv0.setWaveform(1,0);
          drv0.go();
  }
  else if(distanceLeft >= 70 && distanceLeft < 90) {
          tcaselect(0);
          drv0.begin();
          drv0.setWaveform(0, 62);
          drv0.setWaveform(1,0);
          drv0.go();
  }
  else if(distanceLeft >= 90 && distanceLeft < 110) {
          tcaselect(0);
          drv0.begin();
          drv0.setWaveform(0, 63);
          drv0.setWaveform(1,0);
          drv0.go();
  }
  
  digitalWrite(trigPin4, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin4, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin4, LOW);   
  durationRight = pulseIn(echoPin4, HIGH);
  distanceRight = (durationRight*.0343)/2;
  if (distanceRight < 10){
          tcaselect(2);
          drv2.begin();
          drv2.setWaveform(0, 58);
          drv2.setWaveform(1,0);
          drv2.go();    
  }
  else if(distanceRight >= 10 && distanceRight < 30) {
          tcaselect(2);
          drv2.begin();
          drv2.setWaveform(0, 59);
          drv2.setWaveform(1,0);
          drv2.go();
  }
  else if(distanceRight >= 30 && distanceRight < 50) {
          tcaselect(2);
          drv2.begin();
          drv2.setWaveform(0, 60);
          drv2.setWaveform(1,0);
          drv2.go();
  }
  else if(distanceRight >= 50 && distanceRight < 70) {
          tcaselect(2);
          drv2.begin();
          drv2.setWaveform(0, 61);
          drv2.setWaveform(1,0);
          drv2.go();
  }
  else if(distanceRight >= 70 && distanceRight < 90) {
          tcaselect(2);
          drv2.begin();
          drv2.setWaveform(0, 62);
          drv2.setWaveform(1,0);
          drv2.go();
  }
  else if(distanceRight >= 90 && distanceRight < 110) {
          tcaselect(2);
          drv2.begin();
          drv2.setWaveform(0, 63);
          drv2.setWaveform(1,0);
          drv2.go();
  }  
} 
