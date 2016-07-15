/*
TrinketKeyboard example
For Trinket by Adafruit Industries
*/

#include "TrinketHidCombo.h"

#define PIR_IN 0
#define LED 1

int pirState = 0;        
int lastPirState = 0; 

void setup()
{
  // button pins as inputs
  pinMode(PIR_IN, INPUT);
  digitalWrite(PIR_IN, HIGH);
  pinMode(LED, OUTPUT);

  TrinketHidCombo.begin(); // start the USB device engine and enumerate
}

void loop()
{
  TrinketHidCombo.poll(); // do nothing, check if USB needs anything done

  pirState = digitalRead(PIR_IN);
  if (pirState != lastPirState)
  {
    lastPirState = pirState;
    if (pirState == LOW)
    {
       digitalWrite(LED, LOW);
       TrinketHidCombo.pressMultimediaKey(MMKEY_STOP); 
    }
    else 
    {
       digitalWrite(LED, HIGH);      
       TrinketHidCombo.pressMultimediaKey(MMKEY_PLAYPAUSE);
    }   
  }
}
