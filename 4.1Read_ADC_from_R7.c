#include <16F887.h> 
#include <def_887.h> 
#device ADC=10 
#FUSES NOWDT, HS
#use delay(clock=20000000) 
#include <lcd_lib_4bit.c> 
int16 adc;
void main(){ 
   output_low(lcd_rw);
   LCD_Init(); 
   setup_adc(adc_clock_internal); set_adc_channel(3);
   delay_us(10);
   while (true)
   {
      adc=read_adc(); 
      lcd_putcmd(0x01); 
      delay_ms(100); 
      printf(lcd_putchar,"GIA TRI ADC LA:");
      lcd_putcmd(0xC0); printf(lcd_putchar,"%04lu",adc); 
      delay_ms(1000);
   }
}
