#include <Keypad.h>
#include <LiquidCrystal_I2C.h>
#define GIRO_IZQ 50
#define GIRO_DER 51

LiquidCrystal_I2C lcd(0x27, 20, 4);
typedef unsigned short us;

char keys_p[4][4]
{
   {'1','4','7','*'},
   {'2','5','8','0'},
   {'3','6','9','#'},
   {'A','B','C','D'}
};

byte pin_f[4] = {9, 8, 7, 6};
byte pin_c[4] = {5, 4, 3, 2};

//mapeo del teclado
Keypad TecHex = Keypad(makeKeymap (keys_p), pin_f, pin_c, 4, 4);
bool State = LOW;

void show (const char* str, int CoorX = 0, int CoorY = 0) {
  //coordenadas para inicializar el cursor
    if (CoorX >= 0 && CoorY >= 0)
        lcd.setCursor(CoorX, CoorY);
    //imprime la string
    lcd.print(str);
}

void setup(){
    lcd.init();
    lcd.backlight();
    pinMode(GIRO_DER, OUTPUT);
    pinMode(GIRO_IZQ, OUTPUT);
    digitalWrite(GIRO_DER, HIGH);
    digitalWrite(GIRO_IZQ, HIGH);
}

void loop(){
    us Opc = 0;
    while(Opc < 1 || Opc > 3)
    {
        show("1.- Giro IZQ ", 1, 0);
        show("2.- Giro DER ", 1, 1);
        show("3.- Stop", 1, 2);
        show(" Opc: ", 1, 3);
        Opc = enter();
    }
    if(Opc == 3)
    {
        digitalWrite(GIRO_DER, State);
        delay(10);
        digitalWrite(GIRO_IZQ, State);
    }
    else
    {
        State = (Opc == 1)? LOW : HIGH;
        digitalWrite(GIRO_DER, !State);
        delay(10);
        digitalWrite(GIRO_IZQ,  State);
    }
    delay(10);
}

us enter(){
  int value = 0, temp = 0;
  char c = '\0';
  c = TecHex.getKey(); 

  while( c =='\0' || c < 58 ||c > 47)
  {
     delay(1);
     c = TecHex.getKey();
     if( c !='\0' && c < 58 && c > 47){
        lcd.print(c);
        temp = String(c).toInt(); //se le resta a c el valor ascii de 48 --> '0'
        value = (value * 10) + temp;
     }
     if(c == '#')
        break;    
  }

  lcd.clear();
  return value;
}
