
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd (0x27, 20, 4);

short LEDS [] = {8, 9, 10, 11};
short Vect[] = {2, 3, 4, 5, 6};

void S(short int ite, bool Out1 = HIGH, bool Out2 = LOW)
{
  digitalWrite(Vect[ite], Out1);
  digitalWrite(Vect[ite+1], Out2);
  delay(200);
}

void show (const char* str, const int x = 0, const int y = 0, const bool clear = false) {
    if (clear)
        lcd.clear();

    if (x >= 0 && y >= 0)
        lcd.setCursor(x, y);
    lcd.print(str);
}

void setup()
{
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  
    for(short i = 0; i < 4; i++){
      if(Vect[i] != 6)
        pinMode(Vect[i], OUTPUT);
      else
        pinMode(Vect[i], INPUT);
    } 
    
   for(short i = 0; i < 4; i++)
        pinMode(LEDS[i], OUTPUT);
        
  S(0);
}

void loop()
{
  for(short i = 0; i < 4; i++)
       digitalWrite(LEDS[i], LOW);
  
  S(2, LOW);
  int rojo = pulseIn(Vect[4], LOW);
  S(2, HIGH, HIGH);
  int verde = pulseIn(Vect[4], LOW);
  S(2, LOW, HIGH);
  int azul = pulseIn(Vect[4], LOW);


  //naranja
  if(rojo < 80 && (verde > 210 && verde < 231) && (azul > 220 && azul < 240) ){
    digitalWrite(LEDS[1], HIGH);
    show(" -Naranja- ", 2, 1, true);
  }
  //rojo
  else if((rojo > 110 && rojo < 125) && verde > 410 && azul > 289){
    digitalWrite(LEDS[0], HIGH);
    show(" -Rojo- ", 4, 1, true);
  }
  //verde
  else if(verde < 110 && (rojo > 120 && rojo < 140) && (azul > 150 && azul < 180)){
    digitalWrite(LEDS[2], HIGH);
    show(" -Verde- ", 4, 1, true);
  }
  //azul
  else if(azul < 75 && (verde > 90 && verde < 110) && rojo > 165){
    digitalWrite(LEDS[3], HIGH);
    show(" -Azul- ", 4, 1, true);
  }
  Serial.print("R: ");
  Serial.print(rojo);
  Serial.print(", ");
  Serial.print("G: ");
  Serial.print(verde);
   Serial.print(", ");
  Serial.print("B: ");
  Serial.println(azul);
  delay(1000);
}
