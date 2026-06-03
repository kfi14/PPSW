#include "led.h"
#include "timer_interrupts.h"
#include "keyboard.h"
#include "servo.h"
#include "uart.h"
#include "string.h"
#include "command_decoder.h"
#include <LPC21xx.H>



int main() {
  char cTransmitString[30];
	char cDestination[30];

	UART_InitWithInt(9600);
	Timer0InterruptsInit(500000,&WatchUpdate);
	
	while(1) {
			if(Transmiter_GetStatus() == FREE) {
				
				if(sWatch.fSecondsValueChanged == 1){
			
					CopyString("sec ",cTransmitString);
					AppendUIntToString(sWatch.ucSeconds,cTransmitString);	
					
					Transmiter_SendString(cTransmitString);
					
					sWatch.fSecondsValueChanged = 0;
				}
				
				if(sWatch.fMinutesValueChanged == 1){
					
					CopyString("sec ",cTransmitString);
					AppendUIntToString(sWatch.ucSeconds,cTransmitString);				
					AppendString(" min ",cTransmitString);			
					AppendUIntToString(sWatch.ucMinutes,cTransmitString);
					
					Transmiter_SendString(cTransmitString);
					cTransmitString[0] = 0;
					sWatch.fMinutesValueChanged = 0;
				}
				
				if(eReciever_GetStatus() == READY){
					
					Reciever_GetStringCopy(cDestination);
					DecodeMsg(cDestination);
					
					if(asToken[0].uValue.eKeyword == CAL){
						if(asToken[1].eType == NUMBER) {
							CopyString("calc ",cTransmitString);
							AppendUIntToString(asToken[1].uValue.uiValue*2,cTransmitString);	
							Transmiter_SendString(cTransmitString);
						}
					}
				}		
		}
	}
}