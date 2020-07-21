// Pin Numbers for segment LEDs
#define A 2
#define B 3
#define C 4
#define D 5
#define E 6
#define F 7
#define G 8

const int segs[7] = {A, B, C, D, E, F, G};
const byte digits[10] = {0b1000000, 0b1111010, 0b0100100, 0b0110000, 0b0011010, 0b0010001, 0b0000001, 0b1111000, 0b0000000, 0b0010000};

bool isButtonPressed = false;
int counter = 0;   // counter for the number of button presses
int incState = 0;         // current state of the inc. button
int prevIncState = 0;     // previous state of the inc. button
int decState = 0;         // current state of the dec. button
int prevDecState = 0;     // previous state of the dec. button

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  // initialize pin modes
  for (int i = 0; i < 7; i++)
  {
    pinMode(segs[i], OUTPUT);
  }
  showDigit(digits[0]);
  pinMode(12, INPUT_PULLUP); // decrement
  pinMode(13, INPUT_PULLUP); // increment
}

void loop()
{
  incState = digitalRead(13); // read from pin 13
  decState = digitalRead(12); // read from pin 12

  incButton(); // check conditions for pin 13
  decButton(); // check conditions for pin 12

  if(isButtonPressed) // if a button is pressed, that means counter must have updated
  {
     showDigit(digits[counter]); // show counter
  }
}

// switches on LEDs of 7 segment
void showDigit(byte digit)
{
  for (int i = 0; i < 7; i++)
  {
    int bit = bitRead(digit, i); // read a single bit
    digitalWrite(segs[i], bit); // switch on a particular LED of 7 segment
  }
}

// checks conditions for increment button
void incButton()
{
  // compare the incState to its previous state
  if (incState != prevIncState)
  {
    // if the state has changed, increment the counter
    if (incState)
    {
      isButtonPressed = true;
      counter++;
      if(counter > 9)
        counter = 0;
      Serial.println("Increment - on");
    }
    else
    {
      Serial.println("Increment - off");
    }
    // Delay a little bit to avoid bouncing
    delay(50);
  }
  // save the current state as the prev state, for next time through the loop
  prevIncState = incState;
}

// checks conditions for decrement button
void decButton()
{
  // compare the decState to its previous state
  if (decState != prevDecState)
  {
    // if the state has changed, decrement the counter
    if (decState)
    {
      isButtonPressed = true;
      counter--;
      if(counter < 0)
        counter = 9;
      Serial.println("Decrement - on");
    }
    else
    {
      Serial.println("Decrement - off");
    }
    // Delay a little bit to avoid bouncing
    delay(50);
  }
  // save the current state as the prev state, for next time through the loop
  prevDecState = decState;
}
