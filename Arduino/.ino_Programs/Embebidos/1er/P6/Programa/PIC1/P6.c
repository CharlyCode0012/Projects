#include <16F877A.h>
#fuses NOWDT, HS, NOLVP
#device ADC=10
#use delay (clock=4M)

#byte TRISA=0x85
#byte PORTA=0x05
#byte TRISC=0x87
#byte PORTC=0x07
#byte TRISD=0x88
#byte PORTD=0x08

#use RS232(BAUD = 62500, XMIT = PIN_C6, RCV = PIN_C7, bits = 8)   //baudios 62500 bits por seg, Tx= c6    Rx = C7
#include <lcd.c>
#include <string.h>
//#use fast_io(A)
//#use fast_io(C)
//#use fast_io(D)

void main()
{
  int Celsius;
  setup_adc(ADC_CLOCK_INTERNAL);                 // ADC Module uses its internal oscillator
  setup_adc_ports(AN0);                          // Configure AN0 pin as analog
  set_adc_channel(0);                            // Select channel 0 (AN0)
  lcd_init();                                    // Initialize LCD module
  lcd_putc('\f');                                // Clear LCD
  while(TRUE){
    delay_ms(1000);
    lcd_putc('\f'); 
    Celsius = read_adc() * 0.489;                 // Read analog voltage and convert it to Kelvin (0.489 = 500/1023)    
    printf(lcd_putc, "%d C", Celsius);
    
    putc(Celsius);
  }
}
