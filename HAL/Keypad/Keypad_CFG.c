/****************************************************************/
/*   Author             :    Gamal Ahmed Gamal 				    */
/*	 Date 				:    25 Feb 2023 						*/
/*	 Version 			:    1.0V 							 	*/
/*	 Description 		:    Configure Keypad [config.c] 	    */
/****************************************************************/

#include "../HAL/Keypad/Keypad_CFG.h"
#include "../MCAL/DIO/dio.h"

/****************************************************************/
/** !comment : Please Enter the Configurations           		*/
/****************************************************************/

Keypad_config Config_keypad[1] = {
	
	{
	.COL_PORT = PORTD ,
	.COL1_PIN = PIN7  ,
	.COL2_PIN = PIN6  , 
	.COL3_PIN = PIN5  , 
	.COL4_PIN = PIN3  , 
	.ROW_PORT = PORTC , 
	.ROW1_PIN = PIN5  , 
	.ROW2_PIN = PIN4  , 
	.ROW3_PIN = PIN3  , 
	.ROW4_PIN = PIN2		
	}
		
} ;
