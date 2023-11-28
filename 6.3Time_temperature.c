#define LCD_RS_PIN   PIN_D0 
#define LCD_RW_PIN         PIN_D1 
#define LCD_ENABLE_PIN PIN_D2 
#define LCD_DATA4      PIN_D3 
#define LCD_DATA5      PIN_D4 
#define LCD_DATA6      PIN_D5 
#define LCD_DATA7      PIN_D6 
#include <16F887.h>
#include <def_887.h> 
#device ADC=10
#fuses HS, NOWDT, NOPROTECT, NOLVP
#use delay(clock=20000000)
#use I2C(MASTER, I2C1, SLOW = 100000, STREAM = DS1307_STREAM)
#include <DS1307.c> 
#include <lcd.c> 
RTC_Time *mytime; 
int temp;
void rtc_print(){
   lcd_gotoxy(1,2);
   printf(lcd_putc, "TIME: %i:%i:%i", mytime->hours, mytime->minutes, mytime->seconds);}
void main(){
   lcd_init(); 
   lcd_putc('\f');
   setup_adc(adc_clock_internal); 
   set_adc_channel(3);
   delay_us(10);
   mytime = RTC_Get(); 
   rtc_print();
   mytime->hours = 10;
   mytime->minutes = 13;
   mytime->seconds = 12;
   RTC_Set(mytime);
   OSC_Enable();
   SQWE_Set(OUT_1Hz);
   while (true){
      mytime = RTC_Get(); 
      rtc_print(); 
      temp=read_adc(); 
      temp=temp/2.049; 
      lcd_gotoxy(1, 1); 
      delay_ms(100);
      printf(lcd_putc,"Nhiet do: %i oC ",temp);
    }
}
