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
#include <room_3.h>
#include <door.h>
#include <control_panel.h>
#include <color.h>

int main(void)
{
  init_room_1();
  init_room_2();
  init_room_3();
  init_door();
  //init_control_panel();

  uart_init();
  io_redirect();

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
}
