<<<<<<< HEAD
#include "tm4c123gh6pm.h"
#include <stdint.h>
#include "DIO.h"
#include "keybad.h"
#include "Timer.h"
#include "Switch.h"
#include "LED.h"
#include "LCD.h"

void SW3(void){
unsigned char button;
	 switch_vint_pullup('A',2);
	button = switch_vRead('A',2);
}

void cooking_time(void) //not completed 
	{
		LCD_vInit();
		unsigned char button;
		unsigned char button_in;
		
		 button = keypad_read('E');
		if (button == 'D')
			{
				LCD_moveCursor(1,1);
				LCD_sendString("Cooking Time?");
				LCD_clearScreen();
				
				} 
				switch_vint_pullup('f',1);
				switch_vint_pullup('f',5);
				
				button_in = switch_vRead('f',1);
				if (button_in == 0x01){
					LCD_clearScreen();
				}
				button_in = switch_vRead('f',5);
				if(button_in == 0x10){
				
				}
		}
	
}
void popcorn(void)
{
	LCD_vInit();
	char button = keypad_read('E')
		if (button == 'A')
		{
			LCD_moveCursor(char 1, char 1);
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
		LCD_vInit();
		char button = keypad_read('E')
			if (button == 'B')
			{
				LCD_moveCursor(char 1, char 1);
				LCD_sendString(char 'number');
				LCD_moveCursor(char 2, char 1);
				LCD_sendString(char 'kilos');
				char button = keypad_read('A')
					LCD_clearScreen(void);
				if (button == '0')
				{
					LCD_moveCursor(char 1, char 1)
						LCD_sendString(char 'Err');
					wait_secs(uint32_t 2);
					LCD_clearScreen(void);
				}
				else {

					LCD_moveCursor(char 1, char 1);
					LCD_sendString(char button);
					wait_secs(uint32_t 2);
					LCD_clearScreen(void);
					char deforset_m = 0.5 * button;
					char deforset_sec = deforset_m * 60;

					for (i = 1; i < deforset_sec; i++) {
						LCD_sendString(char i)
							LCD_clearScreen(void);
						wait_1sec();
					

