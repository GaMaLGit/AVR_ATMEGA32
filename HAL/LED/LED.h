/****************************************************************/
/*   Author             :    Gamal Ahmed Gamal 				    */
/*	 Date 				:    25 Feb 2023 						*/
/*	 Version 			:    1.0V 							 	*/
/*	 Description        : public Accessing mechanism prototype  */
/****************************************************************/


#ifndef LED_H_
#define LED_H_


typedef enum
{
	RED ,
	GREEN ,
	BLUE , 
	YELLOW
}LED_ID;


void LED_INIT ( void );
void LED_ON ( LED_ID );
void LED_OFF ( LED_ID );
void LED_TOGGLE ( LED_ID );


#endif /* LED_H_ */