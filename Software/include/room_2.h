#ifndef ROOM_2_H_INCLUDED
#define ROOM_2_H_INCLUDED

#define LIGHT_PIN_R2 0
#define BTN_PIN_R2   4

void init_room_2(); // initializes input and output pins and turns the light off
void update_room_2(); // check if any button was pressed and change the state of light accordingly

int check_button_room_2(); // returns 0 when button 1 is pressed

void turn_on_light_room_2();
void turn_off_light_room_2();
void switch_light_room_2(); // if light is on turn off light and vice versa
int get_status_of_light(); // returns 1 when light is lit and 0 when not

#endif