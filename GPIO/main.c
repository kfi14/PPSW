#include "led.h"
#include "timer_interrupts.h"
#include "keyboard.h"
#include "servo.h"
#include "uart.h"
#include "string.h"
#include "command_decoder.h"
#include <LPC21xx.H>



int main() {
  char cTransmitString[20];
	unsigned int uiTransmitCounter = 0;

	UART_InitWithInt(9600);
	
	while(1) {
			if(Transmiter_GetStatus() == FREE) {
			
			CopyString("licznik ",cTransmitString);
			
			AppendUIntToString(uiTransmitCounter,cTransmitString);
			
			Transmiter_SendString(cTransmitString);
			uiTransmitCounter++;
		}
	}
}