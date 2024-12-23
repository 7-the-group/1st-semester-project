#include <functions_for_rooms.h>

#include <room_1.h>
#include <room_2.h>
#include <room_3.h>
#include <door.h>
#include <color.h>
#include <menu.h>

float get_room1_led_brightness(); // id = 11
float get_room1_led_status(); // id = 21
float get_room2_led_status(); // id = 12
float get_room3_led_status(); // id = 13
float get_door_ldr_value(); // id = 14
float get_door_movement(); // id = 24
float get_ldr_threshold(); // id = 34
float get_door_led_status(); // id = 44
float get_room3_led_value1(); // id = 123
float get_room3_led_value2(); // id = 223
float get_room3_led_value3(); // id = 323
float get_room3_color_format(); // id = 423
float get_room3_pot1_controlled_val(); // id = 133

void change_room1_led_brightness_by(int); // id = 11
void change_room1_led_status_by(int); // id = 21
void change_room2_led_status_by(int); // id = 12
void change_room3_led_status_by(int); // id = 13
void change_ldr_threshold_by(int); // id = 34
void change_door_led_status_by(int); // id = 44
void change_room3_led_value1_by(int); // id = 123
void change_room3_led_value2_by(int); // id = 223
void change_room3_led_value3_by(int); // id = 323
void change_room3_color_format_by(int); // id = 423
void change_room3_pot1_controlled_val_by(int); // id = 133

get_value_func get_getter_func(int id)
{
    switch (id)
    {
        case 11:
            return get_room1_led_brightness;
        case 21:
            return get_room1_led_status;
        case 12:
            return get_room2_led_status;
        case 13:
            return get_room3_led_status;
        case 14:
            return get_door_ldr_value;
        case 24:
            return get_door_movement;
        case 34:
            return get_ldr_threshold;
        case 44:
            return get_door_led_status;
        case 123:
            return get_room3_led_value1;
        case 223:
            return get_room3_led_value2;
        case 323:
            return get_room3_led_value3;
        case 423:
            return get_room3_color_format;
        case 133:
            return get_room3_pot1_controlled_val;
        default:
            return 0;
    }
}

change_value_by_func get_changer_func(int id)
{
    switch (id)
    {
        case 11:
            return change_room1_led_brightness_by;
        case 21:
            return change_room1_led_status_by;
        case 12:
            return change_room2_led_status_by;
        case 13:
            return change_room3_led_status_by;
        case 34:
            return change_ldr_threshold_by;
        case 44:
            return change_door_led_status_by;
        case 123:
            return change_room3_led_value1_by;
        case 223:
            return change_room3_led_value2_by;
        case 323:
            return change_room3_led_value3_by;
        case 423:
            return change_room3_color_format_by;
        case 133:
            return change_room3_pot1_controlled_val_by;
        default:
            return 0;
    }
}

void update_color_RGB_room_3()
{
    Menu_element* value1_elem = get_element_by_id(123);
    Menu_element* value2_elem = get_element_by_id(223);
    Menu_element* value3_elem = get_element_by_id(323);
    
    ColorRGB rgb;
    rgb.r = (uint8_t)value1_elem->element.file.value;
    rgb.g = (uint8_t)value2_elem->element.file.value;
    rgb.b = (uint8_t)value3_elem->element.file.value;

    set_color_of_light_RGB_room_3(rgb);
}

void update_color_HSV_room_3()
{
    Menu_element* value1_elem = get_element_by_id(123);
    Menu_element* value2_elem = get_element_by_id(223);
    Menu_element* value3_elem = get_element_by_id(323);
    
    ColorHSV hsv;
    hsv.h = (uint16_t)value1_elem->element.file.value;
    hsv.s = (float)value2_elem->element.file.value;
    hsv.v = (float)value3_elem->element.file.value;

    set_color_of_light_HSV_room_3(hsv);
}

float get_room1_led_brightness()
{
    return (float)get_light_intensity_room_1();
}

float get_room1_led_status()
{
    return (float)(get_light_intensity_room_1() != 0);
}

float get_room2_led_status()
{
    return (float)get_status_of_light_room_2();
}

float get_room3_led_status()
{
    return (float)get_status_of_light_room_3();
}

float get_door_led_status()
{
    return (float)get_door_light_status();
}

float get_door_movement()
{
    return (float)movement_detected_door();
}

