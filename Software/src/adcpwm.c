// Library with useful functions for ADC and PWM for the atmega328p microcontroller
// Author: AD-SDU, 2024
#include <avr/io.h>
#include <stdint.h>
#include <avr/interrupt.h>
#include "adcpwm.h"

volatile uint8_t _duty0 = 0, _duty1 = 0, _duty2 = 0, _timer_tick;

void pwm1_init(void){
    cli();
    DDRB |= (1<<PB1);
    // Set Fast PWM mode, non-inverted output on Timer 1
    TCCR1A = (1 << WGM10) | (1 << COM1A1); // Fast PWM, 8-bit
    TCCR1B = (1 << CS11); // Prescaler: 8 > Frequency approx. 4 kHz
}


void pwm3_init(void){
    /* Alin's program
    DDRD |= (1<<PD3)|(1<<PD5)|(1<<PD6);
    // Disable Timer1
    // TCCR1B = 0; // Makes sure timer 1 is not running
    TCCR1A = (1 << WGM11); // Normal Mode
    TIMSK1 = (1 << OCIE1A);
    OCR1A = 1;
    sei();
    TCCR1B = (1 << CS10); // No prescaler:  Frequency approx. 150Hz
    */

    // Step 1: Set PD3, PD5, and PD6 as output pins
    DDRD |= (1 << PD3) | (1 << PD5) | (1 << PD6);

    // Step 2: Configure Timer0 for Fast PWM on PD5 (OC0B) and PD6 (OC0A)
    // Set Fast PWM mode (WGM02:0 = 011 for 8-bit Fast PWM)
    // Non-inverting mode (COM0A1 = 1, COM0B1 = 1)
    TCCR0A = (1 << WGM00) | (1 << WGM01) | (1 << WGM02) | (1 << COM0A1) | (1 << COM0B1);
    TCCR0B = (1 << CS02);  // Prescaler of 8 for Timer0

    // Step 3: Configure Timer2 for Fast PWM on PD3 (OC2B)
    // Set Fast PWM mode (WGM22:0 = 011 for 8-bit Fast PWM)
    // Non-inverting mode (COM2B1 = 1)
    TCCR2A = (1 << WGM20) | (1 << WGM21) | (1 << WGM22) | (1 << COM2B1);
    TCCR2B = (1 << CS22);  // Prescaler of 8 for Timer2

    // Step 4: Set initial duty cycles
    OCR0A = 0;  // 0% duty cycle on PD6 (OC0A)
    OCR0B = 0;  // 0% duty cycle on PD5 (OC0B)
    OCR2B = 0;  // 0% duty cycle on PD3 (OC2B)
}


void pwm1_set_duty(unsigned char input){
    if (input <= 100){
        OCR1A = input*2.55; // 0 .. 255 range
    }
       
}

void pwm3_set_duty(uint8_t red, uint8_t green, uint8_t blue){
    OCR0A = 255 - blue; // PD6
    OCR0B = 255 - green; // PD5
    OCR2B = 255 - red; // PD3
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
        PORTB |= (1<<PB0)|(1<<PB1)|(1<<PB2);
    }
     // sets the pins to LOW at corresponding duty cycle
    if (_timer_tick == _duty0){
        PORTB &=~(1<<PB0);
    }
    if (_timer_tick == _duty1){
        PORTB &=~(1<<PB1);
    }
    if (_timer_tick == _duty2){
        PORTB &=~(1<<PB2);
    }
    
    _timer_tick++;
    if (_timer_tick == 100){
        _timer_tick = 0;
    }

}
