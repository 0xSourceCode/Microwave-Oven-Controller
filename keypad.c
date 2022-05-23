#include "tm4c123gh6pm.h"
#include <stdint.h>
#include "DIO.h"
#include "keypad.h"
#include "Timer.h"
//Output  -> E0(ROW 0), E1(ROW 1), E2(ROW 2), E3(ROW 3)
//Input -> A2(COL 0), A3(COL 1), A4(COL 2), A5(COL 3)


void keypad_intial(){
	//init. the input
	port_vInit('A');
	DIO_vSetPortDir('A', 0x3C); //0011 1100
	DIO_vSetPinDir('A', 2, 0);
	DIO_vSetPinDir('A', 3, 0);
	DIO_vSetPinDir('A', 4, 0);
	DIO_vSetPinDir('A', 5, 0);

	GPIO_PORTA_PUR_R = 0x3C;
	
	//init the output
	port_vInit('E');
	DIO_vSetPinDir('E', 0, 1);
	DIO_vSetPinDir('E', 1, 1);
	DIO_vSetPinDir('E', 2, 1);
	DIO_vSetPinDir('E', 3, 1);
}


unsigned char keypad_read(){
	
	unsigned char k [4][4]={{'1','2','3','A'},{'4','5','6','B'},{'7','8','9','C'},{'*','0','#','D'}};
	char row, col, x;
	char Returnvalue = 0xFF;
	
	for(row=0; row<4; row++){
		
		DIO_vWritePort('E', 0x0F); //Set default value 0000 1111
		GPIO_PORTE_DATA_R &= ~(1<<row);
		
		for(col=0;col<4;col++){
			DIO_vWritePort('A', 0x3C); //set input pins (default values)
			x = DIO_u8ReadPin('A', col+2);
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
