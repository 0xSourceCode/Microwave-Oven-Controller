#include "tm4c123gh6pm.h"
#include <stdint.h>
#include "DIO.h"
#include "keypad.h"
#include "Timer.h"
#include "Switch.h"
#include "LED.h"
#include "LCD.h"
 
 // popcorn func----------------------------------------------
 void popcorn(void)
{
			LCD_moveCursor(0,1);
			LCD_sendString("Popcorn");
			LCD_clearScreen();

			uint32_t i;
			for (i = 1; i < 61; i++) {
				LCD_sendString((char*)i);
				LCD_clearScreen();
				wait_1sec();

			}
		
}
//-------------------------------------------------------------

// beef func------------------------------------------------------
void Beef(void)
	{
				LCD_moveCursor(0,1);
				LCD_sendString("number");
				LCD_moveCursor(1,1);
				LCD_sendString("kilos");
				char button = keypad_read('A');
				LCD_clearScreen();
				if (button == '0')
				{
					LCD_moveCursor(0,1);
					LCD_sendString("Err");
					wait_secs(2);
					LCD_clearScreen();
				}
				else {

					LCD_moveCursor(0,1);
					LCD_sendString("button");
					wait_secs(2);
					LCD_clearScreen();

					char deforset_m = 0.5 * button;
					char deforset_sec = deforset_m * 60;

					for (int i = 1; i < deforset_sec; i++) {
						LCD_sendString((char*)i);
						LCD_clearScreen();
						wait_1sec();
					
					}
				}
			
		}
	//----------------------------------------------------------------

		
	// chiken func------------------------------------------------------------------
		void chicken(void)
	{
				LCD_moveCursor(0,1);
				LCD_sendString("number");
				LCD_moveCursor(1,1);
				LCD_sendString("kilos");
				char button = keypad_read('A');
				LCD_clearScreen();
				if (button == '0')
				{
					LCD_moveCursor(0,1);
					LCD_sendString("Err");
					wait_secs(2);
					LCD_clearScreen();
				}
				else {

					LCD_moveCursor(0,1);
					LCD_sendString("button");
					wait_secs(2);
					LCD_clearScreen();

					char deforset_m = 0.2 * button;
					char deforset_sec = deforset_m * 60;

					for (int i = 1; i < deforset_sec; i++) {
						LCD_sendString((char*)i);
						LCD_clearScreen();
						wait_1sec();
					
					}
				}
			
		}
		
	//--------------------------------------------------------------------------------
		
	// cooking time func -------------------------------------------------------------------
	
	
	//------------------------------------------------------------------------------------------
		
		
	
		/* all led function are in led.h but I use this function becouse operation on 3 leds 
		in one func  but the  led.h every led need func*/
		
 // array of leds on---------------------------------------------------------------------
		void leds_on (void)
		{
			port_vInit('F');
			DIO_vSetPortDir('F',0x0E);
			GPIO_PORTF_DATA_R=GPIO_PORTF_DATA_R & 0x0E ;
			
		}
		
	//-------------------------------------------------------------------------------
		
	//array of leds blink in last 3 scneds--------------------------------------------------------------------------
		
		/*void leds_blink (void)
		{
			port_vInit('F');
			DIO_vSetPortDir('F',0x0E);
		for(int i;   ;   ){
			GPIO_PORTF_DATA_R=GPIO_PORTF_DATA_R ^ 0x0E ;
			}
		}*/
		
	//---------------------------------------------------------------------------------------------------
	 
	// array of leds is of--------------------------------------------------------------------
		void leds_off (void)
		{
			port_vInit('F');
			DIO_vSetPortDir('F',0x0E);
			GPIO_PORTF_DATA_R=GPIO_PORTF_DATA_R & 0x00 ;
			
		}
		
	//-------------------------------------------------------------------------------------------
	
	//leds flash-------------------------------------------------------------------------------------------
		void leds_flash (void)
		{
			port_vInit('F');
			DIO_vSetPortDir('F',0x0E);
			for(int i=0; i<4 ;i++)
				{
			   GPIO_PORTF_DATA_R=GPIO_PORTF_DATA_R ^ 0x0E ;
				 wait_1sec();
			  }
		}
	//----------------------------------------------------------------------------------------------------
	
		
		 
		 
int main(void){
	switch_vint_pullup('A',2); //sw3 ---> door
	LCD_vInit();
	while(1)
	{
		if(switch_vRead('A',2)==1) // sw3 not pused door is open
			{  
		  LCD_sendString("please close the door");
		  } 
			
		else if (switch_vRead('A',2)==1) // sw3 is pused door is closed
     {
			 //--------------------------------------------
			 if (switch_vRead('A',2)==1) // door is open during the cooking  stop cooking
			   {
					 // lcd show remanning time 
				 }
				 // ---------------------------------------
			  
				 
				 LCD_vInit();
	      char button = keypad_read('E');
		    if (button == 'A')
		      {
			      popcorn();
		      }
					
				else if (button == 'B')	
            {
					   Beef();
		        }
				
						else if (button=='C')
						{
							chicken();
						}
						
						else if (button=='D')
						{
							// cooking time
						}
			    
						 
						switch_vint('F',4);
						if (switch_vRead ('F',4)==0) // start cooking 
						{
							
						}
						switch_vint('F',0);
						if (switch_vRead ('F',0)==0) // sw1 pressed first time --->cooking is paused
						{
							//lcd show the remanning time
							if (switch_vRead ('F',0)==0) // sw1 pressed second time ---> stop cooking clear lcd 
							{
								LCD_clearScreen();
							}
							else if (switch_vRead ('F',4)==0 & switch_vRead('A',2)==1) // if sw2 presed after pause and door is closed  continue cooking and show the last remanning time
								{
									// lcd resume remanning time 
							  }
							
						}
						
						
					
		       
         
			 
			 
     }
			
		
	 }
	}
