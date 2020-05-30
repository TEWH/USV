// CHANGE TCASESELECT, WIRE.BEGIN
#include <Wire.h>
#include "Adafruit_DRV2605.h"
Adafruit_DRV2605 drv1;

const int trigPin1 = 9;
const int echoPin1 = 8;
float duration1;
int distance1;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  drv1.begin();

  drv1.selectLibrary(1);
  
  drv1.setMode(DRV2605_MODE_INTTRIG);

}

void loop() {
  
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  duration1 = pulseIn(echoPin1, HIGH);
  distance1 = (duration1*.0343)/2;
  Serial.println(distance1);
  
  if(distance1 < 10) {
    drv1.begin();
    drv1.setWaveform(0, 64);
    drv1.setWaveform(1,0);
    drv1.go();
  }
  else if(distance1 >= 10 && distance1 < 20) {
    drv1.begin();
    drv1.setWaveform(0, 65);
    drv1.setWaveform(1,0);
    drv1.go();
  }
  else if(distance1 >= 20 && distance1 < 40) {
    drv1.begin();
    drv1.setWaveform(0, 66);
    drv1.setWaveform(1,0);
    drv1.go();
  }
  else if(distance1 >= 40 && distance1 < 80) {
    drv1.begin();
    drv1.setWaveform(0, 67);
    drv1.setWaveform(1,0);
    drv1.go();
  }
  else if(distance1 >= 80 && distance1 < 140) {
    drv1.begin();
    drv1.setWaveform(0, 68);
    drv1.setWaveform(1,0);
    drv1.go();
  }
  else if(distance1 >= 140 && distance1 < 200) {
    drv1.begin();
    drv1.setWaveform(0, 69);
    drv1.setWaveform(1,0);
    drv1.go();
  }        
                      
}
