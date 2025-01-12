#include <door.h>
#include <adcpwm.h>
#include <avr/io.h>
#include <util/delay.h>

int ldr_threshold = 500;
char light_switched_manually_door = 0;

int light_length = 1000;
uint32_t light_timer = 0;

void init_door()
{
    adc_init();

    DDRC &= ~(1 << DDC3); // set LDR pin as input
    DDRB &= ~(1 << DDB5); // set PIR sensor pin as input
    DDRB |= (1 << DDB2); // set LED pin to output

    //PORTB |= (1 << PORTB5); // set pull up resistor
    PORTB |= (1 << PORTB2); // turn off the light
}

void update_door()
{
    light_timer++;
    int current_ldr = get_ldr_value_door();
    int movement = movement_detected_door();

    if (current_ldr > ldr_threshold)
    {
        if (movement)
        {
            turn_on_light_door();
        }
    }

    if (light_length < light_timer)
    {
        turn_off_light_door();
    }
}

void set_ldr_threshold_door(int threshold)
{
    ldr_threshold = threshold;
}

void turn_off_light_door()
{
    PORTB |= (1 << PORTB2);
}

void turn_on_light_door()
{
    light_timer = 0;
    PORTB &= ~(1 << PORTB2);
}

void switch_light_door()
{
    PORTB ^= (1 << PORTB2);
}

int get_ldr_value_door()
{
    return adc_read(3);
}

int movement_detected_door()
{
    if ((PINB & (1 << PINB5)) != 0)
    {
        _delay_ms(50);
        return 1;
    }
    return 0;
}

int get_door_light_status()
{
    if ((PORTB & (1 << PORTB2)) == 0)
    {
        return 1;
    }
    return 0;
}

void turn_off_light_manually_door()
{
    turn_off_light_door();
}

void turn_on_light_manually_door()
{
    turn_on_light_door();
}

int get_ldr_threshold_door() {
    return ldr_threshold;
}