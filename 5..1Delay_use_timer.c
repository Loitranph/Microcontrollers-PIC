#include <16F887.h> 
#include <def_887.h>
#fuses NOWDT,PUT,XT,NOPROTECT 
#use delay(clock=2000000) 
#byte PORTB = 0x06
int16 count; 
#int_timer0
void interrupt_timer0(){
set_timer0(6);
++count;
if(count == 2000){
count=0; porte=~porte;
}
}
void main(void){
   trise = 0x00; 
   enable_interrupts(int_timer0);
setup_timer_0(RTCC_INTERNAL|RTCC_DIV_2); 
   enable_interrupts(global);
   set_timer0(6); 
   porte=0x00; 
   while(true){}
}
