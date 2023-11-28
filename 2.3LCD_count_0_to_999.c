#include <16f887.h>
#include <def_887.h>
#fuses HS, NOWDT, NOPROTECT, NOLVP
#use delay(clock=20000000)
#include <lcd_lib_4bit.c>
int16 i;
void main(){
   Output_low(LCD_RW);
   LCD_init();
   while(1){
for(i = 0; i<=999; i++){
      lcd_putcmd(0x80);
      Printf(lcd_putchar "%Lu", i);
      delay_ms(100);
      lcd_putcmd(0x01);
   }
  }
}
