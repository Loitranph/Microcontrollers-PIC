#include <16F887.h> 
#include <def_887.h> 
#fuses HS
#use delay(clock=2000000) 
#include <lcd_lib_4bit.c> 
int8 nutnhan;
#int_timer0
void main(void){ 
   Output_low(LCD_RW); 
   LCD_init();
   setup_timer_0(T0_EXT_L_TO_H|T0_DIV_1); 
   set_timer0(0);
   LOOP:
   nutnhan=GET_TIMER0(); 
   if (nutnhan == 1 )
   {+nutnhan;}
   {lcd_putcmd(0x80); 
   Printf(lcd_putchar, "So lan bam:" ); 
   Printf(lcd_putchar,"%02d ", nutnhan );
   }
   while(true){
   goto LOOP;
   }
}
