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
	
			enum LedState{LED_LEFT, LED_RIGHT};
			enum LedState eLedState = LED_LEFT;
			unsigned int uiLed_Step_Tracker = 0;
			LedInit();

			while(1){
				
				switch(eLedState){
					
					case LED_LEFT:
						
						if((uiLed_Step_Tracker%5) < 3){
							LedStepLeft();
							uiLed_Step_Tracker++;
							break;
						}
						else{
							eLedState = LED_RIGHT;
							break;
						}
					
						
					case LED_RIGHT:
						
					if((uiLed_Step_Tracker%5) >= 3){
						LedStepRight();
						uiLed_Step_Tracker++;
						break;
					}
					else{
						eLedState = LED_LEFT;
					}
						
					Delay(250);
			}	
		}
}