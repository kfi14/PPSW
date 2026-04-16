#include <LPC21xx.H>
#include "servo.h"

#define DETECTOR_BM (1<<10)


void DetectorInit(void){
	IO0DIR = DETECTOR_BM;
}

enum DetectorState eReadDetector(void){
	
	if((IO0PIN & DETECTOR_BM) == 0){
		return ACTIVE;
	}
	else{
		return INACTIVE;
	}
}