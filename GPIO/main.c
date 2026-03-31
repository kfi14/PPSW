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
						
						if(uiLed_Step_Tracker < 2){
							LedStepLeft();
							uiLed_Step_Tracker++;
							eLedState = LED_MOVING_LEFT;
						}
						
						else{
							LedStepLeft();
							uiLed_Step_Tracker = 0;
							eLedState = LED_MOVING_RIGHT;
						}
						
						break;
								
					case LED_MOVING_RIGHT:
						
						if(uiLed_Step_Tracker < 2){
							LedStepRight();
							uiLed_Step_Tracker++;
							eLedState = LED_MOVING_RIGHT;
						}	
						
						else{
							LedStepRight();
							uiLed_Step_Tracker = 0;
							eLedState = LED_MOVING_LEFT;
						}
						
						break;
			}		
			Delay(250);
		}
}