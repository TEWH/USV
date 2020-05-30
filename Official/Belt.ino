#include <Wire.h>
#include "Adafruit_DRV2605.h"
#define TCAADDR 0x70
Adafruit_DRV2605 drv1;
Adafruit_DRV2605 drv2;
Adafruit_DRV2605 drv3;
Adafruit_DRV2605 drv0;

const int trigPin3 = 9;
const int echoPin3 = 10;
float durationLeft, distanceLeft, dL;
int lim;
float leftArray[20] = {};

const int trigPin4 = 11;
const int echoPin4 = 12;
float durationRight, distanceRight, dR;
float rightArray[20] = {};


void tcaselect(uint8_t i) {
  if (i > 7) return;
 
  Wire.beginTransmission(TCAADDR);
  Wire.write(1 << i);
  Wire.endTransmission();  
}

int LR = 0;


float readLeft(){
  digitalWrite(trigPin3, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin3, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin3, LOW);   
  durationLeft = pulseIn(echoPin3, HIGH);
  dL = (durationLeft*.0343)/2;
  return dL;
}

float readRight(){
  digitalWrite(trigPin4, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin4, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin4, LOW);   
  durationRight = pulseIn(echoPin4, HIGH);
  dR = (durationRight*.0343)/2;
  return dR;
}

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

  //************Calibration to ground approx. 5 seconds***************
  for (int k = 0; k < 20; k++){
    leftArray[k] = readLeft();
    rightArray[k] = readRight();
    delay(250);    
  }
  int sum = leftArray[0] + rightArray[0];
  for (int j = 1; j < 20; j++){
    sum = sum + leftArray[j] + rightArray[j]; 
  }
  lim = sum / 40;
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
          else if(LR >= 10 && LR < 20) {
            tcaselect(1);
            drv1.begin();
            drv1.setWaveform(0, 65);
            drv1.setWaveform(1,0);
            drv1.go();
        }
          else if(LR >= 20 && LR < 40) {
            tcaselect(1);
            drv1.begin();
            drv1.setWaveform(0, 66);
            drv1.setWaveform(1,0);
            drv1.go();
        }
          else if(LR >= 40 && LR < 80) {
            tcaselect(1);
            drv1.begin();
            drv1.setWaveform(0, 67);
            drv1.setWaveform(1,0);
            drv1.go();
        }
          else if(LR >= 80 && LR < 140) {
            tcaselect(1);
            drv1.begin();
            drv1.setWaveform(0, 68);
            drv1.setWaveform(1,0);
            drv1.go();
        }
          else if(LR >= 140 && LR < 200) {
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
          else if(LR >= 10 && LR < 20) {
            tcaselect(3);
            drv3.begin();
            drv3.setWaveform(0, 65);
            drv3.setWaveform(1,0);
            drv3.go();
        }
          else if(LR >= 20 && LR < 40) {
            tcaselect(3);
            drv3.begin();
            drv3.setWaveform(0, 66);
            drv3.setWaveform(1,0);
            drv3.go();
        }
          else if(LR >= 40 && LR < 80) {
            tcaselect(3);
            drv3.begin();
            drv3.setWaveform(0, 67);
            drv3.setWaveform(1,0);
            drv3.go();
        }
          else if(LR >= 80 && LR < 140) {
            tcaselect(3);
            drv3.begin();
            drv3.setWaveform(0, 68);
            drv3.setWaveform(1,0);
            drv3.go();
        }
          else if(LR >= 140 && LR < 200) {
            tcaselect(3);
            drv3.begin();
            drv3.setWaveform(0, 69);
            drv3.setWaveform(1,0);
            drv3.go();
        }                    
      }          
    } 

//***************For Lower Vibration Motors & Ultrasonic Sensors on Belt****************
  int interval = (lim - 10) / 5;
  distanceLeft = readLeft();
  if (distanceLeft < 10){
          tcaselect(0);
          drv0.begin();
          drv0.setWaveform(0, 58);
          drv0.setWaveform(1,0);
          drv0.go();    
  }
  else if(distanceLeft >= 10 && distanceLeft < (lim - (4*interval))) {
          tcaselect(0);
          drv0.begin();
          drv0.setWaveform(0, 59);
          drv0.setWaveform(1,0);
          drv0.go();
  }
  else if(distanceLeft >= (lim - (4*interval)) && distanceLeft < (lim - (3*interval))) {
          tcaselect(0);
          drv0.begin();
          drv0.setWaveform(0, 60);
          drv0.setWaveform(1,0);
          drv0.go();
  }
  else if(distanceLeft >= (lim - (3*interval)) && distanceLeft < (lim - (2*interval))) {
          tcaselect(0);
          drv0.begin();
          drv0.setWaveform(0, 61);
          drv0.setWaveform(1,0);
          drv0.go();
  }
  else if(distanceLeft >= (lim - (2*interval)) && distanceLeft < (lim - interval)) {
          tcaselect(0);
          drv0.begin();
          drv0.setWaveform(0, 62);
          drv0.setWaveform(1,0);
          drv0.go();
  }
  else if(distanceLeft >= (lim - interval) && distanceLeft < lim) {
          tcaselect(0);
          drv0.begin();
          drv0.setWaveform(0, 63);
          drv0.setWaveform(1,0);
          drv0.go();
  }
  
  distanceRight = readRight();
  if (distanceRight < 10){
          tcaselect(2);
          drv2.begin();
          drv2.setWaveform(0, 58);
          drv2.setWaveform(1,0);
          drv2.go();    
  }
  else if(distanceRight >= 10 && distanceRight < (lim - (4*interval))) {
          tcaselect(2);
          drv2.begin();
          drv2.setWaveform(0, 59);
          drv2.setWaveform(1,0);
          drv2.go();
  }
  else if(distanceRight >= (lim - (4*interval)) && distanceRight < (lim - (3*interval))) {
          tcaselect(2);
          drv2.begin();
          drv2.setWaveform(0, 60);
          drv2.setWaveform(1,0);
          drv2.go();
  }
  else if(distanceRight >= (lim - (3*interval)) && distanceRight < (lim - (2*interval))) {
          tcaselect(2);
          drv2.begin();
          drv2.setWaveform(0, 61);
          drv2.setWaveform(1,0);
          drv2.go();
  }
  else if(distanceRight >= (lim - (2*interval)) && distanceRight < (lim - interval)) {
          tcaselect(2);
          drv2.begin();
          drv2.setWaveform(0, 62);
          drv2.setWaveform(1,0);
          drv2.go();
  }
  else if(distanceRight >= (lim - interval) && distanceRight < lim) {
          tcaselect(2);
          drv2.begin();
          drv2.setWaveform(0, 63);
          drv2.setWaveform(1,0);
          drv2.go();
  }  
} 
