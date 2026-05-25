#include "led.h"
#include "timer_interrupts.h"
#include "keyboard.h"
#include "servo.h"
#include "uart.h"


int main(void){
	
		extern char cOdebranyZnak;
		unsigned int uiLoopCounter;
	
    UART_InitWithInt(9600);
		LedInit();
	
    while(1) {
  		switch(cOdebranyZnak){
				
				case '0':
					LedOn(0);
					cOdebranyZnak = 0;
				break;
				
				case '1':
					LedOn(1);
					cOdebranyZnak = 0;
				break;
				
				case '2':
					LedOn(2);
					cOdebranyZnak = 0;
				break;
				
				case '3':
					LedOn(3);
					cOdebranyZnak = 0;
				break;
				
				case 'c':
					LedOn(4);
					cOdebranyZnak = 0;
				break;
				
				default:
				break;
					
			}
			uiLoopCounter++;
			
    }
}
