#include <16f877a.h>
#fuses XT,NOLVP,NOWDT,NOPROTECT
#use delay(clock=4000000) 
#define IN1 PIN_B6 
#define IN2 PIN_B7 
#define Up   PIN_A0 
#define Down PIN_A1 
#define  Dir   PIN_A2 
int16 duty_cycle=512;
void main(){
   setup_adc(ADC_OFF); 
   setup_adc_ports(NO_ANALOGS); 
   output_high(IN1);
   output_low (IN2);

   /* PWM Configurations */ 
   setup_timer_2(T2_DIV_BY_1,255,1); 
   setup_ccp1(CCP_PWM); 
   set_pwm1_duty(512L);

   while(true) {
      while(input(Up) && input(Down) && input(Dir));
      if(!input(Up))
      { duty_cycle+=64; 
         set_pwm1_duty(duty_cycle);}
      if(!input(Down))
      { duty_cycle-=64; 
         set_pwm1_duty(duty_cycle);}
      if(!input(Dir))
         {output_toggle(IN1); 
            output_toggle(IN2);}
      delay_ms(500);}
}
