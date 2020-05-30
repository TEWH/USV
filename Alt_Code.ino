// CHANGE TCASESELECT, WIRE.BEGIN
#include <Wire.h>
#include "Adafruit_DRV2605.h"
#define TCAADDR 0x70
Adafruit_DRV2605 drv1;
Adafruit_DRV2605 drv3;

const int trigPin1 = 9;
const int echoPin1 = 10;
const int trigPin2 = 11;
const int echoPin2= 12;
float duration1, duration2;
int distance1, distance2;

void tcaselect(uint8_t i) {
  if (i > 7) return;
  Wire.beginTransmission(TCAADDR);
  Wire.write(1 << i);
  Wire.endTransmission();  
}

void setup() {
  Serial.begin(38400);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  drv1.begin();
  drv3.begin();

  drv1.selectLibrary(1);
  drv3.selectLibrary(1);
  
  drv1.setMode(DRV2605_MODE_INTTRIG);
  drv3.setMode(DRV2605_MODE_INTTRIG);

  tcaselect(1);
  Wire.begin(1);
  tcaselect(2);
  Wire.begin(2);   
}

void loop() {
  
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  duration1 = pulseIn(echoPin1, HIGH);
  distance1 = (duration1*.0343)/2;
  
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  duration2 = pulseIn(echoPin2, HIGH);
  distance2 = (duration2*.0343)/2;

  if(distance1 < 10) {
    tcaselect(1);
    drv1.begin();
    drv1.setWaveform(0, 64);
    drv1.setWaveform(1,0);
    drv1.go();
  }
  else if(distance1 >= 10 && distance1 < 20) {
    tcaselect(1);
    drv1.begin();
    drv1.setWaveform(0, 65);
    drv1.setWaveform(1,0);
    drv1.go();
  }
  else if(distance1 >= 20 && distance1 < 40) {
    tcaselect(1);
    drv1.begin();
    drv1.setWaveform(0, 66);
    drv1.setWaveform(1,0);
    drv1.go();
  }
  else if(distance1 >= 40 && distance1 < 80) {
    tcaselect(1);
    drv1.begin();
    drv1.setWaveform(0, 67);
    drv1.setWaveform(1,0);
    drv1.go();
  }
  else if(distance1 >= 80 && distance1 < 140) {
    tcaselect(1);
    drv1.begin();
    drv1.setWaveform(0, 68);
    drv1.setWaveform(1,0);
    drv1.go();
  }
  else if(distance2 >= 140 && distance1 < 200) {
    tcaselect(1);
    drv1.begin();
    drv1.setWaveform(0, 69);
    drv1.setWaveform(1,0);
    drv1.go();
  }        

  else if(distance2 < 10) {
    tcaselect(3);
    drv3.begin();
    drv3.setWaveform(0, 64);
    drv3.setWaveform(1,0);
    drv3.go();
  }
  else if(distance2 >= 10 && distance2 < 30) {
    tcaselect(3);
    drv3.begin();
    drv3.setWaveform(0, 65);
    drv3.setWaveform(1,0);
    drv3.go();
  }
  else if(distance2 >= 30 && distance2 < 60) {
    tcaselect(3);
    drv3.begin();
    drv3.setWaveform(0, 66);
    drv3.setWaveform(1,0);
    drv3.go();
  }
  else if(distance2 >= 60 && distance2 < 100) {
    tcaselect(3);
    drv3.begin();
    drv3.setWaveform(0, 67);
    drv3.setWaveform(1,0);
    drv3.go();
  }
  else if(distance2 >= 100 && distance2 < 150) {
    tcaselect(3);
    drv3.begin();
    drv3.setWaveform(0, 68);
    drv3.setWaveform(1,0);
    drv3.go();
  }
  else if(distance2 >= 150 && distance2 < 200) {
    tcaselect(3);
    drv3.begin();
    drv3.setWaveform(0, 69);
    drv3.setWaveform(1,0);
    drv3.go();
  }
                      
}
