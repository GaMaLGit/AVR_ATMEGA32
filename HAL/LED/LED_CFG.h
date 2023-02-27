/****************************************************************/
/*   Author             :    Gamal Ahmed Gamal 				    */
/*	 Date 				:    25 Feb 2023 						*/
/*	 Version 			:    1.0V 							 	*/
/*	 Description 		:    Configure LED [config.h]       	*/
/****************************************************************/


#ifndef LED_CFG_H_
#define LED_CFG_H_


#include "../HAL//LED/LED.h"

#define NUM_OF_LEDS 4

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


typedef enum
{
	SOURCE ,
	SINK 

}LED_t;


typedef struct {
	
	PORTx  Port ; 
	PINx   Pin  ;
	LED_t  State;
	LED_ID Num  ;
	}LED_Config;

LED_Config Config_LED[NUM_OF_LEDS]  ;


#endif 