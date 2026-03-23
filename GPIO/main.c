#include <LPC21xx.H>
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
						Delay(250);
						IO1CLR = LED0_bm;
						
						IO1SET = LED1_bm;
						Delay(250);
						IO1CLR = LED1_bm;
						
						IO1SET = LED2_bm;
						Delay(250);
						IO1CLR = LED2_bm;
						
						IO1SET = LED3_bm;
						Delay(250);
					}						
}
