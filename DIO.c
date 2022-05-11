#include "stdint.h"
#include "tm4c123gh6pm.h" 
#include "BITCTRL.h"


//initialize port by name
void port_vInit(unsigned char portname){
	switch(portname){
		case 'A':
		case 'a':
			SET_BIT(SYSCTL_RCGCGPIO_R, 0);
			while((READ_BIT(SYSCTL_PRGPIO_R, 0)) == 0);
			GPIO_PORTA_LOCK_R = 0x4C4F434B;
			GPIO_PORTA_CR_R = 0xFF;
			GPIO_PORTA_DEN_R = 0xFF;
			break;
		}
		//todo: 
		// same for all pins ...
}


// set the direction for a pin-> input(0) or output(1)
void DIO_vSetPinDir(unsigned char portname, unsigned char pin_number, unsigned char direction){
	switch(portname){
		case 'A':
		case 'a':
			(direction == 1) ? (SET_BIT(GPIO_PORTA_DIR_R, pin_number)) : (CLEAR_BIT(GPIO_PORTA_DIR_R, pin_number));
			break;
		}
		//todo: 
		// same for all pins ...
}	


// set the direction for a port
void DIO_vSetPortDir(unsigned char portname, unsigned char direction){
	switch(portname){
		case 'A':
		case 'a':
			GPIO_PORTA_DIR_R = direction;
			break;
		}
		//todo: 
		// same for all pins ...
}	

// write data to a pin
void DIO_vWritePin(unsigned char portname, unsigned char pin_number, unsigned char data){
	switch(portname){
		case 'A':
		case 'a':
			(data == 1) ? (SET_BIT(GPIO_PORTA_DATA_R, pin_number)) : (CLEAR_BIT(GPIO_PORTA_DATA_R, pin_number));
			break;
		}
		//todo: 
		// same for all pins ...
}

// write data to a port
void DIO_vWritePort(unsigned char portname, unsigned char data){
	switch(portname){
		case 'A':
		case 'a':
			GPIO_PORTA_DATA_R = data;
			break;
		}
		//todo: 
		// same for all pins ...
}


// toggle  pin
void DIO_vTogglePin(unsigned char portname, unsigned char pin_number){
	switch(portname){
		case 'A':
		case 'a':
			TOG_BIT(GPIO_PORTA_DATA_R, pin_number)
			break;
		}
		//todo: 
		// same for all pins ...
}

// Read from a pin
unsigned char DIO_u8ReadPin(unsigned char portname, unsigned char pin_number){
	switch(portname){
		case 'A':
		case 'a':
			return (READ_BIT(GPIO_PORTA_DATA_R, pin_number));
		}
	//todo: 
		// same for all pins ...
 return 'e';
}

// Read from a port
unsigned char DIO_u8ReadPort(unsigned char portname){
	switch(portname){
		case 'A':
		case 'a':
			return  GPIO_PORTA_DATA_R;
		}
	//todo: 
		// same for all pins ...
 return 'e';
}

// Rnable pullup
void DIO_vEbablePullUp(unsigned char portname, unsigned char pin_number){
	switch(portname){
		case 'A':
		case 'a':
			SET_BIT(GPIO_PORTA_PUR_R, pin_number);
			break;
		}
	//todo: 
		// same for all pins ...
}


//write to the 4 most sig. bits
void DIO_vWriteHighLevel(unsigned char portname, unsigned char data){
	switch(portname){
		data <<= 4;
		case 'A':
		case 'a':
			GPIO_PORTA_DATA_R &= 0x0F;
			GPIO_PORTA_DATA_R |= data;
			break;
		}
	//todo: 
		// same for all pins ...
}

//write to the 4 least sig. bits
void DIO_vWriteLowLevel(unsigned char portname, unsigned char data){
	switch(portname){
		case 'A':
		case 'a':
			GPIO_PORTA_DATA_R &= 0xF0;
			GPIO_PORTA_DATA_R |= data;
			break;
		}
	//todo: 
		// same for all pins ...
}