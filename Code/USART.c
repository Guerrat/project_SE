//
// Created by Aurelien on 27/11/2019.
//

#include "USART.h"
#define FOSC 13000000
#define BAUD 38400
#define MYUBBR (FOSC/(16*BAUD))-1

volatile uint8_t value_UART_RX;
volatile int flag_UART_RX;

// Initialisation du module UART
void USART_init(void){
    flag_UART_RX = 0;
    value_UART_RX = 0;
    // Set baud rate
    UBRR0H = (MYUBBR >> 8);
    UBRR0L = MYUBBR;

    // Configuration de l'UART
    UCSR0A &= ~_BV(U2X0);
    UCSR0B |= _BV(RXCIE0);
    //Enable reciever and transmitter
    UCSR0B |= _BV(RXEN0) | _BV(TXEN0);
    //Set frame format : 8bit 1stop bit
    UCSR0C |= _BV(UCSZ01) | _BV(UCSZ00);

    sei();
}

/**
 * Envoie d'un octet
 * @param data
 */
void USART_send(unsigned char data){
    while(!(UCSR0A & _BV(UDRE0)));
    UDR0 = data;
}

/**
 * Envoie d'une chaine de caractère
 * @param str
 */
void USART_putstring(char *str){
    while(*str != 0x00){
        USART_send(*str);
        str++;
        //oui
    }
}


/**
 * Appelé lorsque l'interuption est levé pour récuperer l'octet
 * @return
 */
unsigned char USART_received(void){
    while(!(UCSR0A & _BV(UDRE0)));
    return UDR0;
}

/**
 * Fonction d'intéruption qui sera appelée à chaque réception de donnée
 */

ISR(USART0_RX_vect){
        value_UART_RX = USART_received();
        flag_UART_RX = 1;
}
