//
// Created by Aurelien on 04/12/2019.
//

#include "timer.h"
#include<avr/io.h>
#define LED PD4
#define prescaler_8bits 64
#define val_mili_8bits 204

int main()
{
	 uint8_t timerOverflowCount=0;
	 DDRD=0xff;         //configure PORTD as output
	 TCNT0=0x00;
   switch(prescaler_8bits){
     case 1 :
        TCCR0 = (1<<CS00) | (0<<CS01) | (0<<CS02);
        break;
     case 8 :
        TCCR0 = (0<<CS00) | (1<<CS01) | (0<<CS02);
        break;
    case 32 :
       TCCR0 = (1<<CS00) | (1<<CS01) | (0<<CS02);
       break;
   case 64 :
      TCCR0 = (0<<CS00) | (0<<CS01) | (1<<CS02);
      break;
     case 128 :
        TCCR0 = (1<<CS00) | (0<<CS01) | (1<<CS02);
        break;
    case 256 :
       TCCR0 = (0<<CS00) | (1<<CS01) | (1<<CS02);
       break;
    case 1024 :
       TCCR0 = (0<<CS00) | (1<<CS01) | (1<<CS02);
       break;
    default :
      TCCR0 = (0<<CS00) | (0<<CS01) | (0<<CS02);

   }

	while(1)
	{
		 while ((TIFR & 0x01) == 0);
		  TCNT0 = 0x00;
		  TIFR=0x01; //clear timer1 overflow flag
		 timerOverflowCount++;
		 if (timerOverflowCount>=6)
		 {
			 PORTD ^= (0x01 << LED);
			 timerOverflowCount=0;
		 }
	}
}

void timer_8bits_init() {
  uint8_t timerOverflowCount=0;
  DDRD=0xff;         //configure PORTD as output
  TCNT0=0x00;
  switch(prescaler_8bit){
    case 1 :
       TCCR0 |= (1<<CS00) | (0<<CS01) | (0<<CS02);
       break;
    case 8 :
       TCCR0 = (0<<CS00) | (1<<CS01) | (0<<CS02);
       break;
   case 64 :
      TCCR0 = (1<<CS00) | (1<<CS01) | (0<<CS02);
      break;
    case 256 :
       TCCR0 = (0<<CS00) | (0<<CS01) | (1<<CS02);
       break;
   case 1024 :
      TCCR0 = (1<<CS00) | (0<<CS01) | (1<<CS02);
      break;
   default :
     TCCR0 = (0<<CS00) | (0<<CS01) | (0<<CS02);
  }
}
