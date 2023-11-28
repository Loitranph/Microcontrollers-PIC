#include <16f887.h> 
#include <def_887.h>
#fuses HS,NOWDT,NOPROTECT,NOLVP
#use delay(clock=20000000) 
#include <lcd_lib_4bit.c> 
#define PIN_TRIGGER PIN_A3 int1 echo = 0;
int16 value = 0; void Trigger(){
output_high(PIN_TRIGGER); delay_us(12);
output_low(PIN_TRIGGER);}
#int_CCP1
void CCP1_isr(void){
if(echo == 1){
setup_ccp1(CCP_CAPTURE_FE); // falling fulse set_timer1(0);
echo = 0}
else{
setup_ccp1(CCP_CAPTURE_RE); // rising fulse value = CCP_1;
echo = 1;}}
void main(){
   output_low(LCD_RW); LCD_init(); 
   setup_adc_ports(NO_ANALOGS);
   setup_timer_1(T1_INTERNAL|T1_DIV_BY_4);
   setup_ccp1(CCP_CAPTURE_RE); // raising fulse enable_interrupts(INT_CCP1);
   enable_interrupts(GLOBAL);
   float distance = 0; 
   while(TRUE){
   Trigger(); 
   while(echo == 0){}
   distance = value * 0.8 / 58; 
   lcd_putcmd(0x85); 
   lcd_putcmd(0x01);//xoa man hinh
   printf(LCD_PutChar, "KHOANG CACH : "); 
   lcd_putcmd(Line_2);
   printf(LCD_PutChar, "%fcm", distance); 
   delay_ms(100);}
}
