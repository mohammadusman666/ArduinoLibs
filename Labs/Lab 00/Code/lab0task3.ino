int sz;
char c;
int *arr;

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  sz = get_size(); // get size of array from use
  init_array(sz); // initialize array
  populate_array(arr, sz); // insert elements in array
  display_array(arr, sz); // display elements of array
  Serial.println();
  display_revarray(arr, sz);  // display elements in reverse order
}

void loop()
{
  // put your main code here, to run repeatedly:
}

// function to get array size from user
int get_size()
{
  Serial.print("Enter Array size: ");
  while (Serial.available() == 0);
  int sz = Serial.parseInt();
  Serial.print(sz);
  Serial.println();
  return sz;
}
// function to initialize array with 0
void init_array(int siz)
{
  arr = (int *)malloc(sizeof(int) * sz);
  int i = 0;
  Serial.print("Initializing array ");
  while (i < siz)
  {
    Serial.print(".");
    arr[i] = 0;
    i++;
    delay(1000);
  }
  Serial.println();
  Serial.println("Array has been initialized Successfully.");
}
// function to get elements from user and insert in array
void populate_array(int arr[], int siz)
{
  Serial.println("Enter Values in the array: ");
  int i = 0;
  while (i < siz)
  {
    Serial.print("arr[");
    Serial.print(i);
    Serial.print("] = ");
    c = Serial.read();
    while (Serial.available() == 0);

    arr[i] = Serial.parseInt();
    Serial.print(arr[i]);
    i++;
    Serial.println();
  }
}
// function to display elements of array
void display_array(int arr[] , int siz)
{
  Serial.println("Array contents are:");
  int i = 0;
  while (i < siz)
  {
    Serial.print(arr[i]);
    Serial.print(" ");
    i++;
  }
}
// function to display elements of array in reverse order
void display_revarray(int arr[] , int siz)
{
  int i = 0;
  Serial.print("Initializing array ");
  while (i < siz)
  {
    Serial.print(".");
    i++;
    delay(1000);
  }
  Serial.println();
  Serial.println("Array has been initialized Successfully.");
  Serial.println("The reversed array is:");
  i = siz - 1;
  while (i >= 0)
  {
    Serial.print(arr[i]);
    Serial.print(" ");
    i--;
  }
}
