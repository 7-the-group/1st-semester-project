#include <room_2.h>
#include <avr/io.h>
#include <util/delay.h>

int previous_button_state = 1; // at start button wasn't pressed yet

void init_room_2()
{
    DDRD &= ~(1 << BTN_PIN_R2); // set button pin as input
    DDRD |= (1 << LIGHT_PIN_R2); // set light pin as output

    PORTD |= (1 << BTN_PIN_R2); // add pull up resistor for button
    PORTD |= (1 << LIGHT_PIN_R2); // turn off light
}

void update_room_2()
{
    int button_pressed = check_button_room_2(); // read button
    
    // if button is pressed and it wasn't previously pressed, switch light
    // checking if button wasn't previously pressed get rid of switching light when when button is being held for longer.
    if (button_pressed && previous_button_state == 0)
    {
        switch_light_room_2();
    }

    previous_button_state = button_pressed; // set previous state of a button to current state
    _delay_ms(10); // wait for fluctuations when button is pressed to disappear
}

int check_button_room_2()
{
    return (PIND & (1 << BTN_PIN_R2)) == 0; // get value of button bit in PINC register
}

void turn_on_light_room_2()
{
    PORTD |= (1 << LIGHT_PIN_R2); // set light's pin to 1
}

void turn_off_light_room_2()
{
    PORTD &= ~(1 << LIGHT_PIN_R2); // set light's pin to 0
}

void switch_light_room_2()
{
    PORTD ^= (1 << LIGHT_PIN_R2); // set light's pin to 1
}

int get_status_of_light_room_2()
{
    return (PORTD & (1 << LIGHT_PIN_R2)) != 0; // read bit which indicates if light is on
}