#include "tm4c123gh6pm.h"
#include <stdint.h>
#include "DIO.h"
#include "Switch.h"


void SwInterruptInit(unsigned char portname, unsigned char pin_number){
	switch(portname){
		case 'A':
		case 'a':
			switch_vint_pullup(portname, pin_number);
			break;
		
		case 'B':
		case 'b':
			switch_vint_pullup(portname, pin_number);
			break;
		
		case 'C':
		case 'c':
				switch_vint_pullup(portname, pin_number);
			break;
	
		case 'D':
		case 'd':
				switch_vint_pullup(portname, pin_number);
			break;
		
		case 'E':
		case 'e':
			switch_vint_pullup(portname, pin_number);
			break;
		
		case 'F':
		case 'f':
			switch_vint_pullup(portname, pin_number);
			GPIO_PORTF_IS_R &= ~0x10;
			GPIO_PORTF_IBE_R &=~ 0x10;
			GPIO_PORTF_IEV_R &= ~0x10;
			GPIO_PORTF_ICR_R = 0x10; //clear flag4
			GPIO_PORTF_IM_R |= 0x10;// arm interrupt on PF4
			NVIC_PRI7_R = (NVIC_PRI7_R&0xFF00FFFF)|0x00A00000; // priority 5
			NVIC_EN0_R = 0x40000000; // enable interrupt 30 in NVIC
			EnableInterrupts(); // Enable global Interrupt flag (I)
			break;
		}
}


void GPIOF_Handler(void){
	while(1){}
}