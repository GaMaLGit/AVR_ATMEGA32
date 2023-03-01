/****************************************************************/
/*   Author             :    Gamal Ahmed Gamal 				    */
/*	 Date 				:    25 Feb 2023 						*/
/*	 Version 			:    1.0V 							 	*/
/*	 Description 		:   contain Dc Motors Numbers config	*/
/*             							[config.h] 		        */
/****************************************************************/


/****************************************************************/
/* Description   : Guard to protect this File from include more */
/*                 than one time .                              */
/****************************************************************/

#ifndef _DCMOTOR_CONFIG_H
#define _DCMOTOR_CONFIG_H


#define NUMBER_OF_MOTORS	2

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


typedef struct {
PORTx Right_Motor_Port ; 
PINx  Right_Motor_Pin  ;
PORTx Left_Motor_Port  ;
PINx  Left_Motor_Pin   ;
}DCMotor_Config;


DCMotor_Config Config_DCMotor[NUMBER_OF_MOTORS] ;




#endif /** !comment  :  End of guard                            **/
