#include <control_panel.h>
#include <menu.h>
#include <display.h>
#include <avr/io.h>
#include <adcpwm.h>

#include <room_2.h>
#include <room_3.h>
#include <door.h>

#define BTN_UP      7 // port D
#define BTN_DOWN    0 // port B
#define BTN_SELECT  3 // port B
#define BTN_BACK    4 // port B
#define POT_PIN     0 // port C

enum
{
    IN_MENU,
    IN_FLOAT_ELM,
    IN_ENUM_ELM,
} current_position;

typedef enum
{
    PRESS_BTN_UP,
    PRESS_BTN_DOWN,
    PRESS_BTN_SELECT,
    PRESS_BTN_BACK,
    CHANGE_POT
} What_happened;

Menu_element* curr_element = 0;

int check_btn_up()
{
    return PIND & (1 << BTN_UP) != 0;
}

int check_btn_down()
{
    return PINB & (1 << BTN_DOWN) != 0;
}

int check_btn_select()
{
    return PINB & (1 << BTN_SELECT) != 0;
}

int check_btn_back()
{
    return PINB & (1 << BTN_BACK) != 0;
}

uint16_t read_pot_value()
{
    return adc_read(POT_PIN);
}

void init_control_panel()
{
    init_display();
    init_menu();
    adc_init();

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
}

void show_curr_elems_on_display()
{
    int elms_count;
    Menu_element* elms[4];
    get_current_elms(elms, &elms_count);

    int hovered_elm = get_hovered_elm_idx();
    int selected_elm = get_selected_elm_idx();

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
}

void update_control_panel()
{
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
    }
}