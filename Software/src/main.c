// standard libraries
#include <stdio.h>
#include <avr/io.h>
#include <util/delay.h>

// Alin's libraries
#include <usart.h>
#include <lcd.h>

// Our libraries ☭
#include <room_1.h>
#include <room_2.h>
#include "room_3.h"
#include <door.h>
#include <control_panel.h>
#include <color.h>
#include "menu.h"

int main(void)
{
  //uart_init();
  //io_redirect();

  //init_room_1();
  //init_room_2();
  init_room_3();
  ColorRGB color;
  color.r = 128;
  color.g = 128;
  color.b = 128;
  set_color_of_light_RGB_room_3(color);
  //init_door();
  //init_control_panel();

  /*while (1) {
    update_room_1();
    update_room_2();
    update_room_3();
    update_door();
  }

  while(1)
  {
    _delay_ms(50);
    printf("%d\n", movement_detected());
    //ColorRGB color = {0, 0, 0};
    //switch_door_light();
    //update_room_1();
    //update_room_2();
    //update_room3();
    //update_door();
    //update_control_panel();
  } 

  init_display();
  init_menu();
  //uart_init();
  //io_redirect();
  int number_of_elements;
  Menu_element* elems[4];
  get_current_elms(elems, &number_of_elements);
  LCD_clear();

  update_display(elems,number_of_elements,get_hovered_elm_idx(),get_selected_elm_idx()); */
}
