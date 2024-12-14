#include <control_panel.h>
#include <menu.h>
#include <display.h>
#include <avr/io.h>
#include <adcpwm.h>
#include <stdio.h>
#include <util/delay.h>

#include <functions_for_rooms.h>

#define SDU_BOARD_TESTING 0

#if !SDU_BOARD_TESTING
#define BTN_UP      7 // port D
#define BTN_DOWN    0 // port B
#define BTN_SELECT  3 // port B
#define BTN_BACK    4 // port B
#else
#define BTN_UP      0 // port D
#define BTN_DOWN    1 // port D
#define BTN_SELECT  2 // port D
#define BTN_BACK    3 // port D
#endif

enum
{
    IN_MENU,
    IN_FLOAT_ELM,
    IN_BOOL_ELM,
    IN_ENUM_ELM,
} current_position;

typedef enum
{
    PRESS_BTN_UP,
    PRESS_BTN_DOWN,
    PRESS_BTN_SELECT,
    PRESS_BTN_BACK,
    CHANGE_POT,
    NOTHING
} What_happened;

void show_curr_elems_on_display();

int check_btn_up()
{
    if ((PIND & (1 << BTN_UP)) == 0)
    {
        _delay_ms(100);
        return 1;
    }

    return 0;
}

int check_btn_down()
{
    if ((PINB & (1 << BTN_DOWN)) == 0)
    {
        _delay_ms(100);
        return 1;
    }

    return 0;
}

int check_btn_select()
{
    if ((PINB & (1 << BTN_SELECT)) == 0)
    {
        _delay_ms(100);
        return 1;
    }

    return 0;
}

int check_btn_back()
{
    if ((PINB & (1 << BTN_BACK)) == 0)
    {
        _delay_ms(100);
        return 1;
    }

    return 0;
}

void init_control_panel()
{
    init_display();
    init_menu();
    //adc_init();

    // set input and pull up for button up
    DDRD &= ~(1 << BTN_UP);
    PORTD |= (1 << BTN_UP);

    // set input and pull up for button down
    DDRB &= ~(1 << BTN_DOWN);
    PORTB |= (1 << BTN_DOWN);

    // set input and pull up for button select
    DDRB &= ~(1 << BTN_SELECT);
    PORTB |= (1 << BTN_SELECT);

    // set input and pull up for button back
    DDRB &= ~(1 << BTN_BACK);
    PORTB |= (1 << BTN_BACK);

    show_curr_elems_on_display();
}

void show_curr_elems_on_display()
{
    int elms_count;
    Menu_element* elms[4];
    get_current_elms(elms, &elms_count);

    int hovered_elm = get_hovered_elm_idx();
    int selected_elm = get_selected_elm_idx();
/*
    for (int i = 0; i < elms_count; i++)
    {
        if (i == hovered_elm - 1)
        {
            printf("* ");
        }
        else if (i == selected_elm - 1)
        {
            printf("> ");
        }
        else
        {
            printf("  ");
        }

        if (elms[i]->type == MENU_FILE)
        {
            printf("%s ", elms[i]->element.file.Name);
            printf("%3.2f", elms[i]->element.file.value);
        }
        else if (elms[i]->type == MENU_FOLDER)
        {
            printf("%s", elms[i]->element.folder.Name);
        }

        printf("\n");
    }*/

    update_display(elms, elms_count, hovered_elm, selected_elm);
}

void react_btn_up_pressed()
{
    Move_up();
    show_curr_elems_on_display();
}

void react_btn_down_pressed()
{
    Move_down();
    show_curr_elems_on_display();
}

void react_btn_select_pressed()
{
    Select();
    show_curr_elems_on_display();
}

void react_btn_back_pressed()
{
    Back();
    show_curr_elems_on_display();
}

void react_pot_value_changed()
{
    
}

What_happened check_controls()
{
    if (check_btn_up())
    {
        return PRESS_BTN_UP;
    }

    if (check_btn_down())
    {
        return PRESS_BTN_DOWN;
    }

    if (check_btn_select())
    {
        return PRESS_BTN_SELECT;
    }

    if (check_btn_back())
    {
        return PRESS_BTN_BACK;
    }

    if (check_btn_up())
    {
        return PRESS_BTN_UP;
    }

    return NOTHING;
}

void update_control_panel()
{/*
    char pressed_control;

    printf("Enter control: ");
    scanf("%c", &pressed_control);
    printf("\n");

    switch(pressed_control)
    {
        case 'w': // up
            react_btn_up_pressed();
            break;
        case 's': // select
            react_btn_select_pressed();
            break;
        case 'z': // down
            react_btn_down_pressed();
            break;
        case 'q': // back
            react_btn_back_pressed();
            break;
    }*/
    
    switch(check_controls())
    {
        case PRESS_BTN_UP:
            react_btn_up_pressed();
            break;
        case PRESS_BTN_DOWN:
            react_btn_down_pressed();
            break;
        case PRESS_BTN_SELECT:
            react_btn_select_pressed();
            break;
        case PRESS_BTN_BACK:
            react_btn_back_pressed();
            break;
        case CHANGE_POT:
            react_pot_value_changed();
            break;
        case NOTHING:
            break;
    }

    Menu_element* curr_elems[4];
    int element_count;

    get_current_elms(curr_elems, &element_count);

    for (int i = 0; i < element_count; i++)
    {
        if (curr_elems[i]->type == MENU_FILE)
        {
            get_value_func get_value = get_getter_func(curr_elems[i]->element.file.value);
            float new_value = get_value();

            if (new_value != curr_elems[i]->element.file.value)
            {
                curr_elems[i]->element.file.value = new_value;
                update_file_element(curr_elems[i]);
            }
        }
    }

/*
    switch (curr_element->type)
    {
        case MENU_FOLDER:
            current_position = IN_MENU;
            break;
        case MENU_FILE:
            if (curr_element->element.file.selected)
            {
                switch (curr_element->element.file.type)
                {
                    case FLOAT:
                        current_position = IN_FLOAT_ELM;
                        break;
                    case BOOL:
                        current_position = IN_BOOL_ELM;
                        break;
                }
            }
            else
            {
                current_position = IN_MENU;
            }
    }*/
    
}