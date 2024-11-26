#ifndef DOOR_H_INCLUDED
#define DOOR_H_INCLUDED

void init_door();
void update_door();

void set_ldr_threshold(int threshold);

void turn_off_door_light_manually();
void turn_on_door_light_manually();
void reset_automatic_behaviour_door();
void switch_door_light();

int get_ldr_value();
int get_ldr_threshold();
int movement_detected();

int get_door_light_status();

#endif