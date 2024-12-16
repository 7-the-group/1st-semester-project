#include <room_1.h>
#include <avr/io.h>
#include <adcpwm.h>
#include <util/delay.h>

// I replaced pin for potentiometer with pin for button
#define LED_PIN 1 // port b
#define POT_PIN 6 // adc 6
#define BTN_PIN 1 // port c

int previous_pot_value = 0;
char was_btn_pressed_previously = 0;

void init_room_1()
{
    adc_init();
    pwm1_init();

    // set led pin to output and turn off the led
    DDRB |= (1 << LED_PIN);
    PORTB &= ~(1 << LED_PIN);

    // set button pin to input and add pull up resistor
    DDRC &= ~(1 << BTN_PIN);
    PORTC |= (1 << BTN_PIN);
}

void update_room_1()
{
    int current_pot_value = read_pot_room_1();

    if (current_pot_value > previous_pot_value + 3 || current_pot_value < previous_pot_value - 3)
    {
        set_light_intensity_room_1(current_pot_value);
        previous_pot_value = current_pot_value;
    }

    if (check_btn_room_1())
    {
        if (!was_btn_pressed_previously)
        {
            _delay_ms(5);
            was_btn_pressed_previously = 1;
            switch_light_room_1();
        }
    }
    else
    {
        if (was_btn_pressed_previously)
        {
            _delay_ms(5);
            was_btn_pressed_previously = 0;
        }
    }
}

void turn_on_light_room_1()
{
    pwm1_set_duty(0);
}

void turn_off_light_room_1()
{
    pwm1_set_duty(255);
}

void switch_light_room_1()
{
    if (get_light_intensity_room_1() > 127)
    {
        turn_off_light_room_1();
    }
    else
    {
        turn_on_light_room_1();
    }
}

void set_light_intensity_room_1(unsigned char intensity)
{
    pwm1_set_duty(intensity);
}

int get_light_intensity_room_1()
{
    return OCR1A;
}

int read_pot_room_1()
{
    return adc_read(6);
}

int check_btn_room_1()
{
    if ((PINC & (1 << BTN_PIN)) == 0)
    {
        return 1;
    }
    return 0;
}