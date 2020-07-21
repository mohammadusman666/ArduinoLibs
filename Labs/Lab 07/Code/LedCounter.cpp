#include "LedCounter.h"

LedCounter :: LedCounter(int noOfLeds, int pins[])
{
  _length = noOfLeds;
  _noOfLeds = noOfLeds;
  for (int i = 0; i < _length; i++)
  {
    _pins[i] = pins[i];
  }
}

void LedCounter :: begin()
{
  for (int i = 0; i < _length; i++)
  {
    pinMode(_pins[i], OUTPUT);
    Serial.print("Pin: ");
    Serial.println(_pins[i]);
  }
}

void LedCounter :: upCount()
{
  for (int n = 0; n < pow(2, _length); n++)
  {
    for (int i = 0; i < _length; i++)
    {
      if (bitRead(n, i) == 1)
      {
        digitalWrite(_pins[i], HIGH);
      }
      else
      {
        digitalWrite(_pins[i], LOW);
      }
    }
    delay(500);
  }
}

void LedCounter :: downCount()
{
  for (int n = pow(2, _length); n >= 0; n--)
  {
    for (int i = 0; i < _length; i++)
    {
      if (bitRead(n, i) == 1)
      {
        digitalWrite(_pins[i], HIGH);
      }
      else
      {
        digitalWrite(_pins[i], LOW);
      }
    }
    delay(500);
  }
}

void LedCounter :: shiftLeft()
{
  // turn on leds
  for (int j = 0; j < _length; j++)
  {
    digitalWrite(_pins[j], HIGH);
    delay(500);
  }

  delay(500);

  // turn off leds
  for (int j = 0; j < _length; j++)
  {
    digitalWrite(_pins[j], LOW);
    delay(500);
  }
}

void LedCounter :: shiftRight()
{
  // turn on leds
  for (int j = _length - 1; j >= 0; j--)
  {
    digitalWrite(_pins[j], HIGH);
    delay(500);
  }

  delay(500);

  // turn off leds
  for (int j = _length - 1; j >= 0; j--)
  {
    digitalWrite(_pins[j], LOW);
    delay(500);
  }
}

void LedCounter :: allOff()
{
  for (int i = 0; i < _length; i++)
  {
    digitalWrite(_pins[i], LOW);
  }
}
