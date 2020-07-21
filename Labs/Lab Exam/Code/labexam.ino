#include <ESP8266WiFi.h>
#include <ESP8266Ping.h>
#include <ESP8266WiFiMulti.h>
#include <WiFiClient.h>
#include <WiFiClientSecure.h>
#include <WiFiServer.h>
#include <WiFiServerSecure.h>
#include <WiFiUdp.h>
#include <ESP8266WebServer.h>
#include <ESP8266HTTPClient.h>

const int led = D3; // led pin number
const int btn = D2; // button pin number

bool stateLED = LOW;
int cState = 0; // current state of the inc. button
int pState = 0; // previous state of the inc. button
int i = 0;
int j = 0;

const char *ssid = "mob";  // ENTER YOUR WIFI SETTINGS
const char *password = "pakistan04";

String host = "192.168.43.111"; // server address to read/write from

void setup()
{
  pinMode(btn, INPUT);
  pinMode(led, OUTPUT); // configuring sensor pin as input
  Serial.begin(9600);
  delay(100);

  WiFi.begin(ssid, password); // connect to your WiFi router
  Serial.print("Connecting");
  // wait for connection
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }

  // if connection successful show IP address in serial monitor
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  Serial.println(WiFi.gatewayIP());
  // check if node can ping the server
  IPAddress ip (192, 168, 43, 111); // the remote ip to ping
  bool ret = Ping.ping(ip);
  Serial.print("Pinging: ");
  Serial.println(ret);
}

void loop()
{
  cState = digitalRead(btn); // read button value
  if (cState != pState)
  {
    if (cState == HIGH && i == 0)
    {
      j = 1;
      digitalWrite(led, HIGH);
      updateState(1);
    }
    else if (cState == LOW && j == 1)
    {
      i = 1;
    }
    else if (cState == HIGH && i == 1)
    {
      j = 0;
      digitalWrite(led, LOW);
      updateState(0);
    }
    else if (cState == LOW && j == 0)
    {
      i = 0;
    }
  }
  pState = cState;
}
// function that sends the status of LED to the server
void updateState(int stat)
{
  HTTPClient http; // HTTPClient object
  
  String postData; // post Data
  postData = "status=" + String(stat);

  http.begin("http://" + host + "/labexam/insert.php"); // request destination
  http.addHeader("Content-Type", "application/x-www-form-urlencoded"); // content-type header

  int httpCode = http.POST(postData); // send the request
  String payload = http.getString(); // get the response payload

  Serial.println(httpCode); // print HTTP return code
  Serial.println(payload); // print request response payload

  http.end(); // close connection
}
