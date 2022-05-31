#include <SoftwareSerial.h>
#define E_RX 10
#define E_TX 11

int RGB_PWM[] = {2, 3, 4};
String rgb;
String letras[] = {"R: ","G: ","B: "};

SoftwareSerial ESP8266(E_RX, E_TX); // RX pin10 | TX pin11

void rgbToInt(int *);

void setup(){
  
  ESP8266.begin(9600);
  Serial.begin(9600);
}

void loop(){
  int RGB[] = {0, 0, 0};
  rgb = ESP8266.readStringUntil('\n');
  //Serial.println(rgb);
  rgbToInt(RGB);
  
  for(int cont = 0; cont < 3; cont++ ){
    //digitalWrite(RGB_PWM[cont], RGB[cont]);
    Serial.println(letras[cont] + String(RGB[cont]));
  }

  delay(700);
}

void rgbToInt(int RGB[3]){
  int cont = 0;
 
  for(char item : rgb){
    
     if(item == ','){
      cont++;
      continue;
    }
    
    if(item >= '0' && item <= '9'){
      RGB[cont]= RGB[cont] * 10 + String(item).toInt();
    }
    
  }
}
