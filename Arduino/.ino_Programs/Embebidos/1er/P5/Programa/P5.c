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

#use fast_io(A)
#use fast_io(B)
#use fast_io(C)
#use fast_io(D)
int veces, Seg;
byte CONST display[] = {0x74,0x5C,0x38,0x77,0X00,0X7C,0x3E,0x79,0x37,0X00,0x5E,0x30,0x77};
byte CONST display2[] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};

#INT_RTCC //Timer0
void Reloj()
{
   veces--;
   Set_RTCC(220);
   if(veces==0)
   {
      veces = 10;
      Seg+=2;
      if(Seg == 2)
         bit_set(PORTD,0);
      if(Seg == 4)
      {
         bit_clear(PORTD,0);
         Seg = 0;
      }
   }
}

#INT_EXT
void Inter_Ext()
{
   for(unsigned int cont = 0; cont < 13; cont++)
   {
      PORTC=display[cont];
      delay_ms(500);
   }
}

void main()
{
   int cont2=0;
   TRISA = TRISB = 0x01;
   TRISC = TRISD = 0;
   PORTD = PORTC = 0;
   veces = 10;
   Seg = 0;
   SET_RTCC(220); //0-256 220-221-222-223-255-256
   SETUP_TIMER_0(RTCC_INTERNAL|RTCC_DIV_256|RTCC_8_bit);
   ENABLE_INTERRUPTS(INT_RTCC);          //Activa interrupcion del timer
   ENABLE_INTERRUPTS(INT_EXT); 
   ENABLE_INTERRUPTS(GLOBAL);            //activa todas las interrupciones
   while(true)
   {
      PORTC=display2[cont2];
      cont2++;
      if(cont2 == 10)
         cont2 = 0;
      delay_ms(200);
   }
}
