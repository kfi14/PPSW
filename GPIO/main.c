#include "led.h"
#include "timer_interrupts.h"
#include "keyboard.h"
#include "servo.h"

void Automat(void){
	
			enum LedState{LED_MOVING_LEFT, LED_MOVING_RIGHT, LED_STOPPED, CALLIB};
			static enum LedState eLedState = CALLIB;


				switch(eLedState){
					
					case CALLIB:
						
						if(eReadDetector() == INACTIVE){
							LedStepLeft();
							eLedState = CALLIB;
						}
						else{
							eLedState = LED_STOPPED;
						}
						
					break;
							
						
					case LED_STOPPED:
						
						if(eKeyboardRead() == BUTTON_0){
							eLedState = LED_MOVING_LEFT;
						}		
						
						else if(eKeyboardRead() == BUTTON_2){
							eLedState = LED_MOVING_RIGHT;
						}			
						
						else{
							eLedState = LED_STOPPED;
						}
						
					break;
						
					case LED_MOVING_LEFT:
						
						if(eKeyboardRead() == BUTTON_1){
							eLedState = LED_STOPPED;
						}
						
						else{
							LedStepLeft();
							eLedState = LED_MOVING_LEFT;
						}
						
					break;			

					case LED_MOVING_RIGHT:
						
						if(eKeyboardRead() == BUTTON_1){
							eLedState = LED_STOPPED;
						}
						
						else{
							LedStepRight();
							eLedState = LED_MOVING_RIGHT;
						}
						
					break;
			}		
		}


int main (void) {
    unsigned int iMainLoopCtr = 0;
    
    LedInit();
		KeyboardInit();

    Timer0InterruptsInit(20000,&Automat);

    while(1) {
        iMainLoopCtr++;
    }
}
