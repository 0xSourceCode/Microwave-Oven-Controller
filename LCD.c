#include <stdint.h>
#include "DIO.h"
#include "Timer.h"
#include "tm4c123gh6pm.h"
#include "LED.h"
#include "LCD.h"
void LCD_cmd(char cmd);

void LCD_vInit(void){
	port_vInit(DATA_PORT);
	port_vInit(CTRL_PORT);
	DIO_vSetPortDir(DATA_PORT, 0xFF); //set all pins as output
	DIO_vSetPinDir(CTRL_PORT, E, 1); //set Enable pin
	DIO_vSetPinDir(CTRL_PORT, RS, 1); //set Register Select pin
	DIO_vSetPinDir(CTRL_PORT, RW, 1); //set Read/Write pin
	DIO_vWritePin(CTRL_PORT, RW, 0); //set Read/Write pin to write
	LCD_cmd(MODE_8BITS);
	wait_ms(1);
	LCD_cmd(CURSOR_OFF);
	wait_ms(1);
	LCD_cmd(CLEAR_SCREEN);
	wait_ms(10);
	LCD_cmd(ENTRY_MODE);
}

static void sendPulse(void){
	DIO_vWritePin(CTRL_PORT, E, 1);
	wait_ms(2);
	DIO_vWritePin(CTRL_PORT, E, 0);
	wait_ms(2);
}

void LCD_cmd(char cmd){
	DIO_vWritePort(DATA_PORT, cmd);
	DIO_vWritePin(CTRL_PORT, RS, 0);
	sendPulse();
	wait_ms(1);
}

void LCD_sendChar(char chr){
	DIO_vWritePort(DATA_PORT, chr);
	DIO_vWritePin(CTRL_PORT, RS, 1);
	sendPulse();
	wait_ms(1);
}

void LCD_sendString(char *string){
	while((*string) != '\0'){
		LCD_sendChar((*string));
		string++;
	}
}

void LCD_clearScreen(void){
	LCD_cmd(CLEAR_SCREEN);
	wait_ms(10);
}

void LCD_moveCursor(char row, char col){
	char pos = 0;
	if(row == 1){
		pos = (0x80)+col-1;			
	}
	else if(row == 2) {
		pos = (0xC0)+col-1;
	}
	else {
		pos = 0x80;
	}
	LCD_cmd(pos);
	wait_ms(1);
}
