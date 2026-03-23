#include <LPC21xx.H>
#define LED0_bm 0x00010000
#define LED1_bm 0x00020000
#define LED2_bm 0x00040000
#define LED3_bm 0x00080000


void LedInit(void){
	
	IO1DIR = LED0_bm | LED1_bm | LED2_bm | LED3_bm;
	IO1CLR = LED0_bm | LED1_bm | LED2_bm | LED3_bm;
	IO1SET = LED0_bm;
}