#include <LPC21xx.H>
#include "gpio_13_14_15.h"

#define LED0_bm 0x00010000
#define LED1_bm 0x00020000
#define LED2_bm 0x00040000
#define LED3_bm 0x00080000



enum eLedStepDirection {LEFT, RIGHT};

void LedStep(enum eLedStepDirection Direction){
	
	static unsigned int suiLedTracker = 0;
	
	if(Direction == LEFT){
		suiLedTracker = (suiLedTracker+1)%4;
	}
	
	else if(Direction == RIGHT){
		suiLedTracker = (suiLedTracker-1)%4;
	}
	
	else{
		return;
	}
	
	LedOn(suiLedTracker);
}

void LedStepLeft(void){
	LedStep(LEFT);
}

void LedStepRight(void){
	LedStep(RIGHT);
}
		
		
	
	
	
	
	