float get_ldr_threshold()
{
    return (float)get_ldr_threshold_door();
}

float get_door_ldr_value()
{
    return get_ldr_value_door();
}

float get_room3_led_value1()
{
    Menu_element* elm = get_element_by_id(423);

    if (elm->element.file.value == 0.0f) // RGB
    {
        return (float)get_color_of_light_RGB_room_3().r;
    }
    else if (elm->element.file.value == 1.0f) // HSV
    {
        return (float)get_color_of_light_HSV_room_3().h;
    }
}

float get_room3_led_value2()
{
    Menu_element* elm = get_element_by_id(423);

    if (elm->element.file.value == 0.0f) // RGB
    {
        return (float)get_color_of_light_RGB_room_3().g;
    }
    else if (elm->element.file.value == 1.0f) // HSV
    {
        return (float)get_color_of_light_HSV_room_3().s;
    }
}

float get_room3_led_value3()
{
    Menu_element* elm = get_element_by_id(423);

    if (elm->element.file.value == 0.0f) // RGB
    {
        return (float)get_color_of_light_RGB_room_3().b;
    }
    else if (elm->element.file.value == 1.0f) // HSV
    {
        return (float)get_color_of_light_HSV_room_3().v;
    }
}

float get_room3_color_format()
{
    return (float)get_element_by_id(423)->element.file.value;
}

float get_room3_pot1_controlled_val()
{
    return (float)pot_1_controlled_val_room_3;
}

void change_room1_led_brightness_by(int amount)
{
    Menu_element* elem = get_element_by_id(11);

    elem->element.file.value += (float)amount;

    if (elem->element.file.value < 0.0f)
    {
        elem->element.file.value = 255.0f;
    }

    if (elem->element.file.value > 255.0f)
    {
        elem->element.file.value = 0.0f;
    }

    set_light_intensity_room_1((unsigned char)elem->element.file.value);
}

void change_room1_led_status_by(int amount)
{
    Menu_element* elem = get_element_by_id(21);

    elem->element.file.value = (int)(elem->element.file.value + amount) % 2;

    if (elem->element.file.value < 0.0f)
    {
        elem->element.file.value = 2.0f + elem->element.file.value;
    }

    if (elem->element.file.value == 1.0f)
    {
        turn_on_light_room_1();
    }
    else
    {
        turn_off_light_room_1();
    }
}

void change_room2_led_status_by(int amount) // id = 12
{
    Menu_element* elem = get_element_by_id(12);

    elem->element.file.value = (int)(elem->element.file.value + amount) % 2;

    if (elem->element.file.value < 0.0f)
    {
        elem->element.file.value = 2.0f + elem->element.file.value;
    }

    if (elem->element.file.value == 1.0f)
    {
        turn_on_light_room_2();
    }
    else
    {
        turn_off_light_room_2();
    }
}

void change_room3_led_status_by(int amount) // id = 13
{
    Menu_element* elem = get_element_by_id(13);

    elem->element.file.value = (int)(elem->element.file.value + amount) % 2;

    if (elem->element.file.value < 0.0f)
    {
        elem->element.file.value = 2.0f + elem->element.file.value;
    }

    if (elem->element.file.value == 1.0f)
    {
        turn_on_light_room_3();
    }
    else
    {
        turn_off_light_room_3();
    }
}

void change_door_led_status_by(int amount) // id = 44
{
    Menu_element* elem = get_element_by_id(14);

    elem->element.file.value = (int)(elem->element.file.value + amount) % 2;

    if (elem->element.file.value < 0.0f)
    {
        elem->element.file.value = 2.0f + elem->element.file.value;
    }

    if (elem->element.file.value == 1.0f)
    {
        turn_on_light_manually_door();
    }
    else
    {
        turn_off_light_manually_door();
    }
}

void change_ldr_threshold_by(int amount) // id = 34
{
    Menu_element* elem = get_element_by_id(34);

    elem->element.file.value = (int)(elem->element.file.value + amount) % 1024;

    if (elem->element.file.value < 0.0f)
    {
        elem->element.file.value = 1024.0f + elem->element.file.value;
    }

    set_ldr_threshold_door((int)elem->element.file.value);
}

