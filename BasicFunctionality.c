#include "tm4c123gh6pm.h"
#include <stdint.h>
#include "DIO.h"

void wait_1sec(){
	//To be done
}

//Wait multiples of 1 second
void wait(uint16_t seconds){
	uint16_t i;
	for(i=0; i<seconds; i++) {
		wait_1sec();
	}
}
