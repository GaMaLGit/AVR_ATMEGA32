/****************************************************************/
/*   Author             :    Gamal Ahmed Gamal 				    */
/*	 Date 				:    25 Feb 2023 						*/
/*	 Version 			:    1.0V 							 	*/
/*	 Description 		:    Configure Push Buttons [config.c] 	*/
/****************************************************************/

#include "../HAL/PushButton/PushButtonCFG.h"
#include "../HAL/PushButton/PushButton.h"

/****************************************************************/
/** !comment : Please Enter the Configurations           		*/
/****************************************************************/

Button_Config Config[NUM_OF_Buttons] = {
	{
		.Port = PORTD ,
		.Pin  = PIN3 , 
		.state = PULL_UP ,
		.Num   = BUTTON1 
	},
	
	{
		.Port = PORTD ,
		.Pin  = PIN5 ,
		.state = PULL_UP ,
		.Num   = BUTTON2 
	},
		{
			.Port = PORTD ,
			.Pin  = PIN6 ,
			.state = PULL_UP ,
			.Num   = BUTTON3
		},
		{
			.Port = PORTD ,
			.Pin  = PIN7 ,
			.state = PULL_UP ,
			.Num   = BUTTON4
		}
	
	
	
};

/***********************************************************************************************/
/************************************* END OF PROGRAM ******************************************/
/***********************************************************************************************/