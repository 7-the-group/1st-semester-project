#include <stdio.h>
#include <avr/io.h>
#include <util/delay.h>

#include "usart.h"
#include <room_2.h>
#include "menu.h"
#include "display.h"
#include <lcd.h>

int main(void)
{
  init_display();
  init_menu();

  //uart_init();
  //io_redirect();

  int number_of_elements;
  Menu_element* elems[4];
  get_current_elms(elems, &number_of_elements);

  LCD_clear();

  _delay_ms(5000);
  //printf("%d", (int)elems[1]->type);

  update_display(elems,number_of_elements,get_hovered_elm_idx(),get_selected_elm_idx());
  
  while(1);
}
