//
// Created by Aurelien on 27/11/2019.
//
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#ifndef PROJET_SE_SPI_LED_H
#define PROJET_SE_SPI_LED_H
void SPI_MasterInit(void);
uint8_t SPI_MasterTransmit(uint8_t to_send);
void update_leds(uint16_t led_value);
#endif //PROJET_SE_SPI_LED_H
