#include "tm4c123gh6pm.h"
#include <stdint.h>
#include "DIO.h"
#include "keypad.h"
#include "Timer.h"

// input -> E0, E1, E2, E3
//output -> D0, D1, D2, D3


void keypad_intial(){
	//init. the input for the keypad
	port_vInit('E');
	DIO_vSetPortDir('E', 0x20);
	DIO_vSetPinDir('E', 0, 0);
	DIO_vSetPinDir('E', 1, 0);
	DIO_vSetPinDir('E', 2, 0);
	DIO_vSetPinDir('E', 3, 0);
	DIO_vEnablePullUp('E',0);
	DIO_vEnablePullUp('E',1);
	DIO_vEnablePullUp('E',2);
	DIO_vEnablePullUp('E',3);
	
	//init the output for the keypad
	port_vInit('C');
	DIO_vSetPinDir('C', 4, 1);
	DIO_vSetPinDir('C', 5, 1);
	DIO_vSetPinDir('C', 6, 1);
	DIO_vSetPinDir('C', 7, 1);
}


unsigned char keypad_read(){
	unsigned char k [4][4]={{'1','2','3','A'},{'4','5','6','B'},{'7','8','9','c'},{'*','0','#','D'}};
	char row, col, x;
	char Returnvalue = 0xFF;
	for(row=0; row<4; row++){
		DIO_vWriteHighLevel('C', 0xF); //set the output pins (default values)
		DIO_vWritePin('C', row, 0); //write to the input
		for(col=0;col<4;col++){
			x = DIO_u8ReadPin('E', col+4);
			if(x==0){ 
				Returnvalue = k[row][col];
				break;
			}
		}
		if(x==0){
				break;
		}
	}
	
	return Returnvalue;
}
