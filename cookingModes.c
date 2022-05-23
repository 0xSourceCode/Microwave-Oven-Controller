#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <math.h>
#include "DIO.h"
#include "Timer.h"
#include "tm4c123gh6pm.h"
#include "LED.h"
#include "LCD.h"
#include "cookingModes.h"
#include "keypad.h"

static int isAllowed(unsigned char c);
static int isAllowed1(unsigned char c);

void Popcorn(void){
	int i;
	char buffer[10];
	LCD_sendString("Popcorn");
	wait_secs(2);
	LCD_clearScreen();
	
	//Set LED ON
	for(i = 60; i > -1; i--){
		tostring(buffer, i);
		LCD_sendString(buffer);
		wait_secs(1);
		wait_ms(40);
		LCD_clearScreen();
	}
	//Set LED OFF
	//Set Buzzer
}

void Beef(void){
	
	int i;
	char buffer[10];
	char str[1];
	int weight;
	int deforset_sec;
	char button;
	
	LCD_sendString("Beef weight?");
	wait_secs(2);
	LCD_clearScreen();
	
	while(1){
		if(isAllowed(keypad_read()) == 1 && keypad_read() != 0xFF){
			button = keypad_read();
			LCD_sendChar(keypad_read());
			wait_secs(2);
			LCD_clearScreen();
			weight = button - '0';
			deforset_sec = weight * 30;
			
			for(i = deforset_sec; i > -1; i--){
				tostring(buffer, i);
				LCD_sendString(buffer);
				wait_secs(1);
				wait_ms(40);
				LCD_clearScreen();
			}
			break;
		}
		else if(isAllowed(keypad_read()) == 0 && keypad_read() != 0xFF){
			LCD_sendString("Error");
			wait_secs(2);
			LCD_clearScreen();
			LCD_sendString("Beef weight?");
			wait_secs(2);
			LCD_clearScreen();
		}
		else {
			continue;
		}
	}
}

void Chicken(void){
	
	int i;
	char buffer[10];
	char str[1];
	int weight;
	int deforset_sec;
	char button;
	
	
	LCD_moveCursor(0,1);
	LCD_sendString("Chicken weight?");
	wait_secs(2);
	LCD_clearScreen();
	
	while(1){
		if (isAllowed(keypad_read()) == 1 && keypad_read() != 0xFF){
			button = keypad_read();
			LCD_sendChar(keypad_read());
			wait_secs(2);
			LCD_clearScreen();
			weight = button - '0';
			deforset_sec = weight * 12;
			
			for(i = deforset_sec; i > -1; i--){
				tostring(buffer, i);
				LCD_sendString(buffer);
				wait_secs(1);
				wait_ms(40);
				LCD_clearScreen();
			}
			break;
		}
		else if(isAllowed(keypad_read()) == 0 && keypad_read() != 0xFF){
			LCD_sendString("Error");
			wait_secs(2);
			LCD_clearScreen();
			LCD_sendString("Chicken weight?");
			wait_secs(2);
			LCD_clearScreen();
		}
		else {
			continue;
		}
	}
}
void CookingTime(void){
	
	const int STATIC_CURSOR = 5;
	int DYNAMIC_CURSOR = 5;
	char input;
	char inputArray[5];
	int counter = 0;
	int totalTime = 0;
	int i;
	char buffer[10];
	
	LCD_moveCursor(0,1);
	LCD_sendString("Cooking time?");
	wait_secs(2);
	LCD_clearScreen();
	LCD_sendString("00:00");
	
	while(DYNAMIC_CURSOR != 0){
		
		if(DYNAMIC_CURSOR == 3){
			DYNAMIC_CURSOR--;
			continue;
		}
		
		else if(isAllowed1(keypad_read()) == 1 && keypad_read() != 0xFF){
			
			input = keypad_read();
			
			LCD_moveCursor(1, STATIC_CURSOR); //Print entered digit on col 5
			LCD_sendChar(input);
			
			inputArray[counter] = input; //Save input
			
			LCD_moveCursor(1, DYNAMIC_CURSOR); //Print on current col
			if(counter == 0) {
				LCD_sendChar(inputArray[0]); //Print current element
			}
			else if(counter == 1) {
				LCD_moveCursor(1, 4);
				LCD_sendChar(inputArray[0]); //Print previous element
			}
			else if(counter == 2) {
				LCD_moveCursor(1, 2);
				LCD_sendChar(inputArray[0]);
				LCD_moveCursor(1, 4);
				LCD_sendChar(inputArray[1]);
			}
			else if(counter == 3) {
				LCD_moveCursor(1, 1);
				LCD_sendChar(inputArray[0]); //Print previous element
				LCD_moveCursor(1, 2);
				LCD_sendChar(inputArray[1]);
				LCD_moveCursor(1, 4);
				LCD_sendChar(inputArray[2]);
			}	
			
			DYNAMIC_CURSOR--;
			counter++;
			wait_ms(250);
		}
	}
	
	totalTime += (inputArray[3] - '0'); //Seconds
	totalTime += (inputArray[2] - '0') * 10; //Seconds
	totalTime += (inputArray[1] - '0') * 60; //Minutes
	totalTime += (inputArray[0] - '0') * 60 * 10; //Minutes
	
	while(1){
		
		if(DIO_u8ReadPin('F', 0) == 0){
			//If SW2 is pressed
			
			LCD_clearScreen();
			LCD_sendString("Start timer");
			wait_secs(2);
			LCD_clearScreen();
			
			for(i = totalTime; i > -1; i--){
				tostring(buffer, i);
				LCD_sendString(buffer);
				wait_secs(1);
				wait_ms(40);
				LCD_clearScreen();
			}
			break;
		}
		else if(DIO_u8ReadPin('F', 4) == 0){
			//If SW1 is pressed
			LCD_clearScreen();
			LCD_sendString("Exit timer");
			wait_secs(2);
			LCD_clearScreen();
			break;
		}
		else if(totalTime > 1800){
			LCD_clearScreen();
			LCD_sendString("Invalid time!");
			wait_secs(2);
			LCD_clearScreen();
			break;
		}
	}
}

static int isAllowed(unsigned char c){
	int i;
	char st[] = "123456789";
  int check = 0;
  for(i=0; i<9; i++) {
        if(st[i] == c){
            check =1 ;
            break ;
        }
    }
		return check;
}
static int isAllowed1(unsigned char c){
	int i;
	char st[] = "0123456789";
  int check = 0;
  for(i=0; i<10; i++) {
        if(st[i] == c){
            check =1 ;
            break ;
        }
    }
		return check;
}
