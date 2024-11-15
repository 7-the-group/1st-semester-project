#include <room_3.h>
#include <avr/io.h>
#include "adcpwm.h"

unsigned char buttonStateRoom3 = 0;
int rgbMenuActive = 0;

void init_room_3()
{
    // set all adc pins to input
    DDRC &= ~(1 << POTENTIOMETER1ROOM3); // set potentiometer 1 to input
    DDRD &= ~(1 << POTENTIOMETER2ROOM3); // set potentiometer 2 to input
    DDRD &= ~(1 << BUTTONROOM3); // set button to input

    DDRD |= (1 << REDLED) | (1 << GREENLED) | (1 << BLUELED); // set leds to output

    PORTD &= ~((1 << REDLED) | (1 << GREENLED) | (1 << BLUELED)); // leds turned off initially
    PORTD &= ~(1 << BUTTONROOM3); // set button to 0

    // initialize adc from adcpwm.h library
    adc_init();
    // initialize pwm from adcpwm.h library
    pwm3_init();
}

void update_room_3()
{
    // check if button is pressed, and turn on or off light
    // read pots values and update color
}

int check_button_room_3()
{
  // return 1 if button is pressed otherwise 0
  return (PIND & (1 << BUTTONROOM3));
}

void turn_on_light_room_3()
{
    PORTD |= (1 << REDLED) | (1 << GREENLED) | (1 << BLUELED);
}

void turn_off_light_room_3()
{
    PORTD |= ~((1 << REDLED) | (1 << GREENLED) | (1 << BLUELED));
}

void switch_light_room_3()
{
    // switch state of a light
    if (get_status_of_light_room_3()) turn_off_light_room_3();
    else turn_on_light_room_3();
}

int get_status_of_light_room_3()
{
    // return 1 if light is on otherwise 0
    return PORTD & ((1 << REDLED) | (1 << GREENLED) | (1 << BLUELED));
}

struct ColorRGB get_color_of_light_RGB_room_3()
{
    // adcpwm.h library
    // return current color of the light
}

struct ColorHSV get_color_of_light_HSV_room_3()
{
    return convert_RGB_to_HSV(get_color_of_light_RGB_room_3());
}

void set_color_of_light_RGB_room_3(struct ColorRGB rgb)
{
    // adcpwm.h library
    // set color of the light
}

void set_color_of_light_HSV_room_3(struct ColorHSV hsv)
{
    set_color_of_light_RGB_room_3(convert_HSV_to_RGB(hsv));
}

int read_pot_1_value_room_3()
{
    // return value of potentiometer 1
    return PINC2;
}

int read_pot_2_value_room_3()
{
    // return value of potentiometer 2
}