/****************************************************************/
/*   Author             :    Gamal Ahmed Gamal 				    */
/*	 Date 				:    25 Feb 2023 						*/
/*	 Version 			:    1.0V 							 	*/
/*	 Description 		:   contain Dc Motors Pins configuration*/
/*             							[config.c] 				*/
/****************************************************************/


#include "../HAL/DCMotor/DCMotor_Config.h"




/*****************************************************************/
/* !comment : Please Fill the Configuration for DC Motor   	 	 */
/*****************************************************************/

DCMotor_Config Config_DCMotor[NUMBER_OF_MOTORS] = {
	{
	  .Right_Motor_Port = PORTB ,
	  .Right_Motor_Pin  = PIN0  ,
	  .Left_Motor_Port  = PORTB , 
	  .Left_Motor_Pin   = PIN1  	
	},
	{
	  .Right_Motor_Port = PORTB ,
	  .Right_Motor_Pin  = PIN2  ,
	  .Left_Motor_Port  = PORTB ,
	  .Left_Motor_Pin   = PIN3		
	}
	
};

/***********************************************************************************************/
/************************************* END OF PROGRAM ******************************************/
/***********************************************************************************************/