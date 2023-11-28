#include <16f887.h> 
#include <def_887.h>
#fuses HS,NOWDT,NOPROTECT,NOLVP
#use delay(clock=20000000) 
#include <lcd_lib_4bit.c>
#use rs232(baud=9600,xmit=PIN_C6,rcv=PIN_C7) 
char value1;
#int_RDA
void RDA_interrupt(){ 
value1 = getc();
if (value1=='b') PORTe=0xff; if (value1=='t') PORTe=0x00;
} 
void main(){
   setup_timer_0(RTCC_INTERNAL|RTCC_DIV_1); 
   setup_timer_1(T1_DISABLED); 
   setup_timer_2(T2_DISABLED,0,1); 
   setup_comparator(NC_NC_NC_NC); 
   setup_vref(FALSE);
   trise=0x00; 
   ENABLE_INTERRUPTS(INT_RDA);
   enable_interrupts(GLOBAL);
    while (1) {}
}
