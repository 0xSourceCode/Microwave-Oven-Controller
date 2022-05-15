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

