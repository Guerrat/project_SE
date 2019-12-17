//
// Created by Aurelien on 27/11/2019.
//
#include "SPI_led.h"
#include "capt_Hall.h"
#include "USART.h"
#include <stdio.h>

extern volatile uint16_t led;
extern volatile uint16_t hall_timer;
extern char timer[100];
// volatile uint8_t flag_rise_hall;
void init_hall(void){
    DDRD &= ~_BV(PD0);  // on le met en entrée
    //on active l'interruption sur front montant du capteur
    EICRA |= _BV(ISC01) | _BV(ISC00);
    // on active l'interuption 0
    EIMSK |= _BV(INT0);
}

ISR(INT0_vect){
    hall_timer = (hall_timer + TCNT1)/2 ;
    TCNT1=0;
}