void change_room3_led_value1_by(int amount) // id = 123
{
    Menu_element* elem = get_element_by_id(123);
    Menu_element* format_elm = get_element_by_id(423);

    if (format_elm->element.file.value == 0) // RGB
    {
        elem->element.file.value = (int)(elem->element.file.value + amount) % 256;

        if (elem->element.file.value < 0.0f)
        {
            elem->element.file.value = 256.0f + elem->element.file.value;
        }

        update_color_RGB_room_3();
    }
    else // HSV
    {
        elem->element.file.value += amount;

        if (elem->element.file.value < 0.0f)
        {
            elem->element.file.value = 359.0f;
        }

        if (elem->element.file.value >= 360.0f)
        {
            elem->element.file.value = 0.0f;
        }

        update_color_HSV_room_3();
    }
}

void change_room3_led_value2_by(int amount) // id = 223
{
    Menu_element* elem = get_element_by_id(223);
    Menu_element* format_elm = get_element_by_id(423);
    float amount_float = (float)amount * 0.01f;

    if (format_elm->element.file.value == 0) // RGB
    {
        elem->element.file.value = (int)(elem->element.file.value + amount) % 256;

        if (elem->element.file.value < 0.0f)
        {
            elem->element.file.value = 256.0f + elem->element.file.value;
        }

        update_color_RGB_room_3();
    }
    else // HSV
    {
        elem->element.file.value = elem->element.file.value + amount_float;

        if (elem->element.file.value > 1.0f)
        {
            elem->element.file.value = 0.0f;
        }

        if (elem->element.file.value < 0.0f)
        {
            elem->element.file.value = 1.0f;
        }

        update_color_HSV_room_3();
    }
}

void change_room3_led_value3_by(int amount) // id = 323
{
    Menu_element* elem = get_element_by_id(323);
    Menu_element* format_elm = get_element_by_id(423);
    float amount_float = (float)amount * 0.01f;

    if (format_elm->element.file.value == 0) // RGB
    {
        elem->element.file.value = (int)(elem->element.file.value + amount) % 256;

        if (elem->element.file.value < 0.0f)
        {
            elem->element.file.value = 256.0f + elem->element.file.value;
        }

        update_color_RGB_room_3();
    }
    else // HSV
    {
        elem->element.file.value = elem->element.file.value + amount_float;

        if (elem->element.file.value > 1.0f)
        {
            elem->element.file.value = 0.0f;
        }

        if (elem->element.file.value < 0.0f)
        {
            elem->element.file.value = 1.0f;
        }

        update_color_HSV_room_3();
    }
}

void change_room3_color_format_by(int amount) // id = 423
{
    Menu_element* elem = get_element_by_id(423);

    elem->element.file.value = (int)(elem->element.file.value + amount) % 2;

    if (elem->element.file.value < 0.0f)
    {
        elem->element.file.value = 2.0f + elem->element.file.value;
    }

    Menu_element* value1_elem = get_element_by_id(123);
    Menu_element* value2_elem = get_element_by_id(223);
    Menu_element* value3_elem = get_element_by_id(323);

    if (elem->element.file.value == 1.0f)
    {
        ColorRGB rgb;
        rgb.r = (uint8_t)value1_elem->element.file.value;
        rgb.g = (uint8_t)value2_elem->element.file.value;
        rgb.b = (uint8_t)value3_elem->element.file.value;

        ColorHSV hsv = convert_RGB_to_HSV(rgb);

        value1_elem->element.file.value = (float)hsv.h;
        value2_elem->element.file.value = (float)hsv.s;
        value3_elem->element.file.value = (float)hsv.v;
    }
    else if (elem->element.file.value == 0.0f)
    {
        ColorHSV hsv;
        hsv.h = (uint16_t)value1_elem->element.file.value;
        hsv.s = (float)value2_elem->element.file.value;
        hsv.v = (float)value3_elem->element.file.value;

        ColorRGB rgb = convert_HSV_to_RGB(hsv);

        value1_elem->element.file.value = (float)rgb.r;
        value2_elem->element.file.value = (float)rgb.g;
        value3_elem->element.file.value = (float)rgb.b;
    }
}

void change_room3_pot1_controlled_val_by(int amount) // id = 133
{
    Menu_element* elem = get_element_by_id(133);

    elem->element.file.value = (int)(elem->element.file.value + amount) % 6;

    if (elem->element.file.value < 0.0f)
    {
        elem->element.file.value = 6.0f + elem->element.file.value;
    }

    pot_1_controlled_val_room_3 = (int)(elem->element.file.value);
}