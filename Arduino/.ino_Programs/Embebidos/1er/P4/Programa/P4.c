#include <16F877.h>
#fuses NOWDT, XT
#use delay (clock=4M)
#byte TRISA=0x85
#byte PORTA=0x05
#byte TRISB=0x86
#byte PORTB=0x06
#define use_portb_kbd true
#define button PIN_A0
#use fast_io(A)
#use fast_io(B)

#include <kbd4x4.c>
#include <lcd.c>
#include <stdio.h>


void show1(float Valor, int CoorX = 1, int CoorY = 2)// funcion para imprimir
{
    lcd_putc("\f");
    lcd_gotoxy(CoorX, CoorY);
    printf(lcd_putc, "%f", Valor);
    delay_ms(500);
}

float ingresar()
{
   float value=0;//valor a retornar
   char c; 
   int X3 = 1, temp=0;//coordenada X y valor temporal
   c = kbd_getc();
   printf(lcd_putc, c);
   While( c =='\0' || c < 58 ||c > 47)
   {
      delay_us(10);
      c = kbd_getc();
      if( c !='\0' && c < 58 && c > 47){
         
         lcd_gotoxy(X3,2);
         printf(lcd_putc,"%c", c);
         temp = c - 48 ; //se le resta a c el valor ascii de 48 --> '0'
         value = (value * 10.00) + temp; //se le ingresa el valor ingresado y se multiplica x10 para que funcione
                                         //ejemplo (0*10)+1---> (1*10)+2, esto quiere decir que se ingreso primero el 1 y luego el 2 y te da 12
         X3++;//se le suma uno a la coordenada X
      }
      if(c == '#')
         break;     
   }
   show1(value);//se muestra el valor ingresado
   delay_ms(100);
   lcd_putc("\f");//se limpia la pantalla
   return value;
}

void menu(char OPC)
{
   float promedio = 0, X1=0, Y1=0, Z1=0;
   lcd_gotoxy(8,1);
   printf(lcd_putc,"%c", Opc);
   delay_ms(1000);
    switch(OPC)
  {
    case '0':
         float Y3 = 1;
         show1(Y3);
         for(unsigned int cont   =  0;   cont  <=   15;   cont++)
         { 
            show1(Y3, cont+1);//funcion para mostrar valor en PuertoC
         }
         break;
    case '1':
         X1 = ingresar();//num1
         Y1 = ingresar();//num2
         Z1 = ingresar();//num3
         promedio = (X1 + Y1 + Z1)/3;
         show1(promedio);
         break;
    case '2':
         X1 = ingresar();
         Y1 = ingresar();
         Z1 = ingresar();
         show1(0);//se muestra el 0 para que haya un reset.
         if(X1  >= Y1  && X1  >= Z1 )
           Show1(X1);//num1 mayor
         else
             if(Y1  >= Z1)
                show1(Y1);//num2 mayor
             else
                show1(Z1);//num3 mayor
         break;
    case '3':
         printf(lcd_putc, "00");
         delay_ms(500);
         for(unsigned int cont_1 = 0; cont_1 <= 2; cont_1++)//ciclo para aumentar decenas
           { 
             lcd_gotoxy(1,2);
             printf(lcd_putc, "%d", cont_1);           
             for(unsigned int cont_2 = 0; cont_2 < 10; cont_2+=2)//ciclo para aumentar unidades
             {
               lcd_gotoxy(2,2);
               printf(lcd_putc, "%d", cont_2);//se imprime la unidad
               delay_ms(400);//delay
             }
           }
         break;
    case '4':
         X1 = ingresar();
         Y1 = ingresar();
         lcd_gotoxy(1,2);
         if(X1 == Y1 )//son iguales innecesario seguir
         {
            show1(X1);
            break;
         }
         if(X1>=Y1)
         {
          
            while(X1 >= Y1)//como x es mayor se recquiere drementar
            {
               show1(X1);
               X1 -= 1;
            }
         
         }else
         {
            while(X1 <= Y1)//como x es menor se recquiere incrementar
            {
               show1(X1);
               X1 += 1;
            }
         }
         break;
    case '5':
         X1 = ingresar();
         Y1 = ingresar();
         lcd_gotoxy(1,2);
         float Va1= X1*X1, Va2 = Y1*2;//se le dan los valores de la ecuacion 
         if( Va1< Va2)//se compara cual valor es mayor para as? poner un signo menos
         {        
             printf(lcd_putc, "-%f",Va2-Va1);//negativo
         }
         else
         {
            show1(Va1 - Va2);//positivo
         }
         break;
    default:
         show1(0xFF);//FF si no corresponde a algun caso anterior
         break;
  }
}

void main()
{
   char Opc = '\0';//valor nulo
   set_tris_d(0); 
   lcd_init();
   kbd_init();             //inicializacion del teclado
   port_b_pullups(true);   //porteccion para el teclado Hex
   TRISA = TRISB = 0xFF;
   PORTB = PORTA  = 0;
   while(!input(button))//hasta que se presione button de A1 actuara el ciclo
   { 
      lcd_gotoxy(8,1);
      printf(lcd_putc, "Menu");//se imprimen las opciones
      lcd_gotoxy(1,2);
      printf(lcd_putc, "0.Rota  1.Prome");
      delay_ms(1000);
      lcd_gotoxy(1,2);
      printf(lcd_putc, "2.NuMa  3.Pares");
      delay_ms(1000);
      lcd_gotoxy(1,2);
      printf(lcd_putc, "4.X a Y  5.Ecua");
      delay_ms(1000);
      lcd_putc("\f");
   }
   Opc=kbd_getc();
   while(Opc =='\0')
   { 
     delay_us(10);
     Opc = kbd_getc();//se captura la opcion ingresada
   }
   lcd_putc("\f");
   menu(Opc);//llama a la funcion menu.
}
