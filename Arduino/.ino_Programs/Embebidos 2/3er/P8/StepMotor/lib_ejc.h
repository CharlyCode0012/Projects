#include <ESP8266WiFi.h>
#include <strings_en.h>
#include <WiFiManager.h>

#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <Ticker.h>

#define pinLedWiFi 2

Ticker ticker;

/*void printMessageWiFi(){
  Serial.println("\n******************************");
  Serial.print("Concetando a la red SSID: ");
  Serial.println(WiFi.SSID());
  Serial.print("IP: ");
  Serial.println(WiFi.localIP());
  Serial.print("MAC ADDRESS: ");
  Serial.println(WiFi.macAddress());
  Serial.println("******************************");
  
}*/

void parpadeoLed(){
  byte estado = digitalRead(pinLedWiFi);
  digitalWrite(pinLedWiFi, !estado);
}

void connect_wifi(){
  Serial.begin(9600);
  
  WiFiManager wifiManager;
  pinMode(pinLedWiFi, OUTPUT);
  ticker.attach(0.2, parpadeoLed); 
  
  //wifiManager.resetSettings();
  if(!wifiManager.autoConnect("ESP8266Temp", "12345678")){
    //Serial.print("Fallo la conexion");
    ESP.reset();
    delay(1000);
  }
  
  //printMessageWiFi();
  ticker.detach();
  digitalWrite(pinLedWiFi, HIGH);
}
