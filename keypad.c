#include "tm4c123gh6pm.h"
#include <stdint.h>
#include "DIO.h"

void keybad_intial(unsigned char portname){
	port_vInit(portname);
	DIO_vSetPortDir(portname,0x0F); //Setting pins 0-3 as output and pins 4-7 as input (0:INPUT, 1:OUTPUT)
  DIO_vEbablePullUp(portname,0x4);
	DIO_vEbablePullUp(portname,0x5);
	DIO_vEbablePullUp(portname,0x6);
	DIO_vEbablePullUp(portname,0x7);
}

unsigned char keypad_read(unsigned char portname){
	unsigned char k [4][4]={{'1','2','3','A'},{'4','5','6','B'},{'7','8','9','c'},{'*','0','#','D'}};
	char row, col, x;
	char Returnvalue = 0xFF;
	for(row=0; row<4; row++){
		DIO_vWriteLowLevel(portname, 0xFF); //Set output pins
		DIO_vWritePin(portname, row, 0);
		for(col=0;col<4;col++){
			x = DIO_u8ReadPin(portname, col+4);
			if(x==0){ 
				Returnvalue = k[row][col];
			  break;
			}
		}
		return Returnvalue;
	}
}
