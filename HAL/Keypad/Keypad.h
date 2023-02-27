/****************************************************************/
/*   Author             :    Gamal Ahmed Gamal 				    */
/*	 Date 				:    25 Feb 2023 						*/
/*	 Version 			:    1.0V 							 	*/
/*	 Description : public Accessing mechanism prototype         */
/****************************************************************/


#ifndef KEYPAD_H_
#define KEYPAD_H_

/****************************************************************/
/*********************** STD LIB DIRECTIVES *********************/
/****************************************************************/
#include "../LIB/std_types.h"



void keypad_init(void);
u8 keypad_scanner(void);
u8 keypad_switch_Pressed (void);





#endif /* KEYPAD_H_ */