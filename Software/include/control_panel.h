#ifndef CONTROL_PANEL
#define CONTROL_PANEL

#define BUTTON_UP
#define BUTTON_DOWN
#define BUTTON_SELECT
#define BUTTON_BACK
#define BUTTON_AUTO

int button_up_pressed();
int button_down_pressed();
int button_select_pressed();
int button_back_pressed();
int button_auto_pressed();

int potentiometer_moved();

#endif