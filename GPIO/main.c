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
	
			enum LedState{LED_MOVING, LED_STOPPED};
			enum LedState eLedState = LED_MOVING;

			LedInit();
			KeyboardInit();

			while(1){
				
				switch(eLedState){
					
					case LED_STOPPED:
						
						if(eKeyboardRead() == BUTTON_1 ){
							eLedState = LED_MOVING;
						}
						
						else{
							eLedState = LED_STOPPED;
						}
						
					break;
						
					case LED_MOVING:
						
						if(eKeyboardRead() == BUTTON_0){
							eLedState = LED_STOPPED;
						}
						
						else{
							LedStepRight();
							eLedState = LED_MOVING;
						}
						
					break;						
			}		
			Delay(250);
		}
}