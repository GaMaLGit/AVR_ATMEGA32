/****************************************************************/
/*   Author             :    Gamal Ahmed Gamal 				    */
/*	 Date 				:    25 Feb 2023 						*/
/*	 Version 			:    1.0V 							 	*/
/*	 Description 		:    Configure Keypad [config.h] 	    */
/****************************************************************/

#ifndef KEYPAD_CFG_H_
#define KEYPAD_CFG_H_

/****************************************************************/
/** !comment : Choose the Ports From					      	*/
/****************************************************************/

typedef enum{
	PORTA,
	PORTB,
	PORTC,
	PORTD
}PORTx;

/****************************************************************/
/** !comment : Choose the Pins From		     			      	*/
/****************************************************************/

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
	
	PORTx COL_PORT ; 
	PORTx ROW_PORT ;
	PINx  COL1_PIN ;
	PINx  COL2_PIN ;
	PINx  COL3_PIN ;
	PINx  COL4_PIN ;
	PINx  ROW1_PIN ;
	PINx  ROW2_PIN ;
	PINx  ROW3_PIN ;
	PINx  ROW4_PIN ;
	
	}Keypad_config;


Keypad_config Config_keypad[1] ; 


#endif /* KEYPAD_CFG_H_ */