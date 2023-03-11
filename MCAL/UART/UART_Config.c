/****************************************************************/
/*   Author             :    Gamal Ahmed Gamal 				    */
/*	 Date 				:    3 March 2023 						*/
/*	 Version 			:    1.0V 							 	*/
/*	 Description 		:    Configure UART [config.c]       	*/
/****************************************************************/

/****************************************************************/
/*********************** Component DIRECTIVES *******************/
/****************************************************************/

#include "../MCAL/UART/UART_Config.h"

/****************************************************************/
/** !comment : Please Enter the Configurations           		*/
/****************************************************************/

UART_config Config_UART[1] = {
	{
	.Baud_Rate = Baudrate_9600 , 
	.DataSize  = eight_bits    ,
	.Parity    = Even_Parity   , 
	.StopBits  = one_bit       	
	}
};

