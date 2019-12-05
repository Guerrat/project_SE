//
// Created by Aurelien on 27/11/2019.
//

#include "capt_Hall.h"
volatile uint8_t flag_rise_hall;
void init_hall(void){
    DDRD &= ~_BV(PD0);  // on le met en entrée
    //on active l'interruption sur front montant du capteur
    EICRA |= _BV(ISC01) | _BV(ISC00);
    // on active l'interuption 0
    EIMSK |= _BV(INT0);
}

ISR(INT0_vect){
    flag_rise_hall = 1;
}