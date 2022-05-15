#include "tm4c123gh6pm.h"
#include <stdint.h>
#include "DIO.h"

void LED_vInit(unsigned char portname, unsigned char pin_number){
	port_vInit(portname);
	DIO_vSetPinDir(portname, pin_number, 1);
}

void LED_vON(unsigned char portname, unsigned char pin_number){
	DIO_vWritePin(portname, pin_number, 1);
}

void LED_vOFF(unsigned char portname, unsigned char pin_number){
	DIO_vWritePin(portname, pin_number, 0);
}

void LED_vTOG(unsigned char portname, unsigned char pin_number){
	DIO_vTogglePin(portname,pin_number);
}