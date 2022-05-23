#include "tm4c123gh6pm.h"
#include <stdint.h>
#include "DIO.h"
#include "Switch.h"
#include "BITCTRL.h"


/**
	                   -> SW1 function <-							
SW1 pressed for the first time  --> the oven pauses(keep remaining time on disply)
SW1 pressed for the sec time    --> time cleared and time stops
	                   
	                   -> SW2 function <-								
SW2 pressed --> the oven starts operation
sw2 pressed after pause and door is closed -> resume operation

					-> SW3 function <-
switch down -> open-door
switch up -> closed-door
Opning the door must keep time on disply
**/



void SW1_interrupt(){
	
	switch_vint_pullup('F', 4);
	GPIO_PORTF_IS_R |= 0x10;
	//GPIO_PORTF_IBE_R &=~ 0x10;
	GPIO_PORTF_IEV_R &= ~0x10;
	//here pinNumber needed.
	GPIO_PORTF_ICR_R = 0x10; //clear flag4
	GPIO_PORTF_IM_R |= 0x10;// arm interrupt on PF4
	//----------------------------------------------
	NVIC_PRI7_R = (NVIC_PRI7_R&0xFF00FFFF)|0x00A00000; // priority 5
	NVIC_EN0_R = 0x40000000; // enable interrupt 30 in NVIC
	__enable_irq(); // Enable global Interrupt flag (I)
}


void SW2_interrupt(){
	
	
	switch_vint_pullup('F', 0);
	GPIO_PORTF_IS_R |= 0x10;
	//GPIO_PORTF_IBE_R &=~ 0x10;
	GPIO_PORTF_IEV_R &= ~0x10;
	//here pinNumber needed.
	GPIO_PORTF_ICR_R = 0x01; //clear flag4
	GPIO_PORTF_IM_R |= 0x01;// arm interrupt on PF4
	//----------------------------------------------
	NVIC_PRI7_R = (NVIC_PRI7_R&0xFF00FFFF)|0x00A00000; // priority 5
	NVIC_EN0_R = 0x40000000; // enable interrupt 30 in NVIC
	__enable_irq(); // Enable global Interrupt flag (I)
}

void SW3_interrupt(){
	
	switch_vint_pullup('D', 7);
	GPIO_PORTF_IS_R |= 0x10;
	//GPIO_PORTF_IBE_R &=~ 0x10;
	GPIO_PORTF_IEV_R &= ~0x10;
	//here pinNumber needed.
	GPIO_PORTF_ICR_R = 0x80; //clear flag4
	GPIO_PORTF_IM_R |= 0x80;// arm interrupt on PF4
	//----------------------------------------------
	NVIC_PRI0_R = (NVIC_PRI0_R&0x00FFFFFF)|0x00000000; // priority 5
	NVIC_EN0_R = 0x000000004; // enable interrupt 30 in NVIC
	__enable_irq(); // Enable global Interrupt flag (I)
}
