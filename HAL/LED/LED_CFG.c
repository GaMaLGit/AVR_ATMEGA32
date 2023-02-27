/****************************************************************/
/*   Author             :    Gamal Ahmed Gamal 				    */
/*	 Date 				:    25 Feb 2023 						*/
/*	 Version 			:    1.0V 							 	*/
/*	 Description 		:    Configure LED [config.c]       	*/
/****************************************************************/

#include "../HAL//LED/LED.h"
#include "../HAL//LED/LED_CFG.h"

/****************************************************************/
/** !comment : Please Enter the Configurations           		*/
/****************************************************************/

LED_Config Config_LED[NUM_OF_LEDS]  = {
	
	{
	.Port = PORTB , 
	.Pin  = PIN7  , 
	.State = SOURCE ,
	.Num   = RED  	
			
	} ,
	
	{
	.Port = PORTA ,
	.Pin  = PIN5  ,
	.State = SOURCE ,
	.Num   = BLUE	
	} ,
	
		{
	.Port = PORTA ,
	.Pin  = PIN4  ,
	.State = SOURCE ,
	.Num   = GREEN 
		} ,
	
	 	{
	.Port = PORTA ,
	.Pin  = PIN6  ,
	.State = SOURCE ,
	.Num   = YELLOW
	 	} 
	
};

/**********************************************************************************************************************
 *  END OF FILE
 *********************************************************************************************************************/

