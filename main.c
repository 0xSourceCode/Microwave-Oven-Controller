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

	port_vInit('F'); //Initialize SW1
	DIO_vSetPortDir('F', 0x0E);
	GPIO_PORTF_PUR_R = 0x11;

	port_vInit('D'); //Initialize Buzzer and LED port
	DIO_vSetPinDir('D', 3, 1); //PD7 for Buzzer
	DIO_vSetPinDir('D', 6, 1); //PD6 for external LED

	checkDoor:
		while(DIO_u8ReadPin(S3prot, S3pin) == 0){}
		goto doorIsClosed;


	while(1){
		if(DIO_u8ReadPin(S3prot, S3pin) == 0){
			goto checkDoor;
		}
		doorIsClosed:
			if(keypad_read() != 0xFF) {
				button = keypad_read();

				switch(button){
					case 'A':
						Popcorn();
						break;
					case 'B':
						Beef();
						break;
					case 'C':
						Chicken();
						break;
					case 'D':
						CookingTime();
						break;
				}
			}
		}
}

void SystemInit(){
	main();
}
