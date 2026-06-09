#include <LPC21xx.H>
#include "adc.h"

//PIN
#define P027_AS_ADC 				0x00400000

//VIC
#define VIC_ADC_CHANNEL 		18
#define mIRQ_SLOT_ENABLE 		0x00000020

//ADC 
#define DONE_MASK 					0x80000000
#define RESULT							0x0000FFC0
#define CLK_DIV 						0x00000300
#define BURST 							0x00010000
#define PDN_OPERATIONAL 		0x00200000



unsigned int uiVoltage;

__irq void ADC_Interrupt(void){
	
	if((ADDR & DONE_MASK) == DONE_MASK){
		uiVoltage = ((ADDR & RESULT) >> 6);
	}
	
	VICVectAddr = 0;
}


void AdcInit (void) {
	
	 PINSEL1 |= P027_AS_ADC;
	
	 ADCR = 0x01 | CLK_DIV | BURST | PDN_OPERATIONAL ;
	
	 VICVectAddr2  = (unsigned long) ADC_Interrupt;        
   VICVectCntl2  = mIRQ_SLOT_ENABLE | VIC_ADC_CHANNEL;
   VICIntEnable |= (0x1 << VIC_ADC_CHANNEL);

}



