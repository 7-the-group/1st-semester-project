#include <room_2.h>
#include <avr/io.h>
#include <util/delay.h>

int previous_button_state = 1; // at start button wasn't pressed yet

void init_room_2()
{
    DDRC &= ~(1 << BTN_PIN_R2); // set button pin as input
    DDRD |= (1 << LIGHT_PIN_R2); // set light pin as output

    PORTC |= (1 << BTN_PIN_R2); // add pull up resistor for button
    PORTD |= (1 << LIGHT_PIN_R2); // turn off light
}

void update_room_2()
{
    int button_pressed = check_button_room_2(); // read button
    
    if (button_pressed && previous_button_state == 0)
    {
        switch_light_room_2();
    }

    previous_button_state = button_pressed;
}

int check_button_room_2()
{
    if ((PINC & (1 << BTN_PIN_R2)) == 0)
    {
        _delay_ms(50);
        return 1;
    }
    return 0;
}

void turn_on_light_room_2()
{
    PORTD &= ~(1 << LIGHT_PIN_R2); // set light's pin to 0
}

void turn_off_light_room_2()
{
    PORTD |= (1 << LIGHT_PIN_R2); // set light's pin to 1
}

void switch_light_room_2()
{
    PORTD ^= (1 << LIGHT_PIN_R2); // set light's pin to 1
}

int get_status_of_light_room_2()
{
    if ((PORTD & (1 << LIGHT_PIN_R2)) == 0)
    {
        return 1;
    }
    return 0;
}