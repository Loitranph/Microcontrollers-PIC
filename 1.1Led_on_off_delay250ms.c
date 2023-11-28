#include <16F887.h> 
#include <def_887.h> 
#FUSES NOWDT, HS
#use delay(clock=20000000)

void main ()
{
   trise = 0x00; 
   porte = 0xff; 
   while (TRUE)
   {
      Porte = 0x00; 
      delay_ms(250); 
      Porte = 0xff; 
      delay_ms(250);
   }
}