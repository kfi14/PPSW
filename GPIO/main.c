#include "led.h"
#include "timer_interrupts.h"
#include "keyboard.h"
#include "servo.h"
#include "uart.h"


int main(void){
	
		extern char cOdebranyZnak;
		unsigned int uiLoopCounter;
	
    UART_InitWithInt(9600);
		KeyboardInit();
		ServoInit(50);
	
    while(1) {
			
			if(eKeyboardRead() == BUTTON_0){
					ServoCallib();
				}
				else if(eKeyboardRead() == BUTTON_1){
					ServoGoTo(12);
				}
				else if(eKeyboardRead() == BUTTON_2){
					ServoGoTo(24);
				}
				else if(eKeyboardRead() == BUTTON_3){
					ServoGoTo(36);
				}
				
  		switch(cOdebranyZnak){
				
				case '1':
					ServoGoTo(12);
					cOdebranyZnak = 0;
				break;
				
				case '2':
					ServoGoTo(24);
					cOdebranyZnak = 0;
				break;
				
				case '3':
					ServoGoTo(36);
					cOdebranyZnak = 0;
				break;
				
				case 'c':
					ServoCallib();
					cOdebranyZnak = 0;
				break;
				
				default:
				break;
					
			}
			uiLoopCounter++;
			
    }
}
