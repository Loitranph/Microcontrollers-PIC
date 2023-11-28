#include <16F887.h>
#include <def_887.h> #FUSES NOWDT, HS
#use delay(clock=20000000)
#include <lcd_lib_4bit.c>
#int_ext
void main()
{
   Output_low(LCD_RW); LCD_init();
   while(true)
   { 
      lcd_SetPosition(0x80); 
      printf(lcd_putchar,"TRAN PHUOC LOI");
      lcd_SetPosition(0xC2);
      printf(lcd_putchar,"2101076");
      delay_ms(2000);
      lcd_putcmd(0x01);
   }
}
