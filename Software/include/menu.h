#ifndef MENU
#define MENU

#include <stdint.h>

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
    char Name[19];
}  Folder;

typedef struct {
    uint8_t ID;
    char Name[19];
    float value;
    type_of_file type;
} File;

typedef struct {
    menu_element_type type;

    union {
        Folder folder;
        File file;
    } element;

} Menu_element;

// move up||down by one
// current element selected
// 

#endif