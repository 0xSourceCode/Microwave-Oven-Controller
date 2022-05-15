#include "tm4c123gh6pm.h"
#include <stdint.h>
#include "DIO.h"

void LED_vInit(unsigned char portname, unsigned char pin_number);
void LED_vON(unsigned char portname, unsigned char pin_number);
void LED_vOFF(unsigned char portname, unsigned char pin_number);
void LED_vTOG(unsigned char portname, unsigned char pin_number);