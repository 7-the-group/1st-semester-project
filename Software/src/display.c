#include "display.h"
#include "i2cmaster.h"
#include "lcd.h"
#include <stdio.h>
#include <string.h>
#include <menu_helper.h>

void init_display()
{
    i2c_init();
    LCD_init();
}

char* pot_controlled_vals[6] = {"RED", "GREEN", "BLUE", "HUE", "SATURATION", "VALUE"};
char* color_formats[2] = {"RGB", "HSV"};

char* determine_enum_value(int element_id, float element_value)
{
    switch (element_id)
    {
        case 233:
        case 133:
            return pot_controlled_vals[(int)element_value];
        case 423:
            return color_formats[(int)element_value];
        default:
            return "E";
    }
}

void update_display(Menu_element* elems[4], int elements_count, int element_hovered, int element_selected)
{
    LCD_clear();
    char str_to_print[25];
    
    if (elements_count > 4)
    {
        elements_count = 4;
    }

    for (unsigned char i = 0; i < elements_count; i++) {
        LCD_set_cursor(1,i);
        if (elems[i]->type == MENU_FILE) {
            if (elems[i]->element.file.type == BOOL) {
                if (elems[i]->element.file.value == 0)
                    sprintf(str_to_print, "%s: %s", elems[i]->element.file.Name, "OFF");
                else 
                    sprintf(str_to_print, "%s: %s", elems[i]->element.file.Name, "ON");
            }
            else if (elems[i]->element.file.type == ENUM) {
                char* enum_val = determine_enum_value(elems[i]->element.file.ID, elems[i]->element.file.value);
                sprintf(str_to_print, "%s: %s", elems[i]->element.file.Name, enum_val);
            }
            else if (elems[i]->element.file.type == FLOAT) {
                sprintf(str_to_print, "%s: %3.2f", elems[i]->element.file.Name, elems[i]->element.file.value);
            }
            
            LCD_write_str(str_to_print);
        }
        else {
            sprintf(str_to_print, "%s", elems[i]->element.folder.Name);
            LCD_write_str(str_to_print);
            //printf("%d", elems[i]->element.folder.ID);
        }
    }

    if (element_hovered != -1) {
        LCD_set_cursor(0,element_hovered-1);
        LCD_write_char('*');
    }
    else {
        LCD_set_cursor(0,element_selected-1);
        LCD_write_char('>');
    }
}

void update_file_element(Menu_element* elem)
{
    char str_to_print[25];
    int position = get_last_level_pos(elem->element.file.ID);

    LCD_set_cursor(1, position - 1);
    LCD_write_str("                    ");

    LCD_set_cursor(1, position - 1);
    if (elem->element.file.type == BOOL) {
        if (elem->element.file.value == 0)
        {
            sprintf(str_to_print, "%s: %s", elem->element.file.Name, "OFF");
        }
        else
        {
            sprintf(str_to_print, "%s: %s", elem->element.file.Name, "ON");
        }
    }
    else if (elem->element.file.type == ENUM) 
    {
        char* enum_val = determine_enum_value(elem->element.file.ID, elem->element.file.value);
        sprintf(str_to_print, "%s: %s", elem->element.file.Name, enum_val);
    }
    else if (elem->element.file.type == FLOAT) 
    {
        sprintf(str_to_print, "%s: %3.1f", elem->element.file.Name, elem->element.file.value);
    }
}