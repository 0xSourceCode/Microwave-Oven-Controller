#include "DIO.h"

void switch_vint(unsigned char portname,unsigned char pin_number)
{
	port_vInit(portname);
  DIO_vSetPinDir( portname, pin_number, 0);
}

unsigned char switch_vRead (unsigned char portname,unsigned char pin_number)
{
	return DIO_u8ReadPin( portname, pin_number);
}

void switch_vint_pullup(unsigned char portname,unsigned char pin_number)
{
	port_vInit(portname);
	DIO_vEnablePullUp( portname, pin_number);
  DIO_vSetPinDir( portname, pin_number, 0);
}
