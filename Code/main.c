#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#define FOSC 13000000
#define BAUD 38400
#define MYUBBR (FOSC/(16*BAUD))-1

// Serial init source : https://medium.com/@mellow_/atmega328p-serial-communications-in-c-4e5b26a0ea30
void USART_init(unsigned int ubbr);
void USART_putstring(char *str);
unsigned char USART_received(void);
void USART_send(unsigned char data);

// Global variable


int main(){
    DDRB |= _BV(PB5);
    USART_init(MYUBBR);
    while(1){
        unsigned char received;
        if(received = USART_received()){
            USART_send(received+1);
        }
    }
}

// Initialisation du module UART
void USART_init(unsigned int ubbr){

    // Set baud rate
    UBRR0H = (ubbr >> 8);
    UBRR0L = ubbr;

    // Configuration de l'UART
    UCSR0A &= ~_BV(U2X0);
    UCSR0B |= _BV(RXCIE0);
    //Enable reciever and transmitter
    UCSR0B |= _BV(RXEN0) | _BV(TXEN0);
    //Set frame format : 8bit 2stop bit
    UCSR0C |= _BV(UCSZ01) | _BV(UCSZ00) | _BV(USBS0);


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
 * Envoie d'un octet
 * @param data
 */
void USART_send(unsigned char data){
    while(!(UCSR0A & _BV(UDRE0)));
    UDR0 = data;
}

/**
 * Fonction d'intéruption qui sera appelée à chaque réception de donnée
 */
 /*
ISR(USART_RX_vect){
    unsigned char received = USART_received();

    if(received == '1'){
        //ledState = 1;
        USART_putstring("LED ON\n\r");
    }
    else if(received == '0'){
        //ledState = 0;
        USART_putstring("LED OFF\n\r");
    }

}*/