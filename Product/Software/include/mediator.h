#ifndef MEDIATOR_H_INCLUDED
#define MEDIATOR_H_INCLUDED

typedef float (*get_value_func)(void);
typedef void (*change_value_by_func)(int); // change value by n points

// get pointers to functions using element id
get_value_func get_getter_func(int id);
change_value_by_func get_changer_func(int id);

#endif