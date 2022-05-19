#include "tm4c123gh6pm.h"
#include <stdint.h>
#include "DIO.h"
#include "keypad.h"
// input -> c4, c5, c6, c7
//output -> d0, d1, d2, d3


void keypad_intial(void){
	//init. the input for the keypad
	port_vInit('C');
	DIO_vSetPinDir('C', 4, 0);
	DIO_vSetPinDir('C', 5, 0);
	DIO_vSetPinDir('C', 6, 0);
	DIO_vSetPinDir('C', 7, 0);
  DIO_vEnablePullUp('C',0x4);
	DIO_vEnablePullUp('C',0x5);
	DIO_vEnablePullUp('C',0x6);
	DIO_vEnablePullUp('C',0x7);
	
	//init the output for the keypad
	port_vInit('D');
	DIO_vSetPinDir('D', 0, 1);
	DIO_vSetPinDir('D', 1, 1);
	DIO_vSetPinDir('D', 2, 1);
	DIO_vSetPinDir('D', 3, 1);
}


unsigned char keypad_read(){
	unsigned char k [4][4]={{'1','2','3','A'},{'4','5','6','B'},{'7','8','9','c'},{'*','0','#','D'}};
	char row, col, x;
	char Returnvalue = 0xFF;
	for(row=0; row<4; row++){
		DIO_vWriteLowLevel('D', 0xFF); //Set output pins
		DIO_vWritePin('c', row, 0);
		for(col=0;col<4;col++){
			x = DIO_u8ReadPin('D', col);
			if(x==0){ 
				Returnvalue = k[row][col];
			  break;
			}
		}
		return Returnvalue;
	}
}
