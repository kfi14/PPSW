#ifndef gpio_16_17_18_19_h
#define gpio_16_17_18_19_h


enum KeyboardState {RELEASED, BUTTON_0, BUTTON_1, BUTTON_2, BUTTON_3};

enum KeyboardState eKeyboardRead(void);

void KeyboardInit(void);


#endif