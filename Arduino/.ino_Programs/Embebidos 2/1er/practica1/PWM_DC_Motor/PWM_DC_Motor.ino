#include <LiquidCrystal_I2C.h>
#include <Keypad.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);

//Variables para asitgnar pines
short button = 52, Motor = 11;
const byte Fila = 4;
const byte Columna = 4;
char keys_p[Fila][Columna]
{
   {'1','4','7','*'},
   {'2','5','8','0'},
   {'3','6','9','#'},
   {'A','B','C','D'}
};

byte pin_f[Fila] = {9, 8, 7, 6};
byte pin_c[Columna] = {5, 4, 3, 2};
//mapeo del teclado
Keypad TecHex = Keypad(makeKeymap (keys_p), pin_f, pin_c, Fila, Columna);
double enter();

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
//funcion para obtener rango de 2 puntos diferentes (ecuacion de la recta)
inline double conversion( double X, double int_min, double int_max, double Out_min, double Out_max){
    return (X-int_min) * (Out_max-Out_min)/(int_max - int_min) + Out_min;
}

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  pinMode(Motor, OUTPUT);
  pinMode(button, INPUT_PULLUP);//boton para secuencia 
}

void loop() {
    double num = 0, temp = 0, incremento = 0, porcentaje = 0;
    int tiempo = 0;
    lcd.print("Ingrese un numero: ");
    num = enter();
    system("cls");
    show("Tiempo: ", 1, 0);
    show(tiempo, 9, 0);
    show("Porcentaje: ", 1, 1);
    show(porcentaje, 13, 1);
    lcd.print("%");
    //obtener razón de crecimiento.
    incremento = 256/num; 
    //se le asigna la razon de crecimiento
    temp = incremento;
    for(; temp < 256; temp += incremento){
        delay(1000);
        lcd.clear();
        tiempo ++;
        //obtiene el punto
        porcentaje = conversion( temp, 0, 255, 0, 100);
        show("Tiempo: ", 1, 0);
        show(tiempo, 9, 0);
        show("Porcentaje: ", 1, 1);
        show(porcentaje, 13, 1);
        lcd.print("%");
        analogWrite(Motor, temp);
    }
    //en caso de que el valor supere 255
    if(temp + incremento >= 256 && tiempo < num){
            delay(1000);
            lcd.clear();
            //se aniliza si el tiempo transcurrido es menor al ingresado, si es así se incrementa en 1
            tiempo ++;
            porcentaje = 100;
            temp = 255;
            show("Tiempo: ", 1, 0);
            show(tiempo, 9, 0);
            show("Porcentaje: ", 1, 1);
            show(porcentaje, 13, 1);
            analogWrite(Motor, 255);
            lcd.print("%");
        }
     tiempo = 0;
     temp-=incremento;
     for(; temp >=0; temp -= incremento){
        delay(1000);
        lcd.clear();
        tiempo ++;
        porcentaje = conversion( temp, 0, 255, 0, 100);
        show("Tiempo: ", 1, 0);
        show(tiempo, 9, 0);
        show("Porcentaje: ", 1, 1);
        show(porcentaje, 13, 1);
        lcd.print("%");
        analogWrite(Motor, temp);
    }
    if(temp - incremento <= 0 && tiempo < num){
            delay(1000);
            lcd.clear();
            tiempo ++;
            porcentaje = 100;
            show("Tiempo: ", 1, 0);
            show(tiempo, 9, 0);
            show("Porcentaje: ", 1, 1);
            show(porcentaje, 13, 1);
            analogWrite(Motor, 0);
            lcd.print("%");
        }
    while(digitalRead(button) == HIGH){} //ciclo para apreciar resultado
    delay(200);
    lcd.clear();
}

double enter()

{
  double value = 0;
  char c = '\0';
  int X3 = 10, temp=0;//coordenada X y valor temporal
  c = TecHex.getKey();
  
  while( c =='\0' || c < 58 ||c > 47)
  {
     delay(1);
     c = TecHex.getKey();
     if( c !='\0' && c < 58 && c > 47){
         
        lcd.setCursor(X3,2);
        lcd.print(c);
        temp = String(c).toInt(); //se le resta a c el valor ascii de 48 --> '0'
        value = (value * 10.00) + temp; //se le ingresa el valor ingresado y se multiplica x10 para que funcione
                                         //ejemplo (0*10)+1---> (1*10)+2, esto quiere decir que se ingreso primero el 1 y luego el 2 y te da 12
        X3++;//se le suma uno a la coordenada X
     }
     if(c == '#')
        break;    
  }
  lcd.clear();
  return value;
}
