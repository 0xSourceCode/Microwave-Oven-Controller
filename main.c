#include "tm4c123gh6pm.h"
#include <stdint.h>
#include "DIO.h"
#include "keypad.h"
#include "Timer.h"
#include "Switch.h"
#include "LED.h"
#include "LCD.h"


int main(void){
	
}
/**
	                   -> cooking_time function <-
If D is pushed on the keypad, the words “Cooking Time?” should appear on the LCD. 
After that the user can enter a value between 1 and 30 to indicate the cooking time 
required in minutes and seconds. This value is displayed on the LCD as it is entered, right 
to left. 
For example, pressing 1 displays 00:01, then pressing 2 displays 00:12, then pressing 4 
displays 01:24, then pressing 5 displays 12:45. Press push button SW1 to clear the LCD 
display and press SW2 to start cooking and counting down (in seconds) the cooking time 
on the LCD

**/
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

/**
	                   -> SW3 function <-
 Switch SW3 (external push button), position 1, will simulate the microwave oven door 
latch, where the switch being down would be simulating the open-door situation and the 
switch being up would be simulating the door closed situation. Only when the latch is 
closed should the oven be able to be started.
o When SW2 is pressed, the oven starts operation.
o When SW1 (external push button) is pressed for first time, the oven operation 
pauses (keeping remaining time on the display).
o When SW1 is pushed for second time after pressing it for first time, the time is 
cleared and the cooking stops.
o If SW2 is pushed after the oven is paused and the door is closed, then cooking 
must resume from the time it was paused.
• If it is cooking, opening the door should pause the cooking and keep the remaining time 
on display.
• When the microwave is running, the array of LEDs should be on. When it is stopped, 
they should go off. If paused, the array of LEDs should blink (wait time on and wait time 
off) till the cooking is resumed or stopped.
When the microwave completes its function and timer has counted down to zero (regular 
timed cooking or defrosting), the array of LEDs should flash 3 times (wait time on and 
wait time off), and the buzzer should produce an audible tone/alarm during these 3 
second times periods.
**/
void SW3(void){
unsigned char button;
	 switch_vint_pullup('A',2);
	button = switch_vRead('A',2);
}

/**
	                   -> POPCORN function <-
� If A is pushed on the keypad (for popcorn), the LCD should show �Popcorn� and then 
cook for 1 minute while the remaining cook time counts down (in seconds) on the LCD, 
then clear the LCD after cooking completes.

**/
void popcorn(void)
{
  LCD_vInit();
	char button = keypad_read('E');
		if (button == 'A')
		{
			LCD_moveCursor(0,1);
			LCD_sendString("Popcorn");
			LCD_clearScreen();

			uint32_t i;
			for (i = 1; i < 61; i++) {
				LCD_sendString((char*)i);
				LCD_clearScreen();
				wait_1sec();

			}
		}
}
/**
	                   -> Beef_chicken function <-
� If A is pushed on the keypad (for popcorn), the LCD should show �Popcorn� and then 
cook for 1 minute while the remaining cook time counts down (in seconds) on the LCD, 
then clear the LCD after cooking completes.

**/
	void Beef_chicken(void)
	{
		LCD_vInit();
		char button = keypad_read('E');
		
		if (button == 'B'){
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
