#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include <stdlib.h>
#include "USART.h"
#include "SPI_led.h"
#include "capt_Hall.h"
#include "timer.h"
// Serial init source : https://medium.com/@mellow_/atmega328p-serial-communications-in-c-4e5b26a0ea30



// Global variable

volatile  uint16_t led;

int main(){
    _delay_ms(500); // car il démarre 2fois
    USART_init();
    SPI_MasterInit();
    init_hall();
    int prescaler_8bits = 64;
    int val_mili_8bits = 204;
    int prescaler_16bits = 1;
    timer1_16bits_init(prescaler_16bits);

    char init[50];
    char timer[100];
    uint16_t hall_timer;

    sprintf(init, "INIT");  // permet de rajouter atomatiquement 0x00 à la fin de la chaine de caractere
    USART_putstring(init);

    //_delay_ms(100);
    led = 0b1000000000000000;
    update_leds(led);
    // _delay_ms(10);
    while(1){
        if(flag_rise_hall){
            flag_rise_hall = 0;
            led = 0b0000000000001111;
            update_leds(led);
            USART_send('A');
            // _delay_ms(50);
            hall_timer = TCNT1;
            TCNT1=0;
            sprintf(timer, "Time %u\n", hall_timer);
            USART_putstring(timer);
            // _delay_ms(50);
        }
        // _delay_ms(50);
        led = 0b1000000000000000;
        update_leds(led);
        //_delay_ms(1);

/*
        // echo
        if(flag_UART_RX == 1){
            flag_UART_RX = 0;
            //USART_send('b');
        }
*/
    }
}
