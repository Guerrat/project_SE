//
// Created by Aurelien on 04/12/2019.
//

#include "timer.h"
#include <avr/io.h>
#include <stdio.h>
#include <stdlib.h>
#include "USART.h"
#include "SPI_led.h"

extern char timer[100];
volatile int ms = 0;
volatile int s = 0;
volatile int min = 0;
volatile int h = 0;

void timer0_8bits_init(int prescaler_8bits, uint8_t val_mili_8bits) {
  // uint8_t timerOverflowCount=0;
  //DDRD=0xff;         //configure PORTD as output
  TCNT0=0x00;
  TCCR0 = (1 << WGM01) ;
  TIMSK |= (1 << OCIE0);// | (1 << TOIE0);
  OCR0 = val_mili_8bits;
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
   // sei();
}

void timer3_16bits_init(int prescaler_16bits, uint16_t val_mili_16bits) {
  // DDRD=0xff;         //configure PORTD as output
	TCNT3=0;
  //TCCR3 = (1 << WGM01);
  //TIMSK |= (1 << OCIE0) | (1 << TOIE0);
  OCR3A = val_mili_16bits;
	switch(prescaler_16bits){
		case 1 :
			 TCCR3B = (1<<CS30) | (0<<CS31) | (0<<CS32);
			 break;
		case 8 :
			 TCCR3B = (0<<CS30) | (1<<CS31) | (0<<CS32);
			 break;
	 case 64 :
			TCCR3B = (1<<CS30) | (1<<CS31) | (0<<CS32);
			break;
	case 256 :
		 TCCR3B = (0<<CS30) | (0<<CS31) | (1<<CS32);
		 break;
		case 1024 :
			 TCCR3B = (1<<CS30) | (0<<CS31) | (1<<CS32);
			 break;
	 default :
		 TCCR3B = (0<<CS30) | (0<<CS31) | (0<<CS32);
	 }
}

void timer1_16bits_init(int prescaler_16bits){
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

/* argument hh:mm*/
void set_time(char time[]) {
  h = (time[0]-'0') * 10 + (time[1] - '0');
  min = (time[3] - '0') * 10 + (time[4] - '0');
  s = 0;
  sprintf(timer, "h = %d, min = %d\n", h, min);  // permet de rajouter atomatiquement 0x00 à la fin de la chaine de caractere
  USART_putstring(timer);
}

ISR(TIMER0_COMP_vect){
  ms+=1;
  if (ms == 1000) {
    // sprintf(timer, "ms = %d\n", ms);  // permet de rajouter atomatiquement 0x00 à la fin de la chaine de caractere
    // USART_putstring(timer);
    ms = 0;
    s++;
  }
  if (s == 60) {
    s = 0;
    min++;
  }
  if (min == 60) {
    min = 0;
    h++;
  }
  if (h == 12) {
    h = 0;
  }
}

// ISR(TIMER3_COMPA_vect) {
//   update_leds(0b000111111111000);
//   _delay_ms(10);
//   update_leds(0b000000000000000);
// }
