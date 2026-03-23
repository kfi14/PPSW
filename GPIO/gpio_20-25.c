#include <LPC21xx.H>
#include "gpio_13_14_15.h"

#define LED0_bm 0x00010000
#define LED1_bm 0x00020000
#define LED2_bm 0x00040000
#define LED3_bm 0x00080000

unsigned int uiLedTracker = 0;

void StepLeft(void){
	uiLedTracker = (uiLedTracker+1)%4;
	LedOn(uiLedTracker);
}

void StepRight(void){
	uiLedTracker = (uiLedTracker-1)%4;
	LedOn(uiLedTracker);
}

	
	
	