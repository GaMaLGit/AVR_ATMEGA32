/****************************************************************/
/*   Author             :    Gamal Ahmed Gamal 				    */
/*	 Date 				:    28 Feb 2023 						*/
/*	 Version 			:    1.0V 							 	*/
/*	 Description 		:   contain Stepper Motor config	    */
/*             							[config.h] 		        */
/****************************************************************/


/****************************************************************/
/* Description   : Guard to protect this File from include more */
/*                 than one time .                              */
/****************************************************************/

#ifndef UNI_STEPPER_MOTOR_CONFIG_H_
#define UNI_STEPPER_MOTOR_CONFIG_H_

#define NUMBER_OF_STEPPER_MOTORS	2

typedef enum{
	PORTA,
	PORTB,
	PORTC,
	PORTD
}PORTx;

typedef enum{
	PIN0,
	PIN1,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7,
	PIN8,
	PIN9,
	PIN10,
	PIN11,
	PIN12,
	PIN13,
	PIN14,
	PIN15
}PINx;

typedef enum {
	Full_Step  , 
	Half_Step  
}Step_Mode;



typedef struct{
	
PORTx      Stepper_Port ;
PINx       Stepper_Pin1 ;
PINx       Stepper_Pin2 ;
PINx       Stepper_Pin3 ;
PINx       Stepper_Pin4 ;	
Step_Mode  Stepper_Mode ;	
}StepperMotor_Config;

StepperMotor_Config Config_StepperMotor[NUMBER_OF_STEPPER_MOTORS] ;


#endif 

/***********************************************************************************************/
/************************************* END OF PROGRAM ******************************************/
/***********************************************************************************************/