#include "stdint.h"
#include "tm4c123gh6pm.h"
#include "BITCTRL.h"
#include "DIO.h"
#include "Timer.h"
#include "keypad.h"
#include "Switch.h"
#include "LED.h"
#include "LCD.h"


void SystemInit(void);

unsigned char button_in;

void popcorn()
	{
		 button_in = keypad_read('A');
		if (button_in == 'A')
			{
				LCD_vInit();
				 wait_secs(60);
				LCD_clearScreen();
		}
	
}
