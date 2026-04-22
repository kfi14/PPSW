#include "led.h"
#include "timer_interrupts.h"
#include "keyboard.h"
#include "servo.h"


int main(void){
  
    KeyboardInit();
		ServoInit(25);
		ServoGoTo(24);
		ServoGoTo(12);

    while(1) {
        if(eKeyboardRead() == BUTTON_0){
					ServoCallib();
				}
				else if(eKeyboardRead() == BUTTON_1){
					ServoGoTo(12);
				}
				else if(eKeyboardRead() == BUTTON_2){
					ServoGoTo(24);
				}
				else if(eKeyboardRead() == BUTTON_3){
					ServoGoTo(36);
				}
					
    }
}
