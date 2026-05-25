#include "led.h"
#include "timer_interrupts.h"
#include "keyboard.h"
#include "servo.h"
#include "uart.h"


int main(void){
	
		char Str1[] = "callib";
		char Str2[] = "left";
		char Str3[] = "right";
		char cDestination[10];
	
		UART_InitWithInt(9600);
		ServoInit(50);
    
		while(1) {
			if(eReciever_GetStatus() == READY){
				
				Reciever_GetStringCopy(cDestination);
				
				if(eCompareString(cDestination, Str1) == EQUAL){
					ServoCallib();
				}
				else if(eCompareString(cDestination, Str2) == EQUAL){
					ServoGoTo(12);	
				}
				else if(eCompareString(cDestination, Str3) == EQUAL){
					ServoGoTo(36);
				}			
			}
	}
}
