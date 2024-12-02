#include "menu.h"
#include <math.h>
#include <stdint.h>
#include "menu_helper.h"

int menu_position[3]; 
Menu_element menu_elements[19];

void init_menu()
{
    /* File fileElm1;
    fileElm1.ID = 23;
    fileElm1.Name = "LED 1";
    fileElm1.type = INT;
    fileElm1.value = 78;
    Menu_element elm;
    elm.type = MENU_FILE;
    elm.element.file = fileElm1;

    Folder FolderElm2;
    FolderElm2.ID = 33;
    FolderElm2.Name = "LED 1";
    Menu_element elm2;
    elm2.type = MENU_FOLDER;
    elm2.element.folder = FolderElm2;

    menu_elements[0] = elm;
    menu_elements[1] = elm2; */

    // main menu Room1
    Folder folderElm1;
    folderElm1.ID = 1;
    folderElm1.Name = "ROOM 1";

    Menu_element elm1;
    elm1.type = MENU_FOLDER;
    elm1.element.folder = folderElm1;

    // main menu Room2
    Folder folderElm2;
    folderElm2.ID = 2;
    folderElm2.Name = "ROOM 2";

    Menu_element elm2;
    elm2.type = MENU_FOLDER;
    elm2.element.folder = folderElm2;

    // main menu Room3
    Folder folderElm3;
    folderElm3.ID = 3;
    folderElm3.Name = "ROOM 3";

    Menu_element elm3;
    elm3.type = MENU_FOLDER;
    elm3.element.folder = folderElm3;

    // main menu Door
    Folder folderElm4;
    folderElm4.ID = 4;
    folderElm4.Name = "DOOR";

    Menu_element elm4;
    elm4.type = MENU_FOLDER;
    elm4.element.folder = folderElm4;

    // Room 1 Pot
    File fileElm1;
    fileElm1.ID = 11;
    fileElm1.Name = "Brightness";
    fileElm1.type = FLOAT;
    fileElm1.value = 0;

    Menu_element elm5;
    elm5.type = MENU_FILE;
    elm5.element.file = fileElm1;

    // Room 1 LED
    File fileElm2;
    fileElm2.ID = 21;
    fileElm2.Name = "Light status";
    fileElm2.type = BOOL;
    fileElm2.value = 0;

    Menu_element elm6;
    elm6.type = MENU_FILE;
    elm6.element.file = fileElm2;

    // Room 2 LED
    File fileElm3;
    fileElm3.ID = 12;
    fileElm3.Name = "Light status";
    fileElm3.type = BOOL;
    fileElm3.value = 0;

    Menu_element elm7;
    elm7.type = MENU_FILE;
    elm7.element.file = fileElm3;

    // Room 3 LED
    File fileElm4;
    fileElm4.ID = 13;
    fileElm4.Name = "Light status";
    fileElm4.type = BOOL;
    fileElm4.value = 0;

    Menu_element elm8;
    elm8.type = MENU_FILE;
    elm8.element.file = fileElm4;

    // Room 3 LED Color
    Folder folderElm5;
    folderElm5.ID = 23;
    folderElm5.Name = "Color";

    Menu_element elm9;
    elm9.type = MENU_FOLDER;
    elm9.element.folder = folderElm5;

    // Room 3 Potentiometers
    Folder folderElm6;
    folderElm6.ID = 33;
    folderElm6.Name = "Potentiometer type";

    Menu_element elm10;
    elm10.type = MENU_FOLDER;
    elm10.element.folder = folderElm6;

    // Door LDR
    File fileElm5;
    fileElm5.ID = 14;
    fileElm5.Name = "Outside brightness";
    fileElm5.type = FLOAT;
    fileElm5.value = 0;

    Menu_element elm11;
    elm11.type = MENU_FILE;
    elm11.element.file = fileElm5;

    // Door PIR
    File fileElm6;
    fileElm6.ID = 24;
    fileElm6.Name = "Outside movement";
    fileElm6.type = BOOL;
    fileElm6.value = 0;

    Menu_element elm12;
    elm12.type = MENU_FILE;
    elm12.element.file = fileElm6;

    // Door LDR threshold
    File fileElm7;
    fileElm7.ID = 34;
    fileElm7.Name = "LDR threshold";
    fileElm7.type = FLOAT;
    fileElm7.value = 0;

    Menu_element elm13;
    elm13.type = MENU_FILE;
    elm13.element.file = fileElm7;

    // Room 3 LED Val 1
    File fileElm8;
    fileElm8.ID = 123;
    fileElm8.Name = "Value 1";
    fileElm8.type = FLOAT;
    fileElm8.value = 0;

    Menu_element elm14;
    elm14.type = MENU_FILE;
    elm14.element.file = fileElm8;

    // Room 3 LED Val 2
    File fileElm9;
    fileElm9.ID = 223;
    fileElm9.Name = "Value 2";
    fileElm9.type = FLOAT;
    fileElm9.value = 0;

    Menu_element elm15;
    elm15.type = MENU_FILE;
    elm15.element.file = fileElm9;

    // Room 3 LED Val 3
    File fileElm10;
    fileElm10.ID = 323;
    fileElm10.Name = "Value 3";
    fileElm10.type = FLOAT;
    fileElm10.value = 0;

    Menu_element elm16;
    elm16.type = MENU_FILE;
    elm16.element.file = fileElm10;

    // Room 3 LED Format
    File fileElm11;
    fileElm11.ID = 423;
    fileElm11.Name = "Change format";
    fileElm11.type = BOOL;
    fileElm11.value = 0;

    Menu_element elm17;
    elm17.type = MENU_FILE;
    elm17.element.file = fileElm11;

    // Room 3 Potentiometer 1
    File fileElm12;
    fileElm12.ID = 133;
    fileElm12.Name = "Potentiometer 1";
    fileElm12.type = FLOAT;
    fileElm12.value = 0;

    Menu_element elm18;
    elm18.type = MENU_FILE;
    elm18.element.file = fileElm12;

    // Room 3 Potentiometer 2
    File fileElm13;
    fileElm13.ID = 233;
    fileElm13.Name = "Potentiometer 2";
    fileElm13.type = FLOAT;
    fileElm13.value = 0;

    Menu_element elm19;
    elm19.type = MENU_FILE;
    elm19.element.file = fileElm13;

    // add to array
    menu_elements[0] = elm1;
    menu_elements[1] = elm2;
    menu_elements[2] = elm3;
    menu_elements[3] = elm4;
    menu_elements[4] = elm5;
    menu_elements[5] = elm6;
    menu_elements[6] = elm7;
    menu_elements[7] = elm8;
    menu_elements[8] = elm9;
    menu_elements[9] = elm10;
    menu_elements[10] = elm11;
    menu_elements[11] = elm12;
    menu_elements[12] = elm13;
    menu_elements[13] = elm14;
    menu_elements[14] = elm15;
    menu_elements[15] = elm16;
    menu_elements[16] = elm17;
    menu_elements[17] = elm18;
    menu_elements[18] = elm19;
}

