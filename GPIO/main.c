#include "led.h"
#include "timer_interrupts.h"
#include "keyboard.h"
#include "servo.h"


int main (void) {
  
    LedInit();
		KeyboardInit();
		DetectorInit();

    Timer0InterruptsInit(20000,&AutomatServo);

    while(1) {
        if(eKeyboardRead() == BUTTON_0){
					sServo.eState = CALLIB;
				}
				else if(eKeyboardRead() == BUTTON_1){
					sServo.uiDesiredPosition = 12;
				}
				else if(eKeyboardRead() == BUTTON_2){
					sServo.uiDesiredPosition = 24;
				}
				else if(eKeyboardRead() == BUTTON_3){
					sServo.uiDesiredPosition = 36;
				}
					
    }
}
