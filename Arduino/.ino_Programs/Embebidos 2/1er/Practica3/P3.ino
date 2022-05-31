#include <Servo.h>
#include <Keypad.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);
Servo servo1;

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

short enter();

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
  servo1.attach(11, 500, 2400);
}

void loop() {
    short opc1 = 0, opc2 = 0, num = 0, cant = 0, *grados;
    int tiempo = 0;

    while(cant <= 0 || cant > 9)
    {
        show("Posiciones: ", 0, 0);
        cant = enter();
    }

    grados = new short[cant];

    for(short i = 0; i < cant; i++)
    {
        show("Ingrese grados ", 0, 0);
        show(" Num: ", 0, 2);

        grados[i] = enter();
    }

    for(short i = 0; i < cant; i++){
        lcd.clear();
        servo1.write(grados[i]);

        show("Grados: ", 0, 1);
        lcd.print(servo1.read());

        delay(5000);
    }

    lcd.clear();
    delete []grados;
}

short enter(){
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