#include "lib_ejc.h"
#include <ESP8266HTTPClient.h>
#include <SoftwareSerial.h>

SoftwareSerial Arduino(12, 14);
//String url = "http://iot-rgb.000webhost.com/RGB/TX.php";

WiFiClient wifiClient;
String protocol = "http://";
String host = "iot-rgb.000webhostapp.com";
String resource = "/TX.php";
String postData = "?id=99999&pw=12345";
String respuesta;
int Port = 80;
String letras[] = {"Vel: ","Dir: ","State: "};

String url = protocol + host + ":" + String(Port) + resource + postData;

void rgbToInt(int *);

void setup(void)
{
  /*for(int cont = 0; cont <3; cont ++)
    pinMode(RGB_PWM[cont], OUTPUT);*/
  Serial1.begin(9600);
  Arduino.begin(9600);
  connect_wifi();
}

void loop(void)
{
  HTTPClient http;
  http.begin(wifiClient, url);
  http.addHeader("Content-Type","application/x-wwww.form-urlencoded");
  int httpCode = http.GET();
  respuesta = http.getString();
  Serial.println(respuesta);
  http.end();
  
  Serial1.println(respuesta);
  Arduino.println(respuesta);
  delay(700);
}
