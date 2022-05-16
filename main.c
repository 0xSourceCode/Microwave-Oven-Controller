#include "tm4c123gh6pm.h"
#include <stdint.h>
#include "DIO.h"
#include "keypad.h"
#include "Timer.h"
#include "Switch.h"
#include "LED.h"
#include "LCD.h"

#define KeypadPort 'E' 


int main(void){
	
}
/**
	                   -> SW3 function <-


**/
void SW3(void){
unsigned char button;
	 switch_vint_pullup('A',2);
	button = switch_vRead('A',2);
}

/**
	                   -> POPCORN function <-
• If A is pushed on the keypad (for popcorn), the LCD should show “Popcorn” and then 
cook for 1 minute while the remaining cook time counts down (in seconds) on the LCD, 
then clear the LCD after cooking completes.

**/
void popcorn(void)
{
	char button = keypad_read(KeypadPort);
		if (button == 'A')
		{
			LCD_moveCursor(0,1);
			LCD_sendString("Popcorn");
			LCD_clearScreen();
			uint32_t i;
			for (i = 1; i < 61; i++) {
				//char string[2];
				//sprintf(string, "%d", i);
				LCD_sendString((char*)i);
				LCD_clearScreen();
				wait_1sec();

			}
		}
}
/**
	                   -> Beef_chicken function <-
• If A is pushed on the keypad (for popcorn), the LCD should show “Popcorn” and then 
cook for 1 minute while the remaining cook time counts down (in seconds) on the LCD, 
then clear the LCD after cooking completes.

**/
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
						LCD_sendString((char*)i);
						LCD_clearScreen();
						wait_1sec();
					
					}
				}
			}
		}
