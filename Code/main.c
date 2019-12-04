#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include "USART.h"
#include "SPI_led.h"
#include "capt_Hall.h"
#include "timer.h"
// Serial init source : https://medium.com/@mellow_/atmega328p-serial-communications-in-c-4e5b26a0ea30

// Global variable


int main(){
    _delay_ms(100); // car il démarre 2fois
    USART_init();
    SPI_MasterInit();
    init_hall();
    /*
    char init[50] ;
    sprintf(init, "1234");  // permet de rajouter atomatiquement 0x00 à la fin de la chaine de caractere

    USART_putstring(init);
*/


    //USART_send('a');
    uint16_t led = 0b1001010010010000;
    update_leds(led);
    while(1){
        if(flag_rise_hall){
            flag_rise_hall = 0;
            uint16_t led = 0b1111111111111111;
            update_leds(led);
            _delay_ms(50);
        }
        uint16_t led = 0b1001010010010000;
        update_leds(led);


/*
        // echo
        if(flag_UART_RX == 1){
            flag_UART_RX = 0;
            //USART_send('b');
        }
*/

    }
}


