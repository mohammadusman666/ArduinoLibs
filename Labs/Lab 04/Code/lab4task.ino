// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int sensor = A0; // Assigning analog pin A5 to variable 'sensor'
float tempc; // variable to store temperature in degree Celsius
float vout; // temporary variable to hold sensor reading

const int led = 10;
const int ten = 9;
const int unit = 8;
const int submit = 6;

bool isUnitButtonPressed = false;
bool isTenButtonPressed = false;
bool isSubmitButtonPressed = false;

int unitCounter = 0;   // counter for unit
int tenCounter = 0;   // counter for ten

int incUnitState = 0;         // current state of the inc. unit button
int prevIncUnitState = 0;     // previous state of the inc. unit button
int incTenState = 0;         // current state of the inc. ten button
int prevIncTenState = 0;     // previous state of the inc. ten button
int submitState = 0;         // current state of the submit button
int prevSubmitState = 0;     // previous state of the submit button

void setup()
{
  Serial.begin(9600);

  pinMode(unit, INPUT); // inc. unit button
  pinMode(ten, INPUT); // inc. ten button
  pinMode(submit, INPUT); // submit button
  pinMode(led, OUTPUT); // LED

  // set up the LCD's number of columns and rows:
  delay(500);
  lcd.begin(20, 4);
  delay(500);
  lcd.clear();
  delay(500);
  lcd.print("Enter: ");

  lcd.setCursor(7, 0);
  lcd.print(tenCounter);
  lcd.setCursor(8, 0);
  lcd.print(unitCounter);
  lcd.blink();
}

void loop()
{
  incUnitState = digitalRead(unit); // read
  incTenState = digitalRead(ten); // read
  submitState = digitalRead(submit); // read

  incUnitButton(); // check unit button
  incTenButton(); // check ten button
  checkSubmitButton(); // check submit button

  if (isSubmitButtonPressed)
  {
    String unitStr = String(unitCounter);
    String tenStr = String(tenCounter);

    tenStr.concat(unitStr);
    int number = tenStr.toInt();

    Serial.print("Entered Temp: ");
    Serial.println(number);

    if (number >= 20 && number <= 80)
    {
      vout = analogRead(sensor); //Reading the value from sensor
      vout = (vout * 500) / 1023; // convert voltage to temp.
      tempc = vout; // Storing value in Degree Celsius

      lcd.setCursor(0, 1);
      lcd.print(tempc);
      Serial.print("Read Temp: ");
      Serial.println(tempc);

      if (tempc < number)
      {
        digitalWrite(led, HIGH);
        Serial.println("LED - on");
      }
      else
      {
        digitalWrite(led, LOW);
        Serial.println("LED - off");
      }
    }
    else
    {
      Serial.println("Value Range Error!");
    }
  }
}

// checks conditions for submit button
void checkSubmitButton()
{
  // compare the incState to its previous state
  if (submitState != prevSubmitState)
  {
    // if the state has changed, increment the counter
    if (submitState)
    {
      isSubmitButtonPressed = true;
      Serial.println("Submit - on");
    }
    else
    {
      Serial.println("Submit - off");
    }
    // Delay a little bit to avoid bouncing
    delay(50);
  }
  // save the current state as the prev state, for next time through the loop
  prevSubmitState = submitState;
}

// checks conditions for unit button
void incUnitButton()
{
  // compare to its previous state
  if (incUnitState != prevIncUnitState)
  {
    // if the state has changed
    if (incUnitState)
    {
      //      isUnitButtonPressed = true;
      unitCounter++;
      if (unitCounter > 9)
        unitCounter = 0;
      Serial.print("Unit Increment - on - ");
      Serial.println(unitCounter);
      lcd.setCursor(8, 0);
      lcd.print(unitCounter);
    }
    else
    {
      Serial.println("Unit Increment - off");
    }
    // Delay a little bit to avoid bouncing
    delay(50);
  }
  // save the current state as the prev state, for next time through the loop
  prevIncUnitState = incUnitState;
}

// checks conditions for ten button
void incTenButton()
{
  // compare to its previous state
  if (incTenState != prevIncTenState)
  {
    // if the state has changed
    if (incTenState)
    {
      //      isTenButtonPressed = true;
      tenCounter++;
      if (tenCounter > 9)
        tenCounter = 0;
      Serial.print("Ten Increment - on - ");
      Serial.println(tenCounter);
      lcd.setCursor(7, 0);
      lcd.print(tenCounter);
    }
    else
    {
      Serial.println("Ten Increment - off");
    }
    // Delay a little bit to avoid bouncing
    delay(50);
  }
  // save the current state as the prev state, for next time through the loop
  prevIncTenState = incTenState;
}
