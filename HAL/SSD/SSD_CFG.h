/****************************************************************/
/*   Author             :    Gamal Ahmed Gamal 				    */
/*	 Date 				:    25 Feb 2023 						*/
/*	 Version 			:    1.0V 							 	*/
/*	 Description 		:    Configure Seven Segment            */
/****************************************************************/


#ifndef SSD_CFG_H_
#define SSD_CFG_H_

#include "../HAL//SSD/SSD.h"

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
	PORTx BCD_PORT ; 
	PINx  BCD_PIN1 ;
	PINx  BCD_PIN2 ;
	PINx  BCD_PIN4 ; 
	PINx  BCD_PIN8 ;
	PORTx MX_PORT1 ;
	PINx  COM4 ;
	PINx  COM3 ;
	PORTx MX_PORT2 ;
	PINx  COM2 ;
	PINx  COM1 ;
	
	}SSD_Config;


SSD_Config Config_SSD[1] ;



#endif 

/**********************************************************************************************************************
 *  END OF FILE
 *********************************************************************************************************************/
