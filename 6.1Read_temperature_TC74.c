#include <16f887.h> 
#include <def_887.h>
#fuses HS,NOWDT,NOPROTECT,NOLVP
#use i2c(Master, sda = PIN_C4, scl=PIN_C3) 
#use delay(clock=20000000)
#include <lcd_lib_4bit.c> 
int temp;
void main(){
   output_low(LCD_RW); 
   LCD_init();
   while(true)
   {
      lcd_putcmd(0x80); 
      lcd_putcmd(0x01);//xoa man hinh delay_ms(100);
      i2c_start(); 
      i2c_write(0x90);
      i2c_write(0x00); 
      i2c_start(); 
      i2c_write(0x91); 
      temp=i2c_read(0); 
      i2c_stop();
      Printf(lcd_putchar,"nhiet do :%i oC",temp); 
      delay_ms(1000);
    }
}

