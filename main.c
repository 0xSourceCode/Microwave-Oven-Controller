<<<<<<< HEAD
#include "tm4c123gh6pm.h"
#include <stdint.h>
#include "DIO.h"
#include "keybad.h"
#include "Timer.h"
#include "Switch.h"
#include "LED.h"
#include "LCD.h"


void popcorn(void)
{
	char button = keypad_read('A')
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
}
	void  Beef, chicken(void)
	{
		char button = keypad_read('A')
			if (button == 'B')
			{
				LCD_moveCursor(char 0, char 1);
				LCD_sendString(char 'number');
				LCD_moveCursor(char 1, char 1);
				LCD_sendString(char 'kilos');
				char button = keypad_read('A')
					LCD_clearScreen(void);
				if (button == '0')
				{
					LCD_moveCursor(char 0, char 1)
						LCD_sendString(char 'Err');
					wait_secs(uint32_t 2);
					LCD_clearScreen(void);
				}
				else {

					LCD_moveCursor(char 0, char 1);
					LCD_sendString(char button);
					wait_secs(uint32_t 2);
					LCD_clearScreen(void);
					char deforset_m = 0.5 * button;
					char deforset_sec = deforset_m * 60;

					for (i = 1; i < deforset_sec; i++) {
						LCD_sendString(char i)
							LCD_clearScreen(void);
						wait_1sec();
					

