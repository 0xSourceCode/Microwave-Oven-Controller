#include "tm4c123gh6pm.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <math.h>
#include "DIO.h"
#include "keypad.h"
#include "Timer.h"
#include "Switch.h"
#include "LED.h"
#include "LCD.h"
#include "cookingModes.h"

int main(){
	char button;
	timerInit();
	LCD_vInit();
	keypad_intial();
	port_vInit('F');
	DIO_vSetPortDir('F', 0x0E);
	GPIO_PORTF_PUR_R = 0x11;
	
	while(1){
		if(keypad_read() != 0xFF) {
			button = keypad_read();
			
			switch(button){
				case 'A':
					Popcorn();
				case 'B':
					Beef();
				case 'C':
					Chicken();
				case 'D':
					CookingTime();
			}
		}
	
	}
	
	
}

void SystemInit(){
	main();
}