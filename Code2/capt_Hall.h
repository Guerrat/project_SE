//
// Created by Aurelien on 27/11/2019.
//
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#ifndef PROJET_SE_CAPT_HALL_H
#define PROJET_SE_CAPT_HALL_H

extern volatile uint8_t flag_rise_hall;
void init_hall(void);

#endif //PROJET_SE_CAPT_HALL_H
