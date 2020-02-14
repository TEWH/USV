#include <Wire.h>
#include "Adafruit_DRV2605.h"
#define TCAADDR 0x70

Adafruit_DRV2605 drv1;
Adafruit_DRV2605 drv2;
Adafruit_DRV2605 drv3;
Adafruit_DRV2605 drv0;

void tcaselect(uint8_t i) {
  if (i > 7) return;
 
  Wire.beginTransmission(TCAADDR);
  Wire.write(1 << i);
  Wire.endTransmission();  
}

void setup(void) 
{
  //Serial.begin(9600);
  drv1.begin();
  drv2.begin();
  drv3.begin();
  drv0.begin();

  /*
  if(!drv3.begin())
  {
    Serial.println("Ooops, no DRV detected ... Check your wiring!");
    while(1);
  }
  */
  drv1.selectLibrary(1);
  drv1.setMode(DRV2605_MODE_INTTRIG);
   
  drv2.selectLibrary(1);
  drv2.setMode(DRV2605_MODE_INTTRIG);
   
  drv3.selectLibrary(1);
  drv3.setMode(DRV2605_MODE_INTTRIG);
   
  drv0.selectLibrary(1);
  drv0.setMode(DRV2605_MODE_INTTRIG); 
}
void loop(void) 
{


  tcaselect(1);
  drv1.setWaveform(0, 64);
  drv1.setWaveform(1,0);
  drv1.go();

  tcaselect(2);
  drv2.setWaveform(0, 64);
  drv2.setWaveform(1,0);
  drv2.go();

  tcaselect(3);
  drv3.setWaveform(0, 64);
  drv3.setWaveform(1,0);
  drv3.go();

  tcaselect(0);
  drv0.setWaveform(0, 65);
  drv0.setWaveform(1,0);
  drv0.go();



}
