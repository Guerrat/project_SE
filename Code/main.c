#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include "USART.h"
#include "SPI_led.h"

// Serial init source : https://medium.com/@mellow_/atmega328p-serial-communications-in-c-4e5b26a0ea30

// Global variable


int main(){
    _delay_ms(500); // car il démarre 2fois
    USART_init();
    SPI_MasterInit();
    /*
    char init[50] ;
    sprintf(init, "1234");  // permet de rajouter atomatiquement 0x00 à la fin de la chaine de caractere

    USART_putstring(init);
*/


    //USART_send('a');
    uint16_t led = 0b1001010010010000;
    update_leds(led);
    while(1){

/*
        // echo
        if(flag_UART_RX == 1){
            flag_UART_RX = 0;
            //USART_send('b');
        }
*/

    }
}


