#include "tm4c123gh6pm.h"
#include <stdint.h>
#include "DIO.h"

void keybad_intial(unsigned char portname)
{
	DIO_vSetPortDir(portname,0x0f);
  DIO_vEbablePullUp(portname,0x4);
	DIO_vEbablePullUp(portname,0x5);
	DIO_vEbablePullUp(portname,0x6);
	DIO_vEbablePullUp(portname,0x7);
}
unsigned char keypad_read(unsigned char portname)
{
	unsigned char k [4][4]={{'1','2','3','A'},{'4','5','6','B'},{'7','8','9','c'},{'*','0','#','D'}};
	char row;  char col;  char x;  
	char Returnvalue=0xff;
	for(row=0;row<4;row++){
		DIO_vWriteLowLevel(portname,0xff)
		DIO_vWritePin(portname,row,0)
		for(col=0;col<=0;col++)
		{x=DIO_u8ReadPin(portname,col+4)
			if(x==0){ 
				Returnvalue=k[row][col];
			  break;}}
		return Returnvalue;}
	}
		
	
	
	
	
	
		

