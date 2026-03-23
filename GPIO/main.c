#include <LPC21xx.H>

#include "gpio_16_17_18_19.h"
#include "gpio_13_14_15.h"



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
						switch(ReadButton1()){							
							case PRESSED:
								LedOn(1);
							break;
							
							case RELEASED:
								LedOn(0);
							break;
						}
							
							
					}						
}
