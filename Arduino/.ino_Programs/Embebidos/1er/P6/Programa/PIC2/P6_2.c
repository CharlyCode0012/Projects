#include <16F877A.h>
#fuses NOWDT, XT
#use delay (clock=4M)

#byte TRISC = 0x87
#byte PORTC = 0x07
#byte PORTD = 0x08
#byte TRISD = 0x88

#include <lcd.c>
#include <string.h>
#use RS232(BAUD = 62500, XMIT = PIN_C6, RCV = PIN_C7, bits = 8)   //baudios 62500 bits por seg, Tx= c6    Rx = C7

int Celsius1;

#INT_RDA
void rutinaSerial()
{
   Celsius1 = getc();
}

void main()
{
   lcd_init();
   enable_interrupts(INT_RDA); //se activa la interrupcion por recibo de datos den el puerto Rx
   enable_interrupts(GLOBAL);
   while(true)
   {
      lcd_putc('\f');
      lcd_gotoxy(2, 1);
      printf(lcd_putc, ":Temp: %d C", Celsius1);
      lcd_gotoxy(1, 2);
      if(Celsius1 > 25)
      {
         printf(lcd_putc, "Paso el limite");
      }
      else
          printf(lcd_putc, "Bajo el limite");
      delay_ms(100);
   }
}