Menu_element get_current_elm() {
    // find the current depth
    unsigned char depth = 0;
    for (int i=0; i<3;i++) {
        if (menu_position[i]!=-1) {
            depth++;
        }
    }

    // deduce ID of element based on the current menu position
    uint8_t elementID = 0;
    for (int i=0; i<depth;i++) {
        elementID+=menu_position[i]*pow(i,10);
    }

    for (int i=0;i<19;i++) {
        if (menu_elements[i].type==MENU_FILE) {
            if (elementID == menu_elements[i].element.file.ID) return menu_elements[i];
        }
        else {
            if (elementID == menu_elements[i].element.folder.ID) return menu_elements[i];
        }
    }
}

void change_bool_val_of_curr_elm(char val) {
    Menu_element current_element = get_current_elm();
    current_element.element.file.value += val;
}

void change_float_val_of_curr_element(float val) {
    Menu_element current_element = get_current_elm();
    current_element.element.file.value += val;
}

Menu_element* get_current_elms(int* num_of_elms) {
    uint8_t current_ID;
    Menu_element current_element = get_current_elm();

    if (current_element.type == MENU_FILE) current_ID = current_element.element.file.ID;
    else current_ID = current_element.element.folder.ID;

    Menu_element new_menu[*num_of_elms];
    
    for (int i = 0; i < 19; i++)
    {
        if (menu_elements[i].type == MENU_FILE) {
            // depth 1
            if (get_2nd_level_pos(current_ID) == -1 && get_2nd_level_pos(menu_elements[i].element.file.ID) == -1) 
                new_menu[get_1st_level_pos(menu_elements[i].element.file.ID) - 1] = menu_elements[i];
            // depth 2
            else if (get_3rd_level_pos(current_ID) == -1 && get_3rd_level_pos(menu_elements[i].element.file.ID) == -1 
                && get_1st_level_pos(current_ID) == get_1st_level_pos(menu_elements[i].element.file.ID))
                    new_menu[get_2nd_level_pos(menu_elements[i].element.file.ID) - 1] = menu_elements[i];
            // depth 3
            else if (get_1st_level_pos(current_ID) == get_1st_level_pos(menu_elements[i].element.file.ID) 
                && get_2nd_level_pos(current_ID) == get_2nd_level_pos(menu_elements[i].element.file.ID))
                    new_menu[get_3rd_level_pos(menu_elements[i].element.file.ID) - 1] = menu_elements[i];
        }

        else {
            // depth 1
            if (get_2nd_level_pos(current_ID == -1) && get_2nd_level_pos(menu_elements[i].element.folder.ID) == -1)
                new_menu[get_1st_level_pos(menu_elements[i].element.folder.ID) - 1] = menu_elements[i];
            // depth 2
            else if (get_3rd_level_pos(current_ID) == -1 && get_3rd_level_pos(menu_elements[i].element.folder.ID) == -1
                && get_1st_level_pos(current_ID) == get_2nd_level_pos(menu_elements[i].element.folder.ID))
                    new_menu[get_2nd_level_pos(menu_elements[i].element.folder.ID) - 1] = menu_elements[i];
            // depth 3
            else if (get_1st_level_pos(current_ID) == get_1st_level_pos(menu_elements[i].element.folder.ID)
                && get_2nd_level_pos(current_ID) == get_2nd_level_pos(menu_elements[i].element.folder.ID))
                    new_menu[get_3rd_level_pos(menu_elements[i].element.folder.ID) - 1] = menu_elements[i];
        }
    }

    return &new_menu;
}