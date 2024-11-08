#ifndef ROOM_3_H_INCLUDED
#define ROOM_3_H_INCLUDED

#include <color.h>

#define LIGHT_RED_PIN_R3   3
#define LIGHT_GREEN_PIN_R3 5
#define LIGHT_BLUE_PIN_R3  6

#define POT_1_PIN_R3       2
#define POT_2_PIN_R3       7

#define BTN_PIN_R3         4

enum ControledValue
{
    Red,
    Green,
    Blue,
    Hue,
    Saturation,
    Value
} pot_1_controlled_value_room_3, pot_2_controlled_value_room_3;

void init_room_3();
void update_room_3();

int check_button_room_3(); 

void turn_on_light_room_3();
void turn_off_light_room_3();
void switch_light_room_3();
int get_status_of_light_room_3();

struct ColorRGB get_color_of_light_RGB_room_3();
struct ColorHSV get_color_of_light_HSV_room_3();

void set_color_of_light_RGB_room_3(struct ColorRGB rgb);
void set_color_of_light_HSV_room_3(struct ColorHSV hsv);

int read_pot_1_value_room_3(); // conversion is started automatically
int read_pot_2_value_room_3(); // conversion is started automatically

#endif