int pin[] = {7, 8, 9, 10};
int noOfPins = 4;
int noOfBlinks = 3;

void setup()
{
  // put your setup code here, to run once:
  for (int i = 0; i < noOfPins ; i++)
  {
    pinMode(pin[i], OUTPUT);
  }
  Serial.begin(9600);
}

// blinking function
void blink()
{
  for (int i = 0; i < noOfBlinks; i++)
  {
    // turn off leds
    for (int j = 0; j < noOfPins; j++)
    {
      digitalWrite(pin[j], LOW);
    }
    
    delay(500);
    
    // turn on leds
    for (int j = 0; j < noOfPins; j++)
    {
      digitalWrite(pin[j], HIGH);
    }
    
    delay(500);
  }
}

void loop()
{
  // put your main code here, to run repeatedly:
  // chasing sequence
  for (int i = 0; i < noOfPins; i++)
  {
    digitalWrite(pin[i], HIGH);
    delay(500);
  }

  // blinking function
  blink();

  // reverse chasing sequence
  for (int i = (noOfPins - 1); i >= 0 ; i--)
  {
    digitalWrite(pin[i], LOW);
    delay(500);
  }
  
  delay(500);
}
