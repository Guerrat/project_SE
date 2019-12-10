//
// Created by Aurelien on 04/12/2019.
//

#include "timer.h"
#include<avr/io.h>


void timer0_8bits_init(int prescaler_8bits) {
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
}

void timer1_16bits_init(int prescaler_16bits) {
  // DDRD=0xff;         //configure PORTD as output
	TCNT1=0;
	switch(prescaler_16bits){
		case 1 :
			 TCCR1B = (1<<CS10) | (0<<CS11) | (0<<CS12);
			 break;
		case 8 :
			 TCCR1B = (0<<CS10) | (1<<CS11) | (0<<CS12);
			 break;
	 case 64 :
			TCCR1B = (1<<CS10) | (1<<CS11) | (0<<CS12);
			break;
	case 256 :
		 TCCR1B = (0<<CS10) | (0<<CS11) | (1<<CS12);
		 break;
		case 1024 :
			 TCCR1B = (1<<CS10) | (0<<CS11) | (1<<CS12);
			 break;
	 default :
		 TCCR1B = (0<<CS00) | (0<<CS01) | (0<<CS02);
	 }
}
