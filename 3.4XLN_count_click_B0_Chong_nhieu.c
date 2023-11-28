#include <16F887.h> 
#include <def_887.h> 
#FUSES NOWDT, HS
#use delay(clock=20000000) 
#int_rb
ngat(){
if(rb0==0){
delay_ms(20); 
porte=~porte;
}
else rb0=1;
}
void main(){ trisb=0xff; 
   Port_B_pullups(1); 
   trise=0x00;
   porte=0x00;
   enable_interrupts(int_rb); 
   ext_int_edge(H_TO_L); 
   enable_interrupts(GLOBAL); 
   while(true){}
}
