const int led = 3;        // the pin that the LED is atteched to

int state = LOW;          // by default, no motion detected
const int pir = 2;        // the pin that the pir sensor is atteched to
int pirVal = 0;           // variable to store the pir sensor value

const int ldr = 0;        // the pin that ldr is attached to
int ldrVal = 0;           // variable to store the ldr value

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);     // initialize serial
  pinMode(led, OUTPUT);   // initalize LED as an output
  pinMode(pir, INPUT);    // initialize sensor as an input
  pinMode(ldr, INPUT);    // initialize ldr as an input
}

void loop()
{
  // put your main code here, to run repeatedly:
  pirVal = digitalRead(pir); // read sensor value
  
  ldrVal = analogRead(ldr);
  Serial.print("LDR: ");
  Serial.println(ldrVal);
  
  if (pirVal == HIGH && ldrVal < 100) // check if the sensor is HIGH
  {
    if (state == LOW) // previously no motion was detected
    {
      Serial.println("Motion detected!");
      state = HIGH; // update variable state to HIGH

      digitalWrite(led, HIGH); // turn LED ON
      func(); // call func which detects for further motion while LED is on
      digitalWrite(led, LOW); // turn LED OFF
    }
  }
  else
  {
    digitalWrite(led, LOW); // turn LED OFF

    if (state == HIGH) // previously motion was detected
    {
      Serial.println("Motion stopped!");
      state = LOW; // update variable state to LOW
    }
  }
}

void func()
{
  unsigned long starttime = millis();
  unsigned long endtime = starttime;
  unsigned long delaytime = 30000;
  int count = 0;
  
  while ((endtime - starttime) <= delaytime) // do this loop for up to 1000mS
  {
    pirVal = digitalRead(pir); // read sensor value
    if (pirVal == HIGH)
    {
      if (state == LOW) // previously no motion was detected
      {
        if (count < 1)
        {
          delaytime += 30000;
          Serial.println("Motion detected again! 30 secs increased");
          count += 1;
        }
        state = HIGH; // update variable state to HIGH
      }
    }
    else
    {
      if (state == HIGH) // previously motion was detected
      {
        Serial.println("Motion stopped!");
        state = LOW; // update variable state to LOW
      }
    }
    
    endtime = millis();
  }
}
