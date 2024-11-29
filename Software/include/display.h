#ifndef DISPLAY_H_INCLUDED
#define DISPLAY_H_INCLUDED
#include "menu.h"
void init_display();
void update_display(Menu_element* elems, int elements_count, int element_hovered, int element_selected); 
//if no elment is hovered element_hovered=-1
//if no element is selected element_selected=-1
//one of variables(hovered,selected) will always be -1
#endif