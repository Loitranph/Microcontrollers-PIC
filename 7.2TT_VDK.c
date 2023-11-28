#include <16F877A.h>
#device PIC16F877*=16 ADC=10                              
#fuses hs, nowdt, noprotect, nolvp, put, brownout
#use delay(clock=20000000)
#use rs232(baud=9600,parity=N,xmit=PIN_C6, rcv=PIN_C7,bits=8)
#define use_portb_lcd true
#include <LCD.c>
char data;
int i;
#int_rda
void serial_isr()
{
   data=getc();
   putc(data);
   i=1;   
}
void main() 
{ 
  lcd_init();
  enable_interrupts(global);
  enable_interrupts(int_rda);
while(TRUE) 
  {
      if(i==1) // if interrupt occured 
      { 
         i=0; 
         printf(lcd_putc,"%c",data); 
      } }
}
