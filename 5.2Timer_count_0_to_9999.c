#include <16F887.h> 
#include <def_887.h> 
#fuses HS
#use delay(clock=2000000) 
#include <lcd_lib_4bit.c> 
int16 count;
int16 sodem; 
#int_timer0
void interrupt_timer0(){ 
   set_timer0(6);
   ++count;
   if(count == 2000){
   count=0;
   ++sodem;}
   if(sodem == 10000)
   {sodem = 0;}
}
void main(void) { 
   Output_low(LCD_RW);  LCD_init(); enable_interrupts(int_timer0);
   setup_timer_0(RTCC_INTERNAL|RTCC_DIV_2); 
   enable_interrupts(global);
   set_timer0(6); // T_dinhthi = 2*(256 - 6)*1us = 500us 
   while(true) {
   lcd_putcmd(0x80); Printf(lcd_putchar," So lan dem:" );{
   lcd_putcmd(0x8c); Printf(lcd_putchar,"%lu", sodem ); }
   }
}
