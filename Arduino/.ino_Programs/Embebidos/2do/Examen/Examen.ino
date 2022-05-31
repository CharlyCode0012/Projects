#include <Wire.h>
#include<TimerOne.h>
#include <LiquidCrystal_I2C.h>

#define LEDT  3
#define LED_D 4

LiquidCrystal_I2C lcd(0x27, 20, 4);

volatile int cont = 0, cont2 = 0;
int sw[8] = {22, 23, 24, 25, 26, 27, 28, 29}, leds[] = {37, 36, 35, 34, 33, 32, 31, 30}, button = 2, button2 = 5;
volatile bool flag = false, flag2 = false;
char letras[] = {'A', 'B', 'C', 'D'};

int enter();
void timeIn();
void inExt();

// funcion para imprimir
void show(float Valor, int CoorX = 1, int CoorY = 2){
    lcd.setCursor(CoorX, CoorY);
    lcd.print(Valor);
    delay(500);
}

void setup()
{
    
    DDRC = 0xFF; // se declara como salida PORTC
    DDRA = 0x00; //se declara como entrada al portA   
    pinMode(button, INPUT_PULLUP); //boton para secuencia
    pinMode(button2, INPUT_PULLUP);
    pinMode(LEDT, OUTPUT);
    pinMode(LED_D, OUTPUT);
    lcd.init();
    lcd.backlight();
    lcd.setCursor(0,0);
    attachInterrupt(digitalPinToInterrupt(button2), inExt, RISING);
    Timer1.initialize(1000000);
    Timer1.attachInterrupt(timeIn);
}

void loop()
{
    int opc = 0, r = 0;
    digitalWrite(LEDT, 0);
    digitalWrite(LED_D, 0);
    PORTC = 0x00;
      while(digitalRead(button) == LOW)//hasta que se presione button de A1 actuara el ciclo
   { 
      lcd.setCursor(8,0);
      lcd.print("Menu");//se imprimen las opciones
      lcd.setCursor(2,2);
      lcd.print("A.Rota  B.Timer");
      delay(1500);
      lcd.setCursor(2,2);
      lcd.print("C.Ecua  D.Inten");
      delay(1500);
      lcd.clear();
   } 
   delay(200);
    opc = enter();
    switch (opc)
    {
      case 1:
            //ciclo de inicio hasta que el boton = 1
            flag2 = true;
            lcd.setCursor(5,0);
            lcd.print("POSICION:");
            while( digitalRead(button) == LOW) {
              PORTC = 0x01;
              for(cont2 = 0; cont2 < 8; cont2++){
                 show(cont2+1, 8, 1);
                 delay(500);
                 PORTC = PORTC << 1; //flujo a la izquierda de 1 bit << "1"
              }  
            }
            flag2 = false;     
            break;
      case 2:
            flag = !flag;
            while( digitalRead(button) == LOW) {}
            flag = !flag;
            break;
      case 3:
            int x = enter(), y = enter(), z = enter() ;
            PORTC = ((2 * (x * x) + (3 * y)) / z);
            show(((2 * (x * x) + (3 * y)) / z));
            while(digitalRead(button)== LOW){} //ciclo para apreciar resultado
            delay(200);
            break;
      case 4:
            int cont1 = 0;
            while( digitalRead(button) == LOW) {
              
              for(; cont1 <= 250; cont1 += 50){
                  show(cont1);
                  analogWrite(LED_D, cont1);
                  delay(300);
              }
              lcd.clear();
               for(; cont1 >= 0; cont1 -= 50){
                  show(cont1);
                  analogWrite(LED_D, cont1);
                  delay(300);
               }
              lcd.clear();
              delay(500);
            }
            break;

      default:
            PORTC = 0xFF; // si no es ninguna muestra FF Hex
            break;
      
    }
}

int enter()
{
  int num = 0;
  while(digitalRead(button) == LOW)
   {   
      for(int cont = 0; cont < 8; cont++)
      {
        bitWrite(num, cont, digitalRead(sw[cont])); // se almacena en num lo que hay en PORTA
        bitWrite(PORTC, cont, bitRead(num, cont)); // se muestra el numero ingresado otra forma PORTC = num;
      } 
   }
  delay(200);
  return num;
}

void timeIn()
{
  if(flag){
    cont ++;
    if (cont%5 == 0){
      digitalWrite(LEDT, LOW);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("LED Apagado:");
    }
    if (cont%7 == 0){
      digitalWrite(LEDT, HIGH);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("LED Encendido:");
      cont = 0;
    }
    lcd.setCursor(4,1);
    lcd.print(cont);
  }   
}

void inExt()
{
  if(flag2)
  {
    cont2++;
    for(int i = 0; i < 4; i++){
      digitalWrite(leds[cont2-1], LOW);
      cont2--;
      if(cont2 == 0)
        cont2 = 8;
      digitalWrite(leds[cont2-1], HIGH);
      lcd.setCursor(8,1);
      lcd.print(cont2+1);
      delay(300);
    }
  }
}
