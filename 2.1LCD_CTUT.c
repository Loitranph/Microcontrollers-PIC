#include <16F887.h> 
#include <def_887.h> 
#FUSES NOWDT, HS
#use delay(clock=20000000) 
#include <lcd_lib_4bit.c> 
void main()
{
  Output_low(LCD_RW); 
  LCD_init();
  while(1)
  {
   lcd_putcmd(0x85); 
   Printf(lcd_putchar,"DAI HOC");
   lcd_putcmd(0xC2);
   Printf(lcd_putchar,"KTCN CAN THO"); 
   delay_ms(1000);
   lcd_putcmd(0x01); 
  }
}
