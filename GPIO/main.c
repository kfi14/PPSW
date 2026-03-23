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


int main()
{
					LedInit();
					KeyboardInit();
	
					while(1)
					{
						switch(eKeyboardRead()){
						
						case BUTTON_1:
							LedStepRight();
						break;
						
						case BUTTON_2:
							LedStepLeft();
						break;
						
						default:
						break;
						}					
					}
}