<<<<<<< HEAD
#include "tm4c123gh6pm.h"
#include <stdint.h>
#include "DIO.h"
#include "keybad.h"


void popcorn(void)
{
	char button = keypad_read('B')
		if (button == 'A')
		{
			LCD_moveCursor(char 0, char 1);
			LCD_sendString(char 'Popcorn');
			LCD_clearScreen(void);
			uint32_t i;
			for (i = 1; i < 61; i++) {
				LCD_sendString(char i)
					LCD_clearScreen(void);
				wait_1sec();

			}
		}
=======
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
>>>>>>> 25347904c7cd38745cbf16691cff0f9bc979e61a
