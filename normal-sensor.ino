//processing of switch is "blocking"
/*#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266HTTPClient.h>
//wifi information
const char *ssid = "5BB";
const char *password = "01539310";

//Web Host
const char *host = "https://startuphexapixel.herokuapp.com/api/";*/
#include <TM1637Display.h>

// Module connection pins (Digital Pins)
#define CLK 2
#define DIO 3

// The amount of time (in milliseconds) between tests
#define TEST_DELAY   2000

const uint8_t SEG_DONE[] = {
  SEG_B | SEG_C | SEG_D | SEG_E | SEG_G,           // d
  SEG_A | SEG_B | SEG_C | SEG_D | SEG_E | SEG_F,   // O
  SEG_C | SEG_E | SEG_G,                           // n
  SEG_A | SEG_D | SEG_E | SEG_F | SEG_G            // E
  };

TM1637Display display(CLK, DIO);
const int Inp0 = 4; //port 2
const int Out0 = 13; //LED
int counter;
/*
HTTPClient http;
String postData;*/


void setup()
{
  delay(1000);
  Serial.begin(9600);
  /*WiFi.mode(WIFI_OFF);
  delay(1000);
  WiFi.mode(WIFI_STA);

  WiFi.begin(ssid, password);
  Serial.print("");

  Serial.print("Connecting");
  //Wait for connection

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  //If connection successful show IP address in serial monitor
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP()); //IP address assigned to your ESP*/
  pinMode(Inp0, INPUT);
  digitalWrite(Inp0, HIGH); pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW); //Turn LED off to start.
};

void loop()
{
  int k;
  int khu, sal, yar, htaung;
  uint8_t data[] = {};
  uint8_t blank[] = { 0x00, 0x00, 0x00, 0x00 };
  display.setBrightness(0x0f);

  // All segments on
  

  // Selectively set different digits
  
  
  if (digitalRead(Inp0) == LOW) {
    digitalWrite(LED_BUILTIN, HIGH);
  delay(100);
  //Stuff to happen when switch closed
  counter++;
  Serial.println(counter);
  khu = counter % 10;
  sal = (counter % 100) / 10;
  yar = (counter % 1000) / 100;
  htaung = (counter % 10000) / 1000;

  data[0] = display.encodeDigit(htaung);
  data[1] = display.encodeDigit(yar);
  data[2] = display.encodeDigit(sal);
  data[3] = display.encodeDigit(khu);
  display.setSegments(data);
  //sendDatatoServer(counter);
  
  while (digitalRead(Inp0) == LOW) {

  };//Put to do while waiting
  digitalWrite(LED_BUILTIN, LOW);
  delay(100);
  };
};

/*void DealWithSwitchPress()
{
  digitalWrite(LED_BUILTIN, HIGH);
  delay(100);
  //Stuff to happen when switch closed
  counter++; 
  Serial.println(counter);
  //sendDatatoServer(counter);
  
  while (digitalRead(Inp0) == LOW) {

  };//Put to do while waiting
  digitalWrite(LED_BUILTIN, LOW);
  delay(100);
  //Put here: Stuff to happen when switch finishes opening

}*/

/*void sendDatatoServer(int a)
{
  postData = "count = " + a;
  http.begin(host);
  http.addHeader("Content-Type", "application/x-www-form-urlencode");
  int httpCode = http.POST(postData);
  String payload = http.getString();

  Serial.println(httpCode);
  Serial.println(payload);
  http.end();
}*/
