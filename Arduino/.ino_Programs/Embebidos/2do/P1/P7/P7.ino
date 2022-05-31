#include <avr/io.h>

int sw[8] = {22, 23, 24, 25, 26, 27, 28, 29};//PORTA
int button = 2, sign = 49;//PORTC y boton

int enter();
int may(int, int);

void setup()
{
    
    DDRC = 0xFF; // se declara como salida PORTC
    DDRA = 0x00; //se declara como entrada al portA   
    pinMode(button, INPUT_PULLUP); //boton para secuencia
    pinMode(sign, OUTPUT); //led de negativo 
}

void loop()
{
    int opc = 0, r = 0;
    int *matriz;
    digitalWrite(sign, 0);
    PORTC = 0x01;
    while( digitalRead(button) == LOW) //ciclo de inicio hasta que el boton = 1
    {
      for(int cont = 0; cont < 7; cont++)
      {
        PORTC = PORTC << 1; //flujo a la izquierda de 1 bit << "1"
        delay(200);
      }  
      for(int cont = 8; cont > 1; cont--)
      {
        PORTC = PORTC >> 1; // flujo a la derecha de 1 bit >> "1"
        delay(200);
      }
      delay (500); //medio segundo para poder presionar el boton
    }     
    PORTC = 0x00;
    delay(200); 
    opc = enter();
    if(opc!=4) //arreglo de 2
    {
      matriz = new int[2];
      for (int cont = 0; cont < 2; cont++) //se ingresan los 2 valores
           matriz[cont] = enter();
    }
    else //arreglo de 1
    {
      matriz = new int [1]; // se ingresa su unico valor
      matriz[0] = enter();
    }
      
    switch (opc)
    {
      case 0:
            r = matriz[0] + matriz[1]; //suma de los 2 valores
            PORTC = r; //se muestra
            break;
      case 1:
            if (max(matriz[0], matriz[1]) == matriz[0])//se analiza cual es ma grande
            {
              r = matriz[0] - matriz[1];
            }
            else
            {
              r = matriz[1] - matriz[0];//valor negativo
              digitalWrite(sign, HIGH);
            }
            PORTC = r;
            break;
      case 2:
            r = matriz[0] * matriz[1]; //multiplicacion
            PORTC = r;
            break;
      case 3:
            r = matriz[0] / matriz[1]; //div
            PORTC = r;
            break;
      case 4:
            for(int cont = matriz[0]; cont <= 99; cont++) //muestra del valor decimal Y al valor decimal 99
            {
              PORTC = cont;
              delay(500);
            }
                
            break;
      case 5:
            PORTC = 0x00;
            delay(500);
            PORTC = max(matriz[0], matriz[1]); //se muestra el mayor
            break;
      default:
            PORTC = 0xFF; // si no es ninguna muestra FF Hex
            break;
      
    }
    while(digitalRead(button)== LOW){} //ciclo para apreciar resultado
    delay(200);
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
