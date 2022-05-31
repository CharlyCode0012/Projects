#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <TimerOne.h>

#define MICRO 53
#define ACT_S 51
#define LDR 52
#define ACT_L 50

LiquidCrystal_I2C lcd (0x27, 20, 4);
volatile unsigned sec = 0;
void Sen_Sound();

void show (const char* str, int CoorX = 0, int CoorY = 0) {
    if (CoorX >= 0 && CoorY >= 0)
        lcd.setCursor(CoorX, CoorY);
    lcd.print(str);
}

void setup () {
    lcd.init();
    lcd.setCursor(0, 0);
    lcd.backlight();

    Timer1.initialize(1000000);
    Timer1.attachInterrupt(Sen_Sound);
    
    pinMode(LDR, INPUT);
    pinMode(ACT_L, OUTPUT);
    pinMode(MICRO, INPUT);
    pinMode(ACT_S, OUTPUT);

    digitalWrite(ACT_S, HIGH);
    digitalWrite(ACT_L, HIGH);

    show("Act Sonido: OFF");
    show("Act Luz: OFF", 0, 1);
}

void loop () {
    if (digitalRead(MICRO)) {
        digitalWrite(ACT_S, LOW);
        show("Act Sonido: ON ");
    }
    else
      show("Act Sonido: OFF");
    
    if (digitalRead(LDR) == 0) {
        digitalWrite(ACT_L, LOW);
        show("Act Luz: ON ", 0, 1);
    }
    else {
        digitalWrite(ACT_L, HIGH);
        show("Act Luz: OFF", 0, 1);
    }
}

void Sen_Sound()
{
        if (digitalRead(ACT_S) == LOW){

        sec++;

        if (!(sec % 10)) {
            digitalWrite(ACT_S, HIGH);
            //
            sec = 0;
          }
        }
}
