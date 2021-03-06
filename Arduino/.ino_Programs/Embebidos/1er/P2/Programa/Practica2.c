#include <16F877.h>
#fuses XT, NOWDT, PUT
#use delay (clock=4M)
#define use_portb_kbd true
#byte TRISA=0x85
#byte PORTA=0x05
#byte TRISB=0x86
#byte PORTB=0x06
#byte TRISC=0x87
#byte PORTC=0x07
#define button PIN_A0

#use fast_io(A)
#use fast_io(B)
#use fast_io(C)

#include <kbd4x4.c>
#include <stdio.h>

char enter()
{
   char c='\0';
   c=kbd_getc();
   while(c=='\0')
   { 
     delay_us(10);
     c = kbd_getc();
   }
   return c;
}

void main()
{
char Key, Pass1[6] ={"00000"}, Pass[5]={'2','2','5','5'};
int cont=0;
   kbd_init();             //inicializacion del teclado
   port_b_pullups(true);   //porteccion para el teclado Hex
   TRISA = TRISB = 0xFF;
   TRISC = 0;
   PORTB = PORTA  = 0;
   while(!input(button))//ciclo para indicar al usuario el inciio del programa
   { 
     delay_ms(1000);
     PORTC=0xFF;
     delay_ms(500);
     PORTC=0x00;
   }
     delay_ms(500);
   while( cont < 4)
   {
       Key=enter();
       Pass1[cont]=Key;
       cont++;
       delay_ms(500);
   }
     
   Pass1[4]='\0';
   
   if(strcmp(Pass, Pass1) == 0)
   {
     bit_set(PORTC, 7);
   }
   else
   {
      bit_set(PORTC,0);
   }
}
