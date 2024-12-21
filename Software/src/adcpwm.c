// Library with useful functions for ADC and PWM for the atmega328p microcontroller
// Author: AD-SDU, 2024
#include <avr/io.h>
#include <stdint.h>
#include <avr/interrupt.h>
#include "adcpwm.h"
#include <stdlib.h>

volatile uint8_t _duty0 = 255, _duty1 = 255, _duty2 = 255, _timer_tick;

int initialized = 0;

void pwm1_init(void){
    cli();
    DDRB |= (1<<PB1);
    // Set Fast PWM mode, non-inverted output on Timer 1
    TCCR1A = (1 << WGM10) | (1 << COM1A1); // Fast PWM, 8-bit
    TCCR1B = (1 << CS11); // Prescaler: 8 > Frequency approx. 4 kHz
}


void pwm3_init(void){
    DDRD |= (1<<PD3)|(1<<PD5)|(1<<PD6);
    // Disable Timer1
    // TCCR1B = 0; // Makes sure timer 1 is not running
    TCCR1A = (1 << WGM11); // Normal Mode 
    TIMSK1 = (1 << OCIE1A);
    //OCR1A = 1;
    sei();
    TCCR1B = (1 << CS10); // No prescaler:  Frequency approx. 150Hz
}


void pwm1_set_duty(unsigned char input){
    OCR1A = input; // 0 .. 255 range
}

int pwm1_get_duty()
{
    return OCR1A;
}

void pwm3_set_duty(uint8_t red, uint8_t green, uint8_t blue){
    _duty2 = 255-blue; // PD6
    _duty1 = 255-green; // PD5
    _duty0 = 255-red; // PD3
}

ColorRGB pwm3_get_duty()
{
    ColorRGB color;

    color.r = 255 - _duty0;
    color.g = 255 - _duty1;
    color.b = 255 - _duty2;

    return color;
}

void adc_init(void){
    ADMUX = (1<<REFS0); //set prescaler to 128 and turn on the ADC module
    ADCSRA = (1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0)|(1<<ADEN);
}

uint16_t adc_read(uint8_t adc_channel){
    ADMUX &= 0xf0; // clear any previously used channel, but keep internal reference
    ADMUX |= adc_channel; // set the desired channel
    //start a conversion
    ADCSRA |= (1<<ADSC);
    // now wait for the conversion to complete
    while ((ADCSRA & (1<<ADSC)));
    // now we have the result, so we return it to the calling function as a 16 bit unsigned int
    return ADC;
}


ISR(TIMER1_COMPA_vect){
    // sets the pins to HIGH at start
    if (_timer_tick == 0){
        PORTD |= (1<<PD3)|(1<<PD5)|(1<<PD6);
    }
     // sets the pins to LOW at corresponding duty cycle
    if (_timer_tick == _duty0){
        PORTD &=~(1<<PD3);
    }
    if (_timer_tick == _duty1){
        PORTD &=~(1<<PD5);
    }
    if (_timer_tick == _duty2){
        PORTD &=~(1<<PD6);
    }
    
    _timer_tick++;
    if (_timer_tick == 255){
        _timer_tick = 0;
    }

}
