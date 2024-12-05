#include "display.h"
#include "i2cmaster.h"
#include "lcd.h"

void init_display()
{
    i2c_init();
    LCD_init();
}

void update_display(Menu_element* elems, int elements_count, int element_hovered, int element_selected)
{
    char cursor;
    
    for (int i = 0; i < elements_count; i++) {
        LCD_set_cursor(1,i);
        if (elems[i].type == MENU_FILE) {
            if (elems[i].element.file.selected) {
                printf("%s: %s", elems[i].element.file.Name, elems[i].element.file.value);
            }
            else {
                printf("%s", elems[i].element.file.Name);
            }
        }
        else {
            pritf("%s", elems[i].element.folder.Name);
        }
    }

    if (element_hovered != -1) {
        cursor = "*";
        LCD_set_cursor(0,element_hovered-1);
        printf("%c", &cursor);
    }
    else {
        cursor = ">";
        LCD_set_cursor(0,element_selected-1);
    }
}