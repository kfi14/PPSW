#include <LPC21xx.H>

#define S0_bm 0x00000010
#define S1_bm 0x00000040
#define S2_bm 0x00000020
#define S3_bm 0x00000080


enum KeyboardState {RELEASED, BUTTON_0, BUTTON_1, BUTTON_2, BUTTON_3};

enum KeyboardState eKeyboardRead(void){
	
	if((IO0PIN & S0_bm) == 0){
		return BUTTON_0;
	}
	else if((IO0PIN & S1_bm) == 0){
		return BUTTON_1;
	}
	
	else if((IO0PIN & S2_bm) == 0){
		return BUTTON_2;
	}
	
	else if((IO0PIN & S3_bm) == 0){
		return BUTTON_3;
	}
	
	else {
		return RELEASED;
	}	
}

	

void KeyboardInit(void){
	IO0DIR = IO0DIR & ~(S0_bm | S1_bm | S2_bm | S3_bm);
}
