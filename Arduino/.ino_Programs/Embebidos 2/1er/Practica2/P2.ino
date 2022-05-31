#include <LiquidCrystal_I2C.h>
#include <Keypad.h>
#include <CheapStepper.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);
CheapStepper stepper (8, 9,10, 11); 
//Variables para asitgnar pines
bool Clock = true;
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
int enter();
//funcion para imprimir texto
void show (const char* str, int CoorX = 0, int CoorY = 0) {
  //coordenadas para inicializar el cursor
    if (CoorX >= 0 && CoorY >= 0)
        lcd.setCursor(CoorX, CoorY);
    //imprime la string
    lcd.print(str);
}
//funcion para imprimir numeros
void show (double num, int CoorX = 0, int CoorY = 0) {
    if (CoorX >= 0 && CoorY >= 0)
        lcd.setCursor(CoorX, CoorY);
    lcd.print(num);
}

void setup() {
  lcd.init();
  lcd.backlight();
  stepper.setRpm(10); 
}

void loop() {
    short opc1 = 0, opc2 = 0, num = 0;
    int tiempo = 0;

    /*show(" 1.- Paso completo ", 0, 0);
    show(" 2.- Paso medio ", 0, 1);
    show(" Num: ", 0, 2);*/
    
    opc1 = 1;
    
    // show(" 1.- Giro izq", 0, 0);
    // show(" 2.- Giro der ", 0, 1);
    // show(" Num: ", 0, 2);

    opc2 = 2;
    
    if(opc1== 1)
        stepper.setRpm(15);
    else
        stepper.setRpm(6);
    
    Clock = (opc2 == 1) ? true : false;
    
    stepper.moveDegrees(Clock, 360);
    delay(200);
    
    lcd.clear();
}

int enter(){
  int value = 0;
  char c = '\0';
  int X3 = 10, temp = 0;//coordenada X y valor temporal
  c = TecHex.getKey(); 
  while( c =='\0' || c < 58 ||c > 47)
  {
     delay(1);
     c = TecHex.getKey();
     if( c !='\0' && c < 58 && c > 47){
        lcd.setCursor(X3,2);
        lcd.print(c);
        temp = String(c).toInt(); //se le resta a c el valor ascii de 48 --> '0'
        value = (value * 10) + temp;
        X3++;//se le suma uno a la coordenada X
     }
     if(c == '#')
        break;    
  }
  lcd.clear();
  return value;
}