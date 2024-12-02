#include <stdio.h>
#include <avr/io.h>
#include <util/delay.h>

#include "usart.h"
#include <room_2.h>
#include "menu.h"
#include "display.h"

int main(void)
{
  init_display();

  while (1)
  {
    update_display();
  }
  
}
