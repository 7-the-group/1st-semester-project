#include <room_3.h>
#include <avr/io.h>

void init_room_3()
{
    // set all adc pins to input
    // initialize adc from adcpwm.h library
    // initialize pwm from adcpwm.h library
}

void update_room_3()
{
    // check if button is pressed, and turn on or off light
    // read pots values and update color
}

int check_button_room_3()
{
  // return 1 if button is pressed otherwise 0
}

void turn_on_light_room_3()
{
    
}

void turn_off_light_room_3()
{

}

void switch_light_room_3()
{
    // switch state of a light
}

int get_status_of_light_room_3()
{
    // return 1 if light is on otherwise 0
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
}

int read_pot_2_value_room_3()
{
    // return value of potentiometer 2
}