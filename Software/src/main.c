// standard libraries
#include <stdio.h>
#include <avr/io.h>
#include <util/delay.h>

// Alin's libraries
#include "usart.h"
#include "lcd.h"
#include "adcpwm.h"

// Our libraries ☭
#include "room_1.h"
#include "room_2.h"
#include "room_3.h"
#include "door.h"
#include "control_panel.h"

int main(void)
{
  //init_room_1();
  //init_room_2();
  init_room_3();
  //init_door();

  init_control_panel();
  while(1)
  {
    //update_room_1();
    //update_room_2();
    update_room_3();
    //update_door();

    update_control_panel();
  }
}
