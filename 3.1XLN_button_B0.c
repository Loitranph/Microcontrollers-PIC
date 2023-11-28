#include <16F887.h> 
#include <def_887.h> 
#FUSES NOWDT, HS
#use delay(clock=20000000) 
#int_ext
ext_isr()
{
porte=~porte;
}
void main(){ trisb=0xff; 
Port_B_pullups(1); 
trise=0x00; 
porte=0x00;
enable_interrupts(int_EXT); 
ext_int_edge(H_TO_L); 
enable_interrupts(GLOBAL);
 while(true){}
}
