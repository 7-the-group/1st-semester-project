#ifndef MENU
#define MENU

#include <stdint.h>
#include <stdbool.h>

typedef enum {
    INT,
    BOOL,
    FLOAT
} type_of_file;

typedef enum {
    MENU_FILE,
    MENU_FOLDER
} menu_element_type;

typedef struct {
    uint8_t ID;
    char* Name;
}  Folder;

typedef struct {
    uint8_t ID;
    char* Name;
    float value;
    type_of_file type;
    bool selected;
} File;

typedef struct {
    menu_element_type type;

    union {
        Folder folder;
        File file;
    } element;

} Menu_element;

void init_menu();

void Move_up();
void Move_down();
void Select();
void Back();

Menu_element get_current_elm(); // returns currently selected or hovered element
int get_current_depth();
void change_bool_val_of_curr_elm(char val); // change bool value of current element
void change_float_val_of_curr_elm(float val); // change float value of current element

Menu_element** get_current_elms(int* num_of_elms); // get elements which should be currently displayed on the display
int get_hovered_elm_idx(); // if none element is hovered returns -1
int get_selected_elm_idx(); // if none element is selected returns -1

#endif