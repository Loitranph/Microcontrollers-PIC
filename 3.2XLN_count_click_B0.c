#include <16F887.h> 
#include <def_887.h> 
#FUSES HS
#use delay(clock=20000000) 
#include <lcd_lib_4bit.c> 
#int_ext
int dem=0;
#bit sw1=0x06.0 
ext_isr(){
porte=~porte;}
void main() { 
   trisB = 0x03;
   Port_B_pullups (1 ); 
   trise = 0x00; 
   porte=0b00000000;
   enable_interrupts(int_EXT); 
   ext_int_edge(H_TO_L); 
   enable_interrupts(GLOBAL); 
   Output_low(LCD_RW); 
   LCD_init();
   while (1) { 
      if(sw1==0){
      dem++;}
      lcd_putcmd(0x88); 
      lcd_putcmd(0x01);//xoa man hinh 
      printf(lcd_putchar,"SolanNhan:");
      lcd_setposition(0x8a); 
      Printf(lcd_putchar,"%d", dem ); 
      delay_ms(1000);
   }
}
