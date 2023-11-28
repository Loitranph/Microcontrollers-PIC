#define LCD_RS_PIN     PIN_D0 
#define LCD_RW_PIN     PIN_D1 
#define LCD_ENABLE_PIN PIN_D2 
#define LCD_DATA4      PIN_D3 
#define LCD_DATA5      PIN_D4 
#define LCD_DATA6      PIN_D5 
#define LCD_DATA7      PIN_D6 
#include <16F887.h>
#fuses HS, NOWDT, NOPROTECT, NOLVP
#use delay(clock = 8MHz)
#use I2C(MASTER, I2C1, SLOW = 100000, STREAM = DS1307_STREAM)
#include <lcd.c> 
#include <DS1307.c> 
RTC_Time *mytime;
void rtc_print(){
   lcd_gotoxy(1, 1);
   printf(lcd_putc, "TIME: %02u:%02u:%02u",mytime->hours, mytime->minutes, mytime->seconds);
   lcd_gotoxy(1, 2);
   printf(lcd_putc, "DATE: %02u/%02u/20%02u", mytime->day, mytime->month, mytime->year);}
void main(){
   lcd_init(); 
   lcd_putc('\f');
   mytime = RTC_Get(); 
   rtc_print();
   mytime->hours = 10;
   mytime->minutes = 13;
   mytime->seconds = 12;
   mytime->day = 16;
   mytime->month = 12;
   mytime->year = 21;
   RTC_Set(mytime);
   OSC_Enable();
   SQWE_Set(OUT_1Hz);
   while(TRUE){
      mytime = RTC_Get(); 
      rtc_print();
   }
}
