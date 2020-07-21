int pin[] = {7, 8, 9, 10};
int noOfPins = 4;
int len;
String s;

void setup()
{
  // put your setup code here, to run once:
  for (int i = 0; i < noOfPins; i++)
  {
    pinMode(pin[i], OUTPUT);
  }
  Serial.begin(9600);

  Serial.print("Enter Your Name: ");
  while (Serial.available() == 0);

  s = Serial.readString(); // read string
  Serial.println(s); // print the string read
  len = charCount(s); // count characters
  
  Serial.print("Leds blinking ");
  Serial.print(len);
  Serial.println(" times.");
  
  blink(len); // call blink function
}

// blinking function
void blink(int len)
{
  for (int i = 0; i < len; i++)
  {
    // turn on leds
    for (int j = 0; j < noOfPins; j++)
    {
      digitalWrite(pin[j], HIGH);
    }
    
    delay(500);
    
    // turn off leds
    for (int j = 0; j < noOfPins; j++)
    {
      digitalWrite(pin[j], LOW);
    }
    
    delay(500);
  }
}

// character count function
int charCount(String s)
{
  int count = 0;
  char c;

  // iterating over string
  for (int i = 0; i < s.length() - 1; i++)
  {
    c = s.charAt(i); // get character
    if (c != ' ' )
    {
      count++;
    }
  }
  return count;
}

void loop()
{
  // put your main code here, to run repeatedly:
}
