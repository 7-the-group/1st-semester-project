#ifndef ROOM_3_H_INCLUDED

#define ROOM_3_H_INCLUDED

#include "color.h"

#define POTENTIOMETER1_ROOM3 2
#define POTENTIOMETER2_ROOM3 7
#define RED_LED 3
#define GREEN_LED 5
#define BLUE_LED 6
#define BUTTON_ROOM3 4

enum PotControlledValue
{
    R,
    G,
    B,
    H,
    S,
    V
} pot_1_controlled_val, pot_2_controlled_val;

void init_room3();
void update_room3();

int check_button_room_3();
void turn_on_light_room_3();
void turn_off_light_room_3();
void switch_light_room_3();
int get_status_of_light_room_3();

ColorRGB get_color_of_light_RGB_room_3();
ColorHSV get_color_of_light_HSV_room_3();
void set_color_of_light_RGB_room_3(ColorRGB);
void set_color_of_light_HSV_room_3(ColorHSV);

int read_pot_1_value_room_3();
int read_pot_2_value_room_3();

#endif