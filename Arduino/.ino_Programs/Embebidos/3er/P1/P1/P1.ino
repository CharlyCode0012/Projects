#include <DHT.h>
#include <LiquidCrystal_I2C.h>

#define ACT_S 51
#define LDR 52

LiquidCrystal_I2C lcd(0x27, 16, 2);

DHT dht(13,  DHT11);

void show(float Value, int coorX = 0, int coorY = 0){

   lcd.setCursor(coorX, coorY);
   lcd.print(Value);
}
 
void setup() {
  lcd.init();
  lcd.setCursor(0,0);
  lcd.backlight();
  dht.begin();
  pinMode(ACT_S, OUTPUT);
}
 
void loop() {

  lcd.setCursor(0, 0);
  delay(5000);
 
  // Leemos la humedad relativa
  float h = dht.readHumidity();
  // Leemos la temperatura en grados centígrados (por defecto)
  float t = dht.readTemperature();
  if(t >= 28)
     digitalWrite(ACT_S, LOW);
  else
     digitalWrite(ACT_S, HIGH);
     
  // Comprobamos si ha habido algún error en la lectura
  if (isnan(h) || isnan(t)) {
    lcd.print(" Error obteniendo los"); 
    lcd.setCursor(0, 1);
    lcd.print("datos del sensor DHT11");
    return;
  }
 
  lcd.print("Hume: ");
  show(h, 6, 0);
  lcd.setCursor(0,1);
  lcd.print("Temp: ");
  show(t, 6 , 1);
  lcd.print(" *C ");
}
