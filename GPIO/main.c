#include "led.h"
#include "keyboard.h"
#include "timer.h"



int main(void){
	
			enum LedState{LED_MOVING_LEFT, LED_MOVING_RIGHT, LED_STOPPED};
			enum LedState eLedState = LED_STOPPED;

			LedInit();
			InitTimer0();

			while(1){
				
				LedStepLeft();
				WaitOnTimer0(250000);
		}
}
