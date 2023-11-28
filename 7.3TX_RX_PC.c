#include <16f887.h> 
#include <def_887.h>
#fuses HS,NOWDT,NOPROTECT,NOLVP
#use i2c(Master, sda=PIN_C4, scl=PIN_C3) //Khai bao dung I2C
#use delay(clock=20000000)
#use rs232(baud=9600,xmit=PIN_C6,rcv=PIN_C7) //Khai bao dung RS232
#include <lcd_lib_4bit.c>
int temp;//Bien temp luu gia tri nhiet do
void main(){
   output_low(LCD_RW);
   LCD_init(); //Khoi tao LCD
   while(true){
      i2c_start(); //Bat dau qua trình giao tiep
      i2c_write(0x90); //Dia chi cua TC74
      i2c_write(0x00); //Bat dau doc
      i2c_start();
      i2c_write(0x91); //Truy xu?t gia tri nhiet do
      temp=i2c_read(0); //Bat dau qua trinh doc va gan bao bien temp
      i2c_stop(); //Ket thuc qua trình doc
      printf("%d\n",temp);//Gui gia tri nhiet do len PC
      lcd_putcmd(0x80);
      lcd_putcmd(0x01);//xoa man hinh delay_ms(100)
      delay_ms(100);
      Printf(lcd_putchar,"Nhiet do: %d oC",temp); //Xuat ra LCD
      delay_ms(1000);
   }
}
