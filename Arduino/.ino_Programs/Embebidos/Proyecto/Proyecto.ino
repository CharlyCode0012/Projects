#include <DHT.h>
#include <Keypad.h>
#include <LiquidCrystal_I2C.h>
#include <TimerOne.h>

#define ACT_V 51
#define ACT_C 50
#define FocoV 49
#define FocoR 48


LiquidCrystal_I2C lcd (0x27, 16, 2);
DHT dht(11,  DHT11); // pin 2 entradad de temperatura

String password = "1234";
volatile unsigned sec = 0;
bool flag = false, flag1;
float val_t = 0, timer2, dis;

const int Echo = 10, Trigger = 12;
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

Keypad TecHex = Keypad(makeKeymap (keys_p), pin_f, pin_c, Fila, Columna);


float enter_T();
String enter_P();
void Servo_Chapa();

void show_C (const char* str, bool clearS = false, int CoorX = 0, int CoorY = 0) {
    if(clearS)
      lcd.clear();
    if (CoorX >= 0 && CoorY >= 0)
        lcd.setCursor(CoorX, CoorY);
    lcd.print(str);
}

void show_T (float value, bool clearS = false, int CoorX = 0, int CoorY = 0) {
    if(clearS)
      lcd.clear();
    if (CoorX >= 0 && CoorY >= 0)
        lcd.setCursor(CoorX, CoorY);
    lcd.print(String(value).toInt());
}

void setup () {
    lcd.init();
    lcd.setCursor(0, 0);
    lcd.backlight();

    Timer1.initialize(1000000);
    Timer1.attachInterrupt(Servo_Chapa);
    
    pinMode(ACT_V, OUTPUT);
    pinMode(ACT_C, OUTPUT);
    pinMode(Trigger, OUTPUT); //pin como salida
    pinMode(Echo, INPUT);  //pin como entrada
    
    digitalWrite(Trigger, LOW);//Inicializamos el pin con 
    digitalWrite(ACT_V, HIGH);
    digitalWrite(ACT_C, HIGH);
    digitalWrite(FocoV, HIGH);
    digitalWrite(FocoR, HIGH);
    Serial.begin(9600);
}

void loop () {
      lcd.setCursor(0, 0);
      delay(2000);
      digitalWrite(FocoR, HIGH);
      String pass = "";
      float t = dht.readTemperature();
      
      if (isnan(t)) {
        lcd.print(" Error obteniendo los"); 
        lcd.setCursor(0, 1);
        lcd.print("datos del sensor DHT11");
        return;
      }else{
        if(t >= val_t){
          if(digitalRead(ACT_V) != LOW)
           digitalWrite(ACT_V, LOW);
          show_C("Temp: ", true);
          show_T(t, false, 6);
          show_C(" *C", false, 8);
        
          digitalWrite(FocoV, LOW);
          delay(2000);
        }
        else{
          digitalWrite(ACT_V, HIGH);
          digitalWrite(FocoV, HIGH);
        }
      }    
    int opc = enter_OPC();
    switch (opc)
    {
      case 1://ingresar pass
            pass = enter_P();
            if(pass == password){
              digitalWrite(ACT_C, LOW);
            }
            else{
              digitalWrite(FocoR, LOW);
            }
            break;
      case 2://cambiar pass
            password = enter_P();
            break;
      case 3://cambiar temp
            val_t = enter_T();
            show_C("Temp: ", true);
            show_T(val_t, false, 6);
            show_C(" *C");
            break;
      case 4://mostrar temp
            show_T(t, true);
            break;
      default:
            lcd.clear();
            lcd.setCursor(9, 2); // si no es ninguna muestra FF Hex
            lcd.print("**ERROR**");
            break;
      
    }
}

void Servo_Chapa()
{
        if (digitalRead(ACT_C) == LOW){

            sec++;

        if (!(sec % 30)) {
            digitalWrite(ACT_C, HIGH);
            sec = 0;
          }
        }         
}

float enter_T()
{
  float value = 0;
  char c = '\0';
  int X3 = 3, temp=0;//coordenada X y valor temporal
  c = TecHex.getKey();
  show_C(" Cambiar Temp.", true, 0, 0);
  while( c =='\0' || c < 58 ||c > 47)
  {
     delay(1);
     c = TecHex.getKey();
     if( c !='\0' && c < 58 && c > 47){
         
        lcd.setCursor(X3,1);
        lcd.print(String(c) + "*C");
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

String enter_P()
{
  char c = '\0';
  int X3 = 3, temp = 0, i = 0;//coordenada X y valor temporal
  c = TecHex.getKey();
  show_C("  **PASSWORD**", true, 0, 0);
  String pass = "";
  while( c =='\0' || c < 58 ||c > 47)
  {
     delay(1);
     c = TecHex.getKey();
     if( c !='\0' && c < 58 && c > 47){
         
        lcd.setCursor(X3,1);
        lcd.print('*');
        pass[i++] = c;
        X3++;//se le suma uno a la coordenada X
     }
     if(c == '#')
        break;    
  }
  lcd.clear();
  return pass;
}

int enter_OPC()
{
  int value = 0;
  char c = '\0';
  int X3 = 3, temp=0;//coordenada X y valor temporal
  c = TecHex.getKey();
  lcd.clear();
  show_C(" Opcion:", true, 0, 0);
  while( c =='\0' || c < 58 ||c > 47)
  {
     delay(1);
     c = TecHex.getKey();
     if( c !='\0' && c < 58 && c > 47){
         
        lcd.setCursor(X3,1);
        lcd.print(String(c));
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
