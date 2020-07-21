#include <Key.h>
#include <Keypad.h>

const byte rows = 4;
const byte cols = 4;

char keys[rows][cols] = {
                          {'1', '2', '3', 'A'},
                          {'4', '5', '6', 'B'},
                          {'7', '8', '9', 'C'},
                          {'*', '0', '#', 'D'}
                        };

byte rowPins[rows] = {6, 7, 8, 9};
byte colPins[cols] = {10, 11, 12, 13};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, rows, cols);

//char key;
int led = 2;
String amount = "";
int amt;
int iter = 0;
int amtDiv = 0;

void blink()
{
  pinMode(led, OUTPUT);
  for (int i=0; i<2; i++)
  {
    digitalWrite(led, HIGH);
    delay(200);
    digitalWrite(led, LOW);
    delay(200);
  }
}

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  blink();
  Serial.print("Enter amount: "); 
}

void loop()
{
  // put your main code here, to run repeatedly:
  char key = keypad.getKey();

  if (key != NO_KEY)
  {
    if (iter <= 4)
    {
      if (key != '#')
      {
        amount.concat(key);
//        amount[iter] = key;
//        Serial.print(amount[iter]);
        iter++;
      }
      if (key == '#')
      {
        for (int i=0; i<iter; i++)
        {
          Serial.print(amount[i]);
        }
        Serial.println();

        amt = amount.toInt();
        amtDiv = amt / 90;
      
        if (amt < 90)
        {
          Serial.println("Sorry, system cannot dispense fuel against this amount.");
        }
        else
        {
          Serial.print("You will have ");
          Serial.print(amtDiv);
          Serial.println(" Lit of fuel against this amount.");
          Serial.println("Dispensing fuel. Please wait.");
          delay(amtDiv * 1000);
        }
        Serial.println("Thank you for visiting us.");
        Serial.println("Drive Safe.");
      }
    }
  }
}
