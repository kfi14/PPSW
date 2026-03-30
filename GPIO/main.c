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
	
			enum LedState{LED_MOVING_LEFT, LED_MOVING_RIGHT};
			enum LedState eLedState = LED_MOVING_LEFT;
			unsigned int uiLed_Step_Tracker = 0;
			LedInit();

			while(1){
				
				switch(eLedState){
					
					case LED_MOVING_LEFT:
						
						if((uiLed_Step_Tracker%6) < 3){
							LedStepLeft();
							uiLed_Step_Tracker++;
							goto delay;
						}
						else{
							eLedState = LED_MOVING_RIGHT;
						}
					
						
					case LED_MOVING_RIGHT:
						
					if((uiLed_Step_Tracker%6) >= 3){
						LedStepRight();
						uiLed_Step_Tracker++;
						goto delay;
					}
					else{
						eLedState = LED_MOVING_LEFT;
					}
					delay:
						Delay(250);
			}	
		}
}