#include <stdio.h>
#include <avr/io.h>
#include <util/delay.h>

#include "usart.h"
#include <room_2.h>
#include "menu.h"

int main(void)
{
  uart_init();
  io_redirect();
  // init all rooms
  // init_room_2();

  File new_file;
  Folder new_folder;

  Menu_element element_file;
  Menu_element element_folder;
  element_file.type = MENU_FILE;
  element_file.element.file = new_file;
  element_folder.type = MENU_FOLDER;
  element_file.element.folder = new_folder;

  Menu_element elms[4][4][4][4][4];

  while(1)
  {
    // update_room_2();
  }
}
