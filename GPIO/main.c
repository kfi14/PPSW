#include <LPC21xx.H>

#include "gpio_16_17_18_19.h"
#include "gpio_13_14_15.h"
#include "gpio_20-25.h"



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
					unsigned int uiLedStepCounter;
					LedInit();
	
					while(1)
					{
						for (uiLedStepCounter = 0; uiLedStepCounter < 9; uiLedStepCounter++){
							Delay(250);
							LedStep(LEFT);				
						}		
						for (uiLedStepCounter = 0; uiLedStepCounter < 9; uiLedStepCounter++){
							Delay(250);
							LedStep(RIGHT);
						}
					}
}