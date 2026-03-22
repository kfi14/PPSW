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
    IO1DIR = LED0_bm | LED1_bm | LED2_bm | LED3_bm;

    while(1)
        {
					IO1SET = LED0_bm;
					IO1SET = LED1_bm | LED0_bm;
					IO1SET = LED2_bm | LED1_bm | LED0_bm;
					IO1SET = LED3_bm | LED2_bm | LED1_bm | LED0_bm;
					
					
    }
}