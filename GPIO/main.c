#include <LPC21xx.H>


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
    IO1DIR = 0x00010000;

    while(1)
        {
        IO1SET = 0x00010000;
        Delay(1000);
        IO1CLR = 0x00010000;
        Delay(1000);
    }
}