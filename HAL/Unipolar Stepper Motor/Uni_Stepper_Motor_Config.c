/****************************************************************/
/*   Author             :    Gamal Ahmed Gamal 				    */
/*	 Date 				:    27 Feb 2023 						*/
/*	 Version 			:    1.0V 							 	*/
/*	 Description 		:   Stepper Motors configuration        */
/*             							[config.c] 				*/
/****************************************************************/


#include "Uni_Stepper_Motor_Config.h"


/*****************************************************************/
/* !comment : Please Fill the Configuration for Stepper Motor    */
/*****************************************************************/


StepperMotor_Config Config_StepperMotor[NUMBER_OF_STEPPER_MOTORS] = {
	
	{
	.Stepper_Mode = Full_Step  ,
	.Stepper_Port = PORTB      ,
	.Stepper_Pin1 = PIN0       ,
	.Stepper_Pin2 = PIN1       ,	
	.Stepper_Pin3 = PIN2       ,
	.Stepper_Pin4 = PIN3       	
	},
	{
	.Stepper_Mode = Half_Step  ,
	.Stepper_Port = PORTC      ,
	.Stepper_Pin1 = PIN0       ,
	.Stepper_Pin2 = PIN1       ,
	.Stepper_Pin3 = PIN2       ,
	.Stepper_Pin4 = PIN3
	}	
	
	
};

