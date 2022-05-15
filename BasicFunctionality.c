#include "tm4c123gh6pm.h"
#include <stdint.h>
#include "DIO.h"

void wait_1sec(){
	NVIC_ST_RELOAD_R = 16000000-1;
	NVIC_ST_CURRENT_R = 0;
	while((NVIC_ST_CTRL_R &	 0x00010000) == 0){};
}

void wait_1ms(){
	NVIC_ST_RELOAD_R = 16000-1;
	NVIC_ST_CURRENT_R = 0;
	while((NVIC_ST_CTRL_R &	 0x00010000) == 0){};
}

//Wait multiples of 1 second
void wait_secs(uint32_t secs){
	uint32_t i;
	for(i=0; i<secs; i++) {
		wait_1sec();
	}
}

//Wait multiples of 1 millisecond
void wait_ms(uint32_t ms){
	uint32_t i;
	for(i=0; i<ms; i++) {
		wait_1ms();
	}
}