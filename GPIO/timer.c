#include <LPC21xx.H>
#include "timer.h"

#define Counter_Enable (1<<0)
#define Counter_Reset (1<<1)


void InitTimer0(void){
	T0TCR = Counter_Enable;
}

void WaitOnTimer0(unsigned int uiTime){
	T0TCR = T0TCR | Counter_Reset;
	T0TCR = T0TCR & (~Counter_Reset);
	
	while(T0TC <= uiTime*15){}
}		
	
	