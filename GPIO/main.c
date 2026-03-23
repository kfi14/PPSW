#include <LPC21xx.H>

#include "gpio_16_17_18_19.h"
#include "gpio_13_14_15.h"

#define LED0_bm 0x00010000
#define LED1_bm 0x00020000
#define LED2_bm 0x00040000
#define LED3_bm 0x00080000



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
