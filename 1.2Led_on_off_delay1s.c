#include <16F887.h> 
#include <def_887.h> 
#FUSES NOWDT, HS
#use delay(clock=20000000) 
void led_E0()
{
   output_high(PIN_E0); 
   delay_ms(500); 
   output_low(PIN_E0); 
   delay_ms(500);
}
void main ()
{
   trise = 0x00; 
   porte = 0xff; 
   while (TRUE)
   {
      Porte = 0x00; led_E0();       
      output_high(PIN_E1); 
      led_E0();
   }
}
