#include <16F887.h>
#include <def_887.h>
#FUSES NOWDT, HS, NOPUT, NOPROTECT, NODEBUG,
NOBROWNOUT,NOLVP NOCPD, NOWRT
#use delay(clock=20000000)
#include <lcd_lib_4bit.c>
int16 gtB3=0, gtB4=0, gtB5=0; 
void main() {
   Output_low(LCD_RW);
   LCD_init();
   trisb= 0xff; //port A la input
   Port_B_pullups (1);
   while (1) {
   if(Input(PIN_B3)==0){
   gtB3++;
   }
   if(Input(PIN_B4)==0){
   gtB4++;
   }
   if(Input(PIN_B5)==0){
   gtB5++;
   }
   lcd_putcmd(0x82);
   Printf(lcd_putchar "B3 B4 B5");
   lcd_putcmd(0xC2);
   Printf(lcd_putchar "%Lu", gtB3);
   lcd_putcmd(0xC7);
   Printf(lcd_putchar "%Lu", gtB4);
   lcd_putcmd(0xCC);
   Printf(lcd_putchar "%Lu", gtB5);
   delay_ms(2000);
   lcd_putcmd(0x01);}
}
