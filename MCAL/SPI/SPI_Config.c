/****************************************************************/
/*   Author             :    Gamal Ahmed Gamal 				    */
/*	 Date 				:    4 March 2023 						*/
/*	 Version 			:    1.0V 							 	*/
/*	 Description 		:    Configure SPI [config.c]       	*/
/****************************************************************/

/****************************************************************/
/*********************** Component DIRECTIVES *******************/
/****************************************************************/

#include "../MCAL/SPI/SPI_Config.h"

/****************************************************************/
/** !comment : Please Enter the Configurations           		*/
/****************************************************************/

SPI_Config Config_SPI[1] = {
	{
	.SPI_Data_Order = MSB        , 
	.M_S_Select     = Master_SPI , 
	.CLK_Phase      = Sample_SPI ,	
	.CLK_Rate       =  FOSC_div128 ,
	.CLK_Polarity   = Rising_SPI 
		
	}
	
};