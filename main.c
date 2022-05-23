#include "tm4c123gh6pm.h"
#include <stdint.h>
#include "DIO.h"
#include "keypad.h"
#include "Timer.h"
#include "Switch.h"
#include "LED.h"
#include "LCD.h"
#include "interrupt.h"

#define S1Port 'F'
#define S1Pin 1

#define S2Port 'F'
#define S2Pin 4

#define S3Port 'A'
#define S3Pin 7


void popcorn (void);
void Beef(void);
void chicken(void);
void door_check(void);

int main(void){
	while(1){
		
	}
}


/**
	                   -> POPCORN function <-
� If A is pushed on the keypad (for popcorn), the LCD should show �Popcorn� and then 
cook for 1 minute while the remaining cook time counts down (in seconds) on the LCD, 
then clear the LCD after cooking completes.

**/
void popcorn(void)
{
	LCD_moveCursor(0,1);
	LCD_sendString("Popcorn");
	LCD_clearScreen();

	uint32_t i;
	for (i = 60; i > -1; i--)
	{
		LCD_sendString((char*)i);
		LCD_clearScreen();
		wait_1sec();

	}
		
}
/**
	                   -> Beef_chicken function <-
� If A is pushed on the keypad (for popcorn), the LCD should show �Popcorn� and then 
cook for 1 minute while the remaining cook time counts down (in seconds) on the LCD, 
then clear the LCD after cooking completes.

**/
	void Beef(void){
		LCD_moveCursor(0,1);
		LCD_sendString("number");
		LCD_moveCursor(1,1);
		LCD_sendString("kilos");
		char button = keypad_read('A');
		LCD_clearScreen();
		if (button == '0'){
			LCD_moveCursor(0,1);
			LCD_sendString("Err");
			wait_secs(2);
			LCD_clearScreen();
		}
		else{
			LCD_moveCursor(0,1);
			LCD_sendString("button");
			wait_secs(2);
			LCD_clearScreen();

			char deforset_m = 0.5 * button;
			char deforset_sec = deforset_m * 60;

			for (int i = 1; i < deforset_sec; i++){
				LCD_sendString((char*)i);
				LCD_clearScreen();
				wait_1sec();
			
			}
		}
			
}
	
void chicken(void){
		LCD_moveCursor(0,1);
		LCD_sendString("number");
		LCD_moveCursor(1,1);
		LCD_sendString("kilos");
		char button = keypad_read('A');
		LCD_clearScreen();
		
		if (button == '0'){
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

			char deforset_m = 0.2 * button;
			char deforset_sec = deforset_m * 60;

			for (int i = 1; i < deforset_sec; i++) {
				LCD_sendString((char*)i);
				LCD_clearScreen();
				wait_1sec();
			
			}
		}
			
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
void cooking_time(void) {
	LCD_vInit();
	unsigned char button;
	unsigned char button_in;

	button = keypad_read('E');
  if (button == 'D'){
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
	                   -> SW1 function <-							
SW1 pressed for the first time  --> the oven pauses(keep remaining time on disply)
SW1 pressed for the sec time    --> time cleared and time stops
	                   
	                   -> SW2 function <-								
SW2 pressed --> the oven starts operation
sw2 pressed after pause and door is closed -> resume operation


	                   -> Leds function <-	
microwve running -> leds on
microwve stops -> leds stops
microwave paused -> leds blink
last 3 secs -> leds flash 3 times and buzzer go "we we"
**/

/**
					-> door_check function <-
switch down -> open-door
switch up -> closed-door
Opning the door must keep time on disply
**/
void door(void){

}
