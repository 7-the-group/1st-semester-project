#ifndef ROOM_3_H_INCLUDED

#define ROOM_3_H_INCLUDED

#include "color.h"

#define POTENTIOMETER1ROOM3 2
#define POTENTIOMETER2ROOM3 7
#define REDLED 3
#define GREENLED 5
#define BLUELED 6
#define BUTTONROOM3 4

void init_room3();
void update_room3();

int check_button_room_3();
void turn_on_light_room_3();
void turn_off_light_room_3();
void switch_light_room_3();
int get_status_of_light_room_3();

struct ColorRGB get_color_of_light_RGB_room_3();
struct ColorHSV get_color_of_light_HSV_room_3();
void set_color_of_light_RGB_room_3(ColorRGB);
void set_color_of_light_HSV_room_3(ColorHSV);

int read_pot_1_value_room_3();
int read_pot_2_value_room_3();

#endif