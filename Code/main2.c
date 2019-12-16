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
volatile uint16_t hall_timer;
char timer[100];

int main(){
    _delay_ms(500); // car il démarre 2fois
    USART_init();
    SPI_MasterInit();
    init_hall();
    int prescaler_8bits = 64;
    int val_mili_8bits = 204;
    int prescaler_16bits = 1024;
    timer1_16bits_init(prescaler_16bits);

    char init[50];
    int i = 1;
    uint16_t timer_step;
    sprintf(init, "INIT\n");  // permet de rajouter atomatiquement 0x00 à la fin de la chaine de caractere
    USART_putstring(init);

    //_delay_ms(100);
    led = 0b1000000000000000;
    update_leds(led);
    // _delay_ms(10);
    while(1){
        // if(flag_rise_hall){
        //     led = 0b1011000000000000;
        //     // led = 0b1011000000000000;
        //     // led = 0b1111111111111111;
        //     update_leds(led);
        //     // _delay_ms(10);
        //     flag_rise_hall = 0;
        //     // _delay_ms(1);
        //     // USART_send('A');
        //     // // _delay_ms(50);
        //     // sprintf(timer, "Time = %d, i = %d\n", TCNT1 == TCNT1, i);  // permet de rajouter atomatiquement 0x00 à la fin de la chaine de caractere
        //     // USART_putstring(timer);
        //     hall_timer = TCNT1;
        //     TCNT1=0;
        // }
        // _delay_ms(1);
        // timer_step = hall_timer/12;
        // if ((TCNT1 >= timer_step * i - timer_step/9) &&(TCNT1 <= timer_step * i + timer_step/9)) {
        //
        //   led = 0b1011000000000000;
        //   update_leds(led);
        //   // sprintf(timer, "Time = %u, i = %d\n", TCNT1, i);  // permet de rajouter atomatiquement 0x00 à la fin de la chaine de caractere
        //   // USART_putstring(timer);
        //   i++;
        // }
        // if (i >= 12)
        //   i = 1;
        led = 0b1000000000000000;
        update_leds(led);
        _delay_ms(3);
        // sprintf(timer, "Time %u\n", hall_timer);
        // USART_putstring(timer);
        // // _delay_ms(50);
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
