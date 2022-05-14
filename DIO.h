#include "stdint.h"
#include "tm4c123gh6pm.h"
#include "BITCTRL.h"


void port_vInit(unsigned char portname);
void DIO_vSetPinDir(unsigned char portname, unsigned char pin_number, unsigned char direction);
void DIO_vSetPortDir(unsigned char portname, unsigned char direction);
void DIO_vWritePin(unsigned char portname, unsigned char pin_number, unsigned char data);
void DIO_vWritePort(unsigned char portname, unsigned char data);
void DIO_vTogglePin(unsigned char portname, unsigned char pin_number);
unsigned char DIO_u8ReadPin(unsigned char portname, unsigned char pin_number);
unsigned char DIO_u8ReadPort(unsigned char portname);
void DIO_vEbablePullUp(unsigned char portname, unsigned char pin_number);
void DIO_vWriteHighLevel(unsigned char portname, unsigned char data);
void DIO_vWriteLowLevel(unsigned char portname, unsigned char data);
void wait_1sec();
void wait_1msec();
void wait_secs(uint32_t secs);
void wait_millisecs(uint32_t millisecs);