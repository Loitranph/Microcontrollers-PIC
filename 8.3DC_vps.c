#include <16f877a.h>
#fuses XT,NOLVP,NOWDT,NOPROTECT
#use delay(clock=4000000) 
#define Wire1 PIN_B6 
#define Wire2 PIN_B7 
#define Up   PIN_A0 
#define Down PIN_A1 
#define Dir PIN_A2 
#include <lcd_lib_4bit.c> 
int8 duty_cycle=255;
void main(){
   Output_low(LCD_RW); 
   LCD_init();
   setup_adc(ADC_OFF); 
   setup_adc_ports(NO_ANALOGS); 
   output_high(Wire1);
   output_low (Wire2);
   /* PWM Configurations */ 
   setup_timer_2(T2_DIV_BY_1,255,1); 
   setup_ccp1(CCP_PWM); 
   set_pwm1_duty(255L);
   while(true) {
      while(input(Up) && input(Down) && input(Dir));
      if(!input(Up))
      { duty_cycle+=85; 
      set_pwm1_duty(duty_cycle); }
      if(!input(Down))
      { duty_cycle-=85; 
      set_pwm1_duty(duty_cycle); }
      if(!input(Dir))
      { output_toggle(Wire1); 
      output_toggle(Wire2); }
      delay_ms(500);
      lcd_putcmd(0x85); 
      lcd_putcmd(0x01);//xoa man hinh
      Printf(lcd_putchar,"Toc do: %2u",duty_cycle);}
}
