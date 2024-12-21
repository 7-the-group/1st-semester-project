#include <room_3.h>
#include <avr/io.h>
#include "adcpwm.h"
#include <stdlib.h>
#include <util/delay.h>

unsigned char previousButtonStateRoom3 = 1;
ColorRGB RGBcolor;
int prev_potentiometer_1;
// int prev_potentiometer_2;

void init_room_3()
{
    // initialize adc from adcpwm.h library
    adc_init();
    // initialize pwm from adcpwm.h library
    pwm3_init();

    pot_1_controlled_val_room_3 = H;
    // pot_2_controlled_val_room_3 = V;
    // set all adc pins to input
    // DDRC &= ~(1 << POTENTIOMETER1_ROOM3); // set potentiometer 1 to input
    DDRD &= ~(1 << POTENTIOMETER2_ROOM3); // set potentiometer 2 to input

    DDRD &= ~(1 << BUTTON_ROOM3); // set button to input
    //DDRD |= (1 << RED_LED | 1 << GREEN_LED | 1 << BLUE_LED); // set lights as output

    PORTD |= (1 << BUTTON_ROOM3); // add pull up
    //PORTD &= ~(1 << RED_LED | 1 << GREEN_LED | 1 << BLUE_LED); // turn off led

    pwm3_set_duty((uint8_t)0,(uint8_t)0,(uint8_t)0);
}

void update_room_3()
{
    // measure pots
    int potentiometer_1 = read_pot_1_value_room_3();
    // int potentiometer_2 = read_pot_2_value_room_3();

    if (abs(potentiometer_1 - prev_potentiometer_1)  >= 3)
    {
        prev_potentiometer_1 = potentiometer_1;
        ColorRGB current_color = pwm3_get_duty();
        ColorHSV current_color_HSV = convert_RGB_to_HSV(current_color);
        switch (pot_1_controlled_val_room_3)
        {
            case R:
                pwm3_set_duty(prev_potentiometer_1/1023.0f*255,current_color.g,current_color.b);
                break;
            case G:
                pwm3_set_duty(current_color.r, prev_potentiometer_1/1023.0f*255, current_color.b);
                break;
            case B:
                pwm3_set_duty(current_color.r, current_color.b, prev_potentiometer_1/1023.0f*255);
                break;
            case H:
                current_color_HSV.h = prev_potentiometer_1/1023.0f*360;
                set_color_of_light_HSV_room_3(current_color_HSV);
                break;
            case S:
                current_color_HSV.s = prev_potentiometer_1/1023.0f;
                set_color_of_light_HSV_room_3(current_color_HSV);
                break;
            case V:
                current_color_HSV.v = prev_potentiometer_1/1023.0f;
                set_color_of_light_HSV_room_3(current_color_HSV);
                break;
        }
    }

    /* if (abs(potentiometer_2 - prev_potentiometer_2)  >= 3)
    {
        prev_potentiometer_2 = potentiometer_2;
        ColorRGB current_color;
        pwm3_get_duty(&current_color);
        ColorHSV current_color_HSV = convert_RGB_to_HSV(current_color);
        switch (pot_2_controlled_val_room_3)
        {
            case R:
                pwm3_set_duty(prev_potentiometer_1/1023*255,current_color.g,current_color.b);
                break;
            case G:
                pwm3_set_duty(current_color.r, prev_potentiometer_1/1023*255, current_color.b);
                break;
            case B:
                pwm3_set_duty(current_color.r, current_color.b, prev_potentiometer_1/1023*255);
                break;
            case H:
                current_color_HSV.h = prev_potentiometer_1/1023*360;
                set_color_of_light_HSV_room_3(current_color_HSV);
                break;
            case S:
                current_color_HSV.s = prev_potentiometer_1/1023.0;
                set_color_of_light_HSV_room_3(current_color_HSV);
                break;
            case V:
                current_color_HSV.v = prev_potentiometer_1/1023.0;
                set_color_of_light_HSV_room_3(current_color_HSV);
                break;
        }
    } */

    // check if button is pressed, and turn on or off light
    int button_pressed = check_button_room_3();
    if (button_pressed && previousButtonStateRoom3 == 0) switch_light_room_3();

    previousButtonStateRoom3 = button_pressed;
    _delay_ms(10);
    // read pots values and update color
    // set_color_of_light_RGB_room_3();
}

int check_button_room_3()
{
  // return 1 if button is pressed otherwise 0
  if ((PIND & (1 << BUTTON_ROOM3)) == 0)
  {
    _delay_ms(50);
    return 1;
  }
  return 0;
}

void turn_on_light_room_3()
{
    pwm3_set_duty((uint8_t)0, (uint8_t)0, (uint8_t)0);
    //PORTD |= (1 << RED_LED) | (1 << GREEN_LED) | (1 << BLUE_LED);
}

void turn_off_light_room_3()
{
    pwm3_set_duty((uint8_t)255, (uint8_t)255, (uint8_t)255);
    //PORTD &= ~((1 << RED_LED) | (1 << GREEN_LED) | (1 << BLUE_LED));
}

void switch_light_room_3()
{
    // switch state of a light
    //if (get_status_of_light_room_3()) turn_off_light_room_3();
    //else turn_on_light_room_3();

    ColorRGB color = get_color_of_light_RGB_room_3();

    if (color.r != 0 || color.g != 0 || color.b != 0)
    {
        pwm3_set_duty((uint8_t)0, (uint8_t)0, (uint8_t)0);
    }
    else pwm3_set_duty((uint8_t)255, (uint8_t)255, (uint8_t)255);
}

int get_status_of_light_room_3()
{
    // return 1 if light is on otherwise 0
    //return (PORTD & ((1 << RED_LED) | (1 << GREEN_LED) | (1 << BLUE_LED))) != 0;

    ColorRGB color = get_color_of_light_RGB_room_3();

    if (color.r != 0 || color.g != 0 || color.b != 0)
    {
        return 1;
    }

    return 0;
}

ColorRGB get_color_of_light_RGB_room_3()
{
    // adcpwm.h library
    // return current color of the light
    return pwm3_get_duty();
}

ColorHSV get_color_of_light_HSV_room_3()
{
    return convert_RGB_to_HSV(get_color_of_light_RGB_room_3());
}

void set_color_of_light_RGB_room_3(ColorRGB rgb)
{
    // adcpwm.h library
    // set color of the light
    pwm3_set_duty(rgb.r, rgb.g, rgb.b);
}

void set_color_of_light_HSV_room_3(ColorHSV hsv)
{
    set_color_of_light_RGB_room_3(convert_HSV_to_RGB(hsv));
}

int read_pot_1_value_room_3()
{
    // return value of potentiometer 1
    return adc_read(7);
}

/* int read_pot_2_value_room_3()
{
    // return value of potentiometer 2
    return adc_read(2);
} */