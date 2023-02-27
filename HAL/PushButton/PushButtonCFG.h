/****************************************************************/
/*   Author             :    Gamal Ahmed Gamal 				    */
/*	 Date 				:    25 Feb 2023 						*/
/*	 Version 			:    1.0V 							 	*/
/*	 Description 		:    Configure Push Buttons [config.c] 	*/
/****************************************************************/


#ifndef PUSHBUTTONCFG_H_
#define PUSHBUTTONCFG_H_


#define NUM_OF_Buttons 4

#include "../HAL/PushButton/PushButton.h"

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



// Choose either Pull UP or Pull DOWN

typedef enum
{
	PULL_DOWN ,
	PULL_UP 

}BUTTON_t;



typedef struct{
	PORTx Port ;
	PINx  Pin  ;
	BUTTON_t state ;
    BUTTON_ID Num  ;
}Button_Config;



Button_Config Config[NUM_OF_Buttons];



#endif 
/***********************************************************************************************/
/************************************* END OF PROGRAM ******************************************/
/***********************************************************************************************/