#include "led.h"
#include "timer_interrupts.h"
#include "keyboard.h"
#include "servo.h"
#include "uart.h"
#include "string.h"
#include "command_decoder.h"
#include <LPC21xx.H>

extern char cWyslanyZnak;

int main() {
	unsigned int uiLoopCtr;
	UART_InitWithInt(9600);
	U0THR = cWyslanyZnak;
	while(1) {
		uiLoopCtr++;
	}
}