#include "led.h"
#include "timer_interrupts.h"
#include "keyboard.h"
#include "servo.h"
#include "uart.h"
#include "string.h"
#include "command_decoder.h"


int main(void){
	

		char cDestination[12];
		
		UART_InitWithInt(9600);
		DetectorInit();
		ServoInit(50);
	
		while(1) {
			if(eReciever_GetStatus() == READY){
				
				Reciever_GetStringCopy(cDestination);
				DecodeMsg(cDestination);
				
				if((ucTokenNr != 0) && (asToken[0].eType == KEYWORD)){
					switch (asToken[0].uValue.eKeyword) {
				
						case CLB:					
							ServoCallib();
						break;
					
						case GT:
							ServoGoTo(asToken[1].uValue.uiValue);					
						break;
					}
			}			
		}
	}
}