#include <LPC21xx.H>
#define S0_bm 0x00000010

char ReadButton1(void){
	
	if((IO0PIN & S0_bm) == 0){
		return 1;
	}
	else {
		return 0;
	}	
}

	