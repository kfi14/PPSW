#include "led.h"
#include "keyboard.h"



void Delay(unsigned int uiMiliseconds) 
{
    unsigned int uiMilisecondsCounter;
        unsigned int uiDelayCounter;

    for (uiMilisecondsCounter = 0; uiMilisecondsCounter < uiMiliseconds; uiMilisecondsCounter++) {

        for (uiDelayCounter = 0; uiDelayCounter < 7000; uiDelayCounter++) {
        }
    }
}


int main(void){
	
			enum LedState{LED_MOVING_LEFT, LED_MOVING_RIGHT, LED_STOPPED};
			enum LedState eLedState = LED_STOPPED;

			LedInit();
			KeyboardInit();

			while(1){
				
				switch(eLedState){
					
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
			Delay(100);
		}
}
