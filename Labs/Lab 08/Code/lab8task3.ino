#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

String s = "<!DOCTYPE html><html><body><form action=\"/ledblink\"><select name=\"drop\"><option>Choose a Number</option><option value='1'>1</option><option value='2'>2</option><option value='3'>3</option><option value='4'>4</option><option value='5'>5</option><option value='6'>6</option><option value='7'>7</option><option value='8'>8</option><option value='9'>9</option></select><input type=\"submit\" value=\"Submit\"></form></body></html>";

const char *ssid = "41bdbe";
const char *password = "248200754";

ESP8266WebServer server(80); //Server on port 80
int ledPin = 2;

void handleRoot()
{
  server.send(200, "text/html", s); // send web page
}

void blinkFunc(int n)
{
  for (int i = 0; i < n; i++)
  {
    digitalWrite(ledPin, HIGH);
    delay(1000);
    digitalWrite(ledPin, LOW);
    delay(1000);
  }
}

void handleForm()
{
  int n = server.arg("drop").toInt(); // getting input
  Serial.print("LED blinking ");
  Serial.print(n);
  Serial.println(" times");
  blinkFunc(n);
  String s = "<a href='/'> Go Back </a>";
  server.send(200, "text/html", s); //Send web page
}

void setup(void)
{
  Serial.begin(9600);

  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);

  WiFi.begin(ssid, password); // connect to your WiFi router
  Serial.println("");

  // wait for connection
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }

  // if connection successful show IP address in serial monitor
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println("WiFi");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());  //IP address assigned to your ESP

  server.on("/", handleRoot); // which routine to handle at root location
  server.on("/ledblink", handleForm); // form action is handled here

  server.begin(); // start server
  Serial.println("HTTP server started");
}

void loop(void)
{
  server.handleClient(); // handle client requests
}
