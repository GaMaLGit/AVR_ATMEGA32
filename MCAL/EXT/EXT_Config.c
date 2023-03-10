/****************************************************************/
/*   Author             :    Gamal Ahmed Gamal 				    */
/*	 Date 				:    25 Feb 2023 						*/
/*	 Version 			:    1.0V 							 	*/
/*	 Description 		:    Configure Sense Mode [config.c] 	*/
/****************************************************************/

/****************************************************************/
/*********************** Component DIRECTIVES *******************/
/****************************************************************/

#include "../MCAL/EXT/EXT_Config.h"

/****************************************************************/
/** !comment : Please Enter the Configurations           		*/
/****************************************************************/

EXT_Config Config_EXT[NUM_OF_EXT] = {
	
	{
     .EXT_Number = EXT1 ,
	 .Sense_Mode = Rising  	
	}
	
};


/***********************************************************************************************/
/************************************* END OF PROGRAM ******************************************/
/***********************************************************************************************/