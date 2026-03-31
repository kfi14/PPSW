#include <LPC21xx.H>
#include "timer.h"

#define Counter_Enable (1<<0)
#define Counter_Reset (1<<1)
#define Interrupt_MR0 (1<<0)
#define Reset_MR0 (1<<1)
#define Stop_MR0 (1<<2)
#define MR0_Interrupt_Flag (1<<0)


void InitTimer0(void){
	T0TCR = Counter_Enable;
}


void WaitOnTimer0(unsigned int uiTime){
	T0TCR = T0TCR | Counter_Reset;
	T0TCR = T0TCR & (~Counter_Reset);
	
	while(T0TC <= uiTime*15){}
}		


void InitTimer0Match0(unsigned int uiDelayTime){
	T0MR0 = uiDelayTime*15;
	T0MCR = (Reset_MR0 | Interrupt_MR0);	
	T0TCR = T0TCR | Counter_Reset;
	T0TCR = T0TCR & (~Counter_Reset);
	T0TCR = T0TCR | Counter_Enable;
}
	

void WaitOnTimer0Match0(void){
	while((T0IR & MR0_Interrupt_Flag) == 0){}
		T0IR = MR0_Interrupt_Flag;
}
	

