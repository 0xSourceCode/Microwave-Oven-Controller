#include "tm4c123gh6pm.h"
#include <stdint.h>
#include "DIO.h"
#include "keypad.h"
#include "Timer.h"
#include "Switch.h"
#include "LED.h"
#include "LCD.h"

void SW3(void){
unsigned char button;
	 switch_vint_pullup('A',2);
	button = switch_vRead('A',2);
}
void popcorn(void)
{
	char button = keypad_read('E');
		if (button == 'A')
		{
			LCD_moveCursor(0,1);
			LCD_sendString("Popcorn");
			LCD_clearScreen();
			uint32_t i;
			for (i = 1; i < 61; i++) {
				char string[2];
				sprintf(string, "%d", i);
				LCD_sendString(string);
				LCD_clearScreen();
				wait_1sec();

			}
		}
}
	void Beef_chicken(void)
	{
		char button = keypad_read('E');
			if (button == 'B')
			{
				LCD_moveCursor(0,1);
				LCD_sendString("number");
				LCD_moveCursor(1,1);
				LCD_sendString("kilos");
				char button = keypad_read('A');
				LCD_clearScreen();
				if (button == '0')
				{
					LCD_moveCursor(0,1);
					LCD_sendString("Err");
					wait_secs(2);
					LCD_clearScreen();
				}
				else {

					LCD_moveCursor(0,1);
					LCD_sendString("button");
					wait_secs(2);
					LCD_clearScreen();
					char deforset_m = 0.5 * button;
					char deforset_sec = deforset_m * 60;

					for (int i = 1; i < deforset_sec; i++) {
						LCD_sendString(i)
						LCD_clearScreen();
						wait_1sec();
					
					}
				}
			}
		}
