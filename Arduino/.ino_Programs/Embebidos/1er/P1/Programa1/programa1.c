#include <16F877.h>
#fuses NOWDT, XT
#use delay (clock=4M)
#byte TRISA=0x85
#byte PORTA=0x05
#byte TRISB=0x86
#byte PORTB=0x06
#byte TRISC=0x87
#byte PORTC=0x07
#byte TRISD=0x88
#byte PORTD=0x08

#define button PIN_A0

#use fast_io(A)
#use fast_io(B)
#use fast_io(C)
#use fast_io(D)


void show1(unsigned int Value)
{
    PORTC=Value;//muestra el valor pasado
    delay_ms(500);
}

void enter(unsigned int& Num)
{
    while(!input(button))//bandera para poder ingresar numeros
         {
            Num = PORTC = PORTB;
         }
          delay_ms(500);
}

void menu(unsigned int OPC)
{
unsigned int Promedio = 0, X1=0, Y1=0, Z1=0;
    switch(OPC)
  {
    case 0:
         byte X2=0x05;
         show1(X2);
         for(unsigned int cont   =  0;   cont  <=   15;   cont++)
         {
            rotate_right(&X2,1);
            show1(X2);//funcion para mostrar valor en PuertoC
         }
         break;
    case 1:
         enter(X1);//funcion input 
         enter(Y1);
         enter(Z1);
         
         Promedio = (X1 + Y1 + Z1)/3;
         show1(Promedio);
         break;
    case 2:
         enter(X1);
         enter(Y1);
         enter(Z1);
         show1(0);
         if(X1  >= Y1  && X1  >= Z1 )
           Show1(X1);
         else
             if(Y1  >= Z1)
                show1(Y1);
             else
                show1(Z1);
         break;
    case 3:
         byte Y2=0;//creacion de un byte para una secuencia m?s sencilla
         while( Y2 <= 0x90 )
         {
            PORTC=Y2;
            delay_ms(300);
            Y2+=0x02;//se incrementa en 2 para solo mostrar pares
         }
         break;
    case 4:
         enter(X1);
         enter(Y1);
         if(X1 == Y1)//son iguales innecesario seguir
         {
            show1(X1);
            break;
         }
         if(X1 > Y1)//se analiza cual es mayor para asi saber que secuencia tendra
         {
            while(X1 >= Y1)
            {
               show1(X1);//ya que x es mayor se requiere decrementar
               X1--;
            }
         }
         else
         {
            while(X1 <= Y1)//como x es menor se recquiere incrementar
            {
               show1(X1);
               X1++;
            }
         }
         break;
    case 5:
         enter(X1);
         enter(Y1);
         
         int result = 0;
         int Va1= X1; //& 0x00011111;//mascara de 4 bits
         int Va2= Y1;//& 0x00011111;
         result = (Va1 * Va1)-(Va2*2);
        
         if( (Va1 * Va1)< (Va2*2))
         {
                  result = (Va2*2)-(Va1 * Va1);
                  bit_set(PORTD, 0);//signo negativo
         }
         show1(result);
         break;
    default:
         show1(0xFF);//FF si no corresponde a algun caso anterior
         break;
  }
}


void main()
{
unsigned int Opc=0;
  TRISA = TRISB = 0xFF;
  TRISC = TRISD = 0;
  PORTB = PORTA = PORTD = 0;
  while(!input(button))//ciclo para indicar al usuario el inciio del programa
   { 
     delay_ms(500);
     PORTC=0xFF;
     delay_ms(1000);
     PORTC=0x00;
   }
     delay_ms(500);
   enter(Opc); //se ingresa opcion de menu
   menu(Opc);//llama a la funcion menu.
}
