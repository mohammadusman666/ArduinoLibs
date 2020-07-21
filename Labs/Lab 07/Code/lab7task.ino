#include "LedCounter.h"

const int noOfPins = 4;
int pins[noOfPins] = {2, 3, 4, 5}; // arduino pins
LedCounter lc(noOfPins, pins); // instance

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  lc.begin(); // put pins in OUTPUT mode
  lc.upCount(); // call upCount function
  lc.allOff(); // turn off all LEDs
  delay(2000);
  lc.downCount(); // call downCount function
  lc.allOff(); // turn off all LEDs
  delay(2000);
  lc.shiftLeft(); // call shiftLeft function
  lc.allOff(); // turn off all LEDs
  delay(2000);
  lc.shiftRight(); // call shiftRight function
  lc.allOff(); // turn off all LEDs
}

void loop()
{
  // put your main code here, to run repeatedly:
}
