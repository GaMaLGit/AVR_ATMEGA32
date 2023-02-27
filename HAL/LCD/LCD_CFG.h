/****************************************************************/
/*   Author             :    Gamal Ahmed Gamal 				    */
/*	 Date 				:    25 Feb 2023 						*/
/*	 Version 			:    1.0V 							 	*/
/*	 Description 		:    Configure LCD [config.h] 	        */
/****************************************************************/ 


#ifndef LCD_CFG_H_
#define LCD_CFG_H_


#include "../HAL/LCD/LCD.h"
#include "../LIB/std_types.h"

#define NUM_OF_LCD 1

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
	PORTx LCD_Control_PORT ; 
	PORTx LCD_DATA_PORT ;  
	u16   EN_Delay ; 
	PINx  EN ;
	PINx  RS ; 
	PINx  D4 ; 
	PINx  D5 ; 
	PINx  D6 ; 
	PINx  D7 ; 	
	}LCD_Config;


LCD_Config Config_LCD[NUM_OF_LCD] ;



#endif 