#include "DIO.h"

void LED_vInit(unsigned char portname, unsigned char pin_number){
	
	DIO_vSetPinDir(portname, pin_number, 1);
	

}

void LED_vON(unsigned char portname, unsigned char pin_number){
	
	DIO_vWritePin(portname, pin_number, 1);
	
}