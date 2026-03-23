#include <LPC21xx.H>
#define S0_bm 0x00000010

enum ButtonState {RELEASED, PRESSED};

enum ButtonState ReadButton1(void){
	
	if((IO0PIN & S0_bm) == 0){
		return PRESSED;
	}
	else {
		return RELEASED;
	}	
}

	