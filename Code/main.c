#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include <stdlib.h>
#include "USART.h"
#include "SPI_led.h"
#include "capt_Hall.h"
#include "timer.h"
#include "patterns.h"
// Serial init source : https://medium.com/@mellow_/atmega328p-serial-communications-in-c-4e5b26a0ea30



// Global variable

volatile  uint16_t led;
volatile uint16_t hall_timer;
char timer[100];
extern int ms;
extern int s;
extern int min;
extern int h;


int main(){
    // sei();
    // _delay_ms(500); // car il démarre 2fois
    USART_init();
    SPI_MasterInit();
    init_hall();
    int prescaler_8bits = 64;
    uint8_t val_mili_8bits = 204; //0b11001100; // 204 en binaire
    int prescaler_16bits = 1024;
    uint16_t val_mili_16bits = 13000;
    // timer3_16bits_init(prescaler_16bits, val_mili_16bits);
    char init[50];
    int i = 1;
    uint16_t hours_step;
    uint16_t minutes_step;
    int minute_hand = 3;
    int hour_hand = 4;
    // sprintf(init, "INIT\n");  // permet de rajouter atomatiquement 0x00 à la fin de la chaine de caractere
    // USART_putstring(init);

    //_delay_ms(100);
    // led = 0b1000000000000000;
    // update_leds(led);
    // _delay_ms(10);
    timer1_16bits_init(prescaler_16bits);
    timer0_8bits_init(prescaler_8bits, val_mili_8bits);
    set_time("10:10");
    while(1){
        hours_step = hall_timer/12;
        minutes_step = hall_timer/60;

        // set_time("10:10");

        if (s == 30) {
          s = s - 60;
        }

        if (min == 30) {
          min = min - 60;
        }

        if (h == 6) {
          h = h - 12;
        }

        if ((TCNT1 >= hours_step * i - hours_step/20) &&(TCNT1 <= hours_step * i + hours_step/20)) {
          led = 0b0110000000000000;
          update_leds(led);
          _delay_ms(0.5);
          i++;
        }

        // Seconds
        if ((TCNT1 >= minutes_step * (30 + s) - minutes_step/4) &&(TCNT1 <= minutes_step * (30 + s) + minutes_step/4)) {
          // led = 0b1000111111111111;
          led += 0b1000000000000000;
          update_leds(led);
          _delay_ms(0.5);
        }

        //Minutes
        if ((TCNT1 >= minutes_step * (30 + min) - minutes_step/4) &&(TCNT1 <= minutes_step * (30 + min) + minutes_step/4)) {
          led = 0b0000000011111111;
          update_leds(led);
          _delay_ms(0.5);
        }

        //Hours
        if ((TCNT1 >= hours_step * (6 + h) - hours_step/20) &&(TCNT1 <= hours_step * (6 + h) + hours_step/20)) {
          led = 0b0000000111111111;
          update_leds(led);
          _delay_ms(0.5);
        }
        if (i >= 12)
          i = 1;
        led = 0b0000000000000000;
        update_leds(led);
    }
}
