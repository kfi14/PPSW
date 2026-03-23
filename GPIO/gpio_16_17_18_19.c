#include <LPC21xx.H>

#define S0_bm 0x00000010
#define S1_bm 0x0000000040
#define S2_bm 0x0000000020
#define S3_bm 0x0000000080


enum ButtonState {RELEASED, PRESSED};

enum ButtonState ReadButton1(void){
	
	if((IO0PIN & S0_bm) == 0){
		return PRESSED;
	}
	else {
		return RELEASED;
	}	
}

	

void KeyboardInit(void){
	IO0DIR = IO0DIR & ~(S0_bm | S1_bm | S2_bm | S3_bm);
}
