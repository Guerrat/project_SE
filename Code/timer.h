//
// Created by Aurelien on 04/12/2019.
//
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#ifndef PROJET_SE_TIMER_H
#define PROJET_SE_TIMER_H

void timer0_8bits_init(int prescaler_8bits, uint8_t val_mili_8bits);
void timer1_16bits_init(int prescaler_16bits);
void timer3_16bits_init(int prescaler_16bits, uint16_t val_mili_16bits);
void set_time(char time[]);

#endif //PROJET_SE_TIMER_H
