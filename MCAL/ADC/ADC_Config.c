/****************************************************************/
/*   Author             :    Gamal Ahmed Gamal 				    */
/*	 Date 				:    25 Feb 2023 						*/
/*	 Version 			:    1.0V 							 	*/
/*	 Description 		:    Configure Sense Mode [config.c] 	*/
/****************************************************************/

/****************************************************************/
/*********************** Component DIRECTIVES *******************/
/****************************************************************/

#include "../MCAL/ADC/ADC_Config.h"

/****************************************************************/
/** !comment : Please Enter the Configurations           		*/
/****************************************************************/


ADC_Config Config_ADC[NUM_OF_ADC] = {
	{
	.V_Ref     = AVCC             , 
	.Adj       = Right_Adjustment ,
	.Trig_S    = EXT0             ,
	.Prescaler = Prescaler_128 
	}
	
};




