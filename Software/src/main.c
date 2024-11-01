#include <stdio.h>
#include <avr/io.h>
#include <util/delay.h>

#include "usart.h"
#include <room_2.h>

int main(void)
{
  // init all rooms
  init_room_2();

  while(1)
  {
    update_room_2();
  }
}
