#include <16f887.h> 
#include <def_887.h>
#fuses HS,NOWDT,NOPROTECT,NOLVP
#use delay(clock=20000000) 
#int_ext
ext_isr(){
   set_tris_c(0xf9); 
   output_c(0);
   setup_timer_2(t2_div_by_4,124,1); 
   setup_ccp1(ccp_pwm); 
   set_pwm1_duty(125);
}
void main(){
   trisb = 0xff; 
   Port_B_pullups (1 ); 
   enable_interrupts(int_ext); 
   ext_int_edge(H_TO_L);
   enable_interrupts(GLOBAL); 
   while (true) {}
}
