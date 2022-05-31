#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>


LiquidCrystal_I2C lcd(0x27, 20, 4);

int button = 52;
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


float enter();
void show1(float Valor, int CoorX = 1, int CoorY = 2)// funcion para imprimir
{
    
    lcd.setCursor(CoorX, CoorY);
    lcd.print(Valor);
    delay(500);
}

void setup() 
{ 
  lcd.init();
  lcd.backlight();
  lcd.setCursor(4,0);
  pinMode(button, INPUT_PULLUP);//boton para secuencia
}

void loop() 
{
  lcd.clear();
  bool band = true;
  float r = 0, *matriz;
  int opc = 0;
  while(digitalRead(button) == HIGH)//hasta que se presione button de A1 actuara el ciclo
   { 
      lcd.setCursor(8,0);
      lcd.print("Menu");//se imprimen las opciones
      lcd.setCursor(2,2);
      lcd.print("0.Suma  1.Resta");
      delay(1500);
      lcd.setCursor(2,2);
      lcd.print("2.Multi  3.Divi");
      delay(1500);
      lcd.setCursor(2,2);
      lcd.print("4.Y a 99  5.NuMay");
      delay(1500);
      lcd.clear();
   } 
  delay(200);
  lcd.setCursor(6,0);
  lcd.print("Opcion: ");   
  opc = enter();
  lcd.setCursor(6,0);
  lcd.print("Opcion: ");
  lcd.print(opc);
    if(opc!=4 && opc >= 0 && opc <= 5) //arreglo de 2
    {
      matriz = new float[2];
      for (int cont = 0; cont < 2; cont++)
      {
        lcd.setCursor(0,2);
        lcd.print("Numero ");
        lcd.print(cont+1);
        lcd.print(": ");
        matriz[cont] = enter();
      }//se ingresan los 2 valores
           
    }
    else //arreglo de 1
    {
      if(opc==4){
      matriz = new float [1]; // se ingresa su unico valor
      lcd.setCursor(0,2);
      lcd.print("Numero 1: ");
      matriz[0] = enter();
      }
    }
    
    lcd.setCursor(0,2);
    lcd.print("Resultado: ");
    switch (opc)
    {
      case 0:
            r = matriz[0] + matriz[1]; //suma de los 2 valores
            break;
      case 1:
            if (max(matriz[0], matriz[1]) == matriz[0])//se analiza cual es ma grande
            {
              r = matriz[0] - matriz[1];
            }
            else
            {
              r = matriz[1] - matriz[0];//valor negativo
              lcd.setCursor(10,2);
              lcd.print("-");
            }
            lcd.setCursor(11,2);
            break;
      case 2:
            r = matriz[0] * matriz[1]; //multiplicacion
            break;
      case 3:
            r = matriz[0] / matriz[1]; //div
            break;
      case 4:
            for(float cont = matriz[0]; cont <= 99; cont++) //muestra del valor decimal Y al valor decimal 99
            {
              show1(cont, 11);
              delay(200);
            }
                
            break;
      case 5:
            delay(500);
            r= max(matriz[0], matriz[1]); //se muestra el mayor
            break;
      default:
            lcd.clear();
            lcd.setCursor(9, 2); // si no es ninguna muestra FF Hex
            lcd.print("**ERROR**");
            band = false;
            break;
      
    }
    if (band == true)
        show1(r, 11);
    while(digitalRead(button) == HIGH){} //ciclo para apreciar resultado
    delay(200);
}

float enter()
{
  float value = 0;
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
