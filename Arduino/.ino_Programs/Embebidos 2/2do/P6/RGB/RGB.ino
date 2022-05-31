#include "lib_ejc.h"
#include <ESP8266HTTPClient.h>

//String url = "http://iot-rgb.000webhost.com/RGB/TX.php";

WiFiClient wifiClient;
String protocol = "http://";
String host = "iot-rgb.000webhostapp.com";
String resource = "/RGB/TX.php";
String postData = "?id1=99999&pw1=12345";
String respuesta;
int Port = 80;
int RGB_PWM[] = {15, 13, 12}; // D8 -> R, D7 -> G, D6 -> B
String letras[] = {"R: ","G: ","B: "};

String url = protocol + host + ":" + String(Port) + resource + postData;

void rgbToInt(int *);

void setup(void)
{
  for(int cont = 0; cont <3; cont ++)
    pinMode(RGB_PWM[cont], OUTPUT);
  connect_wifi();
}

void loop(void)
{
  HTTPClient http;
  http.begin(wifiClient, url);
  http.addHeader("Content-Type","application/x-wwww.form-urlencoded");
  int httpCode = http.GET();
  respuesta = http.getString();
  //Serial.println(respuesta);
  http.end();
  
  int RGB[] = {0, 0, 0};
  
  rgbToInt(RGB);
  
  for(int cont = 0; cont < 3; cont++ ){
    analogWrite(RGB_PWM[cont], RGB[cont]);
    Serial.print(letras[cont] + String(RGB[cont]) + " ");
  }
  Serial.print('\n');
  
  delay(700);
}

void rgbToInt(int RGB[3]){
  int cont = 0;
 
  for(char item : respuesta){
    
     if(item == ','){
      cont++;
      continue;
    }
    
    if(item >= '0' && item <= '9'){
      RGB[cont]= RGB[cont] * 10 + String(item).toInt();
    }
    
  }
}
