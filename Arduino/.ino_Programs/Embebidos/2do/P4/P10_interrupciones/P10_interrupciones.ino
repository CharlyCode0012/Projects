#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include<TimerOne.h>
#define button1 3 //Pulsador
#define button2 2
LiquidCrystal_I2C lcd(0x27, 20, 4);



String str = "";
volatile int cont = 0;
const int Banda = 150, Banda1 = 150;
long Time = 0, Time1 = 0;



 
void setup()
{
  //Configura la entrada
   pinMode(button1, INPUT_PULLUP);
   pinMode(button2, INPUT_PULLUP);
   //Configura la interrupción en el PIN del pulsador en modo FALLING
   attachInterrupt(digitalPinToInterrupt(button2), Adrian, FALLING);
   attachInterrupt(digitalPinToInterrupt(button1), Carlos, RISING);
   Timer1.initialize(1000000);      //Configura el TIMER en 1 Segundo
   Timer1.attachInterrupt(timeIn);
   Serial.begin(9600);
   lcd.init();
   lcd.backlight();
   lcd.setCursor(0,0);
   lcd.print("HOLA");
   delay(1000);
   lcd.clear();
   lcd.setCursor(0, 1);
}
 
void loop()
{
  lcd.setCursor(0,2);
  lcd.print(str);
}

void Adrian()
{

  if (millis() - Time > Banda)
   {
      str = "+Adrian Orozco UwU+ ";
      Time = millis();
   }
}

void Carlos()
{

  if (millis() - Time1 > Banda1)
   {
      str = " *Carlos Lozano OwO*";
      Time1 = millis();
   }
}

void timeIn()
{
  cont ++;
  if (cont%30 == 0){
      str = " -Buen dia a todos- ";
  }   
}
