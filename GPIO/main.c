#include "led.h"
#include "timer_interrupts.h"
#include "keyboard.h"
#include "servo.h"
#include "uart.h"


int main(void){
	
		unsigned int uiLoopCounter;
		
    UART_InitWithInt(38400);
	
    while(1) {
  		uiLoopCounter++;	
    }
}
