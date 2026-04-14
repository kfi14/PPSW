#include "led.h"
#include "timer_interrupts.h"
#include "keyboard.h"

int main (void) {
    unsigned int iMainLoopCtr = 0;
    
    LedInit();

    Timer0InterruptsInit(250000,&LedStepLeft);

    while(1) {
        iMainLoopCtr++;
    }
}
