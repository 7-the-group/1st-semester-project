#include "display.h"
#include "i2cmaster.h"
#include "lcd.h"
#include <stdio.h>
#include <string.h>

void init_display()
{
    i2c_init();
    LCD_init();
}

void update_display(Menu_element* elems[4], int elements_count, int element_hovered, int element_selected)
{
    char str_to_print[25];
    
    if (elements_count > 4)
    {
        elements_count = 4;
    }

    for (int i = 0; i < elements_count; i++) {
        LCD_set_cursor(1,(unsigned char)i);
        if (elems[i]->type == MENU_FILE) {
            if (elems[i]->element.file.type == BOOL) {
                if (elems[i]->element.file.value == 0)
                    sprintf(str_to_print, "%s: %s", elems[i]->element.file.Name, "OFF");
                else 
                    sprintf(str_to_print, "%s: %s", elems[i]->element.file.Name, "ON");
            }

            else if (elems[i]->element.file.type == INT) {
                sprintf(str_to_print, "%s: %3.0f", elems[i]->element.file.Name, elems[i]->element.file.value);
            }

            else if (elems[i]->element.file.type = FLOAT) {
                sprintf(str_to_print, "%s: %3.1f", elems[i]->element.file.Name, elems[i]->element.file.value);
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