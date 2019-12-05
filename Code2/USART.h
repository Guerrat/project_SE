//
// Created by Aurelien on 27/11/2019.
//
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>



#ifndef PROJET_SE_USART_H
#define PROJET_SE_USART_H

void USART_init(void);
void USART_send(unsigned char data);
void USART_putstring(char *str);
unsigned char USART_received(void);

#endif //PROJET_SE_USART_H
