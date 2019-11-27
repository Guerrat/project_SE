//
// Created by Aurelien on 27/11/2019.
//

#include "SPI_led.h"
void SPI_MasterInit(void)
{
/* Set MOSI and SCK output, all others input */
    DDRB |= _BV(PB2)|_BV(PB1);
    DDRB &= ~_BV(PB3);

    DDRE |= _BV(PE4); // /OE\ set 0 (OE set 1)
    PORTE &= ~_BV(PE4);

    DDRE |= _BV(PE5); // LE set 0
    PORTE &= ~_BV(PE5);
/* Enable SPI, Master, set clock rate fck/2 , le reste a 0*/
    SPCR |= _BV(SPE)|_BV(MSTR);
    SPSR |= _BV(SPI2X);
    update_leds(0x0000);
}
uint8_t SPI_MasterTransmit(uint8_t to_send)
{
/* Start transmission */
    SPDR = to_send;
    //USART_send(to_send);
/* Wait for transmission complete */
    while(!(SPSR & _BV(SPIF)))
        ;
/* Return the value */
    return SPDR;
}

void update_leds(uint16_t leds_value){
    SPI_MasterTransmit((uint8_t)(leds_value>>8));
    SPI_MasterTransmit((uint8_t)(leds_value));

    PORTE |= _BV(PORTE5);
    PORTE &= ~_BV(PORTE5);
}