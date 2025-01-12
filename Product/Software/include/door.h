#ifndef DOOR_H_INCLUDED
#define DOOR_H_INCLUDED

void init_door();
void update_door();

void set_ldr_threshold_door(int threshold);

void turn_off_light_manually_door();
void turn_on_light_manually_door();
void reset_automatic_behaviour_door();
void switch_light_door();

int get_ldr_value_door();
int get_ldr_threshold_door();
int movement_detected_door();

int get_door_light_status();

#endif