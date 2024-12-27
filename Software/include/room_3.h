#ifndef ROOM_3_H_INCLUDED
#define ROOM_3_H_INCLUDED

#include "color.h"

enum PotControlledValue
{
    R,
    G,
    B,
    H,
    S,
    V
} pot_1_controlled_val_room_3;

void init_room_3();
void update_room_3();

int check_button_room_3();
void turn_on_light_room_3();
void turn_off_light_room_3();
void switch_light_room_3();
int get_status_of_light_room_3();

ColorRGB get_color_of_light_RGB_room_3();
ColorHSV get_color_of_light_HSV_room_3();
void set_color_of_light_RGB_room_3(ColorRGB);
void set_color_of_light_HSV_room_3(ColorHSV);

#endif