#ifndef MENU_HELPER_H_INCLUDED
#define MENU_HELPER_H_INCLUDED

// every function returns -1 if element is not on a particular level (for example element on second level, will have position of -1 on third level)
int get_1st_level_pos(int id);
int get_2nd_level_pos(int id);
int get_3rd_level_pos(int id);
int get_4th_level_pos(int id);
int get_5th_level_pos(int id);

int get_last_level_pos(int id);

#endif