char c; // used for clearing the buffer (Serial.available)

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.setTimeout(5000);

  // getting array size
  Serial.print("Enter Array size: ");
  while (Serial.available() == 0);
  int sz = Serial.parseInt( );
  Serial.print(sz);
  Serial.println();

  // initializing array
  int arr[sz];
  int i = 0;
  Serial.print("Initializing array ");
  while (i < sz)
  {
    Serial.print(".");
    arr[i] = 0;
    i++;
    delay(1000);
  }
  Serial.println();
  Serial.println("Array has been initialized Successfully.");

  // getting values for array
  Serial.println("Enter Values in the array: ");
  i = 0;
  while (i < sz)
  {
    Serial.print("arr[");
    Serial.print(i);
    Serial.print("] = ");
    
    c = Serial.read();
    while (Serial.available() == 0);

    arr[i] = Serial.parseInt();
    Serial.print(arr[i]);
    Serial.println();
    i++;
  }

  // displaying values the user entered
  Serial.println("You have Entered:");
  i = 0;
  while (i < sz)
  {
    Serial.print(arr[i]);
    Serial.print(" ");
    i++;
  }
}

void loop()
{
  // put your main code here, to run repeatedly:
}
