#include <LPC21xx.H>
#include "servo.h"
#include "led.h"
#include "timer_interrupts.h"

#define DETECTOR_BM (1<<10)


void DetectorInit(void){
	IO0DIR = (IO0DIR & ~(DETECTOR_BM));
}

enum DetectorState eReadDetector(void){
	
	if((IO0PIN & DETECTOR_BM) == 0){
		return ACTIVE;
	}
	else{
		return INACTIVE;
	}
}

enum ServoState {CALLIB, IDLE, IN_PROGRESS};

struct Servo{
	enum ServoState eState;
	unsigned int uiCurrentPosition;
	unsigned int uiDesiredPosition;
}; 
struct Servo sServo;

void AutomatServo(void){
	
	switch(sServo.eState){
	
		case CALLIB:
		
			if(eReadDetector() == ACTIVE){
				sServo.uiCurrentPosition = 0;
				sServo.uiDesiredPosition = 0;
				sServo.eState = IDLE;
			}
			else{
				LedStepLeft();
				sServo.eState = CALLIB;
			}
		
		break;
		
		case IDLE:
		
			if(sServo.uiCurrentPosition == sServo.uiDesiredPosition){
				sServo.eState = IDLE;
			}
			else{
				sServo.eState = IN_PROGRESS;
			}
		
		break;
		
		case IN_PROGRESS:
		
			if(sServo.uiCurrentPosition < sServo.uiDesiredPosition){
				LedStepRight();
				sServo.uiCurrentPosition++;
				sServo.eState = IN_PROGRESS;
			}
			else if(sServo.uiCurrentPosition > sServo.uiDesiredPosition){
				LedStepLeft();
				sServo.uiCurrentPosition--;
				sServo.eState = IN_PROGRESS;
			}
			else{
				sServo.eState = IDLE;
			}
		
		break;

	}
}
		
void ServoInit(unsigned int uiServoFrequency){
	sServo.eState = CALLIB;
	LedInit();
	Timer0InterruptsInit((1000000/uiServoFrequency),&AutomatServo);
}

void ServoCallib(void){
	sServo.eState = CALLIB;
}

void ServoGoTo(unsigned int uiPosition){
	sServo.uiDesiredPosition = uiPosition;
}
		