#include <Arduino.h>

class LedCounter
{
  public:
    LedCounter(int noOfLeds, int pins[]);
    void begin();
    void upCount();
    void downCount();
    void shiftLeft();
    void shiftRight();
    void allOff();

  private:
    int _noOfLeds; // number of leds
    int _pins[12]; // max pins
    int _length; // redundant
};
