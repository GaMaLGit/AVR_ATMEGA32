/****************************************************************/
/*   Author             :    Gamal Ahmed Gamal 				    */
/*	 Date 				:    25 Feb 2023 						*/
/*	 Version 			:    1.0V 							 	*/
/*   Description	    :    prog.c for Keypad	                */
/****************************************************************/

/****************************************************************/
/*********************** STD LIB DIRECTIVES *********************/
/****************************************************************/
#include "../LIB/std_types.h"

/****************************************************************/
/*********************** Component DIRECTIVES *******************/
/****************************************************************/
#include "../HAL/Keypad/Keypad.h"
#include "../HAL/Keypad/Keypad_CFG.h"
#include "../MCAL/DIO/dio.h"
#include <util/delay.h>

/****************************************************************/
/* Description    :  This function used to initialize Keypad    */
/*					 Inputs : void 								*/
/*					 return : void		 						*/
/****************************************************************/


void keypad_init(void){
// configure direction of pins	
dio_vidConfigChannel(Config_keypad->ROW_PORT , Config_keypad->ROW1_PIN , OUTPUT);		
dio_vidConfigChannel(Config_keypad->ROW_PORT , Config_keypad->ROW2_PIN , OUTPUT);
dio_vidConfigChannel(Config_keypad->ROW_PORT , Config_keypad->ROW3_PIN , OUTPUT);
dio_vidConfigChannel(Config_keypad->ROW_PORT , Config_keypad->ROW4_PIN , OUTPUT);
dio_vidConfigChannel(Config_keypad->COL_PORT , Config_keypad->COL1_PIN , INPUT );	
dio_vidConfigChannel(Config_keypad->COL_PORT , Config_keypad->COL2_PIN , INPUT );
dio_vidConfigChannel(Config_keypad->COL_PORT , Config_keypad->COL3_PIN , INPUT );
dio_vidConfigChannel(Config_keypad->COL_PORT , Config_keypad->COL4_PIN , INPUT );	
	
//reset all pins

dio_vidWriteChannel(Config_keypad->ROW_PORT,Config_keypad->ROW1_PIN, STD_LOW );
dio_vidWriteChannel(Config_keypad->ROW_PORT,Config_keypad->ROW2_PIN, STD_LOW );
dio_vidWriteChannel(Config_keypad->ROW_PORT,Config_keypad->ROW3_PIN, STD_LOW );
dio_vidWriteChannel(Config_keypad->ROW_PORT,Config_keypad->ROW4_PIN, STD_LOW );
	
}

/****************************************************************/
/* Description    :  This function used to Scan Keypad keys     */
/*					 Inputs : void 								*/
/*					 return : void		 						*/
/****************************************************************/


u8 keypad_scanner(void){
	
	dio_vidWriteChannel(Config_keypad->ROW_PORT,Config_keypad->ROW1_PIN, STD_LOW );
	dio_vidWriteChannel(Config_keypad->ROW_PORT,Config_keypad->ROW2_PIN, STD_HIGH );
	dio_vidWriteChannel(Config_keypad->ROW_PORT,Config_keypad->ROW3_PIN, STD_HIGH );
	dio_vidWriteChannel(Config_keypad->ROW_PORT,Config_keypad->ROW4_PIN, STD_HIGH );
	
if(!dio_dioLevelReadChannel(Config_keypad->COL_PORT , Config_keypad->COL1_PIN)){ _delay_ms(100); while(!dio_dioLevelReadChannel(Config_keypad->COL_PORT , Config_keypad->COL1_PIN)) ; return '1' ;}	
if(!dio_dioLevelReadChannel(Config_keypad->COL_PORT , Config_keypad->COL2_PIN)){ _delay_ms(100); while(!dio_dioLevelReadChannel(Config_keypad->COL_PORT , Config_keypad->COL2_PIN)) ; return '2' ;}	
if(!dio_dioLevelReadChannel(Config_keypad->COL_PORT , Config_keypad->COL3_PIN)){ _delay_ms(100); while(!dio_dioLevelReadChannel(Config_keypad->COL_PORT , Config_keypad->COL3_PIN)) ; return '3' ;}	
if(!dio_dioLevelReadChannel(Config_keypad->COL_PORT , Config_keypad->COL4_PIN)){ _delay_ms(100); while(!dio_dioLevelReadChannel(Config_keypad->COL_PORT , Config_keypad->COL4_PIN)) ; return 'A' ;}	
	
	dio_vidWriteChannel(Config_keypad->ROW_PORT,Config_keypad->ROW1_PIN, STD_HIGH );
	dio_vidWriteChannel(Config_keypad->ROW_PORT,Config_keypad->ROW2_PIN, STD_LOW );
	dio_vidWriteChannel(Config_keypad->ROW_PORT,Config_keypad->ROW3_PIN, STD_HIGH );
	dio_vidWriteChannel(Config_keypad->ROW_PORT,Config_keypad->ROW4_PIN, STD_HIGH );	
	
if(!dio_dioLevelReadChannel(Config_keypad->COL_PORT , Config_keypad->COL1_PIN)){ _delay_ms(100); while(!dio_dioLevelReadChannel(Config_keypad->COL_PORT , Config_keypad->COL1_PIN)) ; return '4' ;}
if(!dio_dioLevelReadChannel(Config_keypad->COL_PORT , Config_keypad->COL2_PIN)){ _delay_ms(100); while(!dio_dioLevelReadChannel(Config_keypad->COL_PORT , Config_keypad->COL2_PIN)) ; return '5' ;}
if(!dio_dioLevelReadChannel(Config_keypad->COL_PORT , Config_keypad->COL3_PIN)){ _delay_ms(100); while(!dio_dioLevelReadChannel(Config_keypad->COL_PORT , Config_keypad->COL3_PIN)) ; return '6' ;}
if(!dio_dioLevelReadChannel(Config_keypad->COL_PORT , Config_keypad->COL4_PIN)){ _delay_ms(100); while(!dio_dioLevelReadChannel(Config_keypad->COL_PORT , Config_keypad->COL4_PIN)) ; return 'B' ;}	
	
	dio_vidWriteChannel(Config_keypad->ROW_PORT,Config_keypad->ROW1_PIN, STD_HIGH );
	dio_vidWriteChannel(Config_keypad->ROW_PORT,Config_keypad->ROW2_PIN, STD_HIGH );
	dio_vidWriteChannel(Config_keypad->ROW_PORT,Config_keypad->ROW3_PIN, STD_LOW );
	dio_vidWriteChannel(Config_keypad->ROW_PORT,Config_keypad->ROW4_PIN, STD_HIGH );	
	
if(!dio_dioLevelReadChannel(Config_keypad->COL_PORT , Config_keypad->COL1_PIN)){ _delay_ms(100); while(!dio_dioLevelReadChannel(Config_keypad->COL_PORT , Config_keypad->COL1_PIN)) ; return '7' ;}
if(!dio_dioLevelReadChannel(Config_keypad->COL_PORT , Config_keypad->COL2_PIN)){ _delay_ms(100); while(!dio_dioLevelReadChannel(Config_keypad->COL_PORT , Config_keypad->COL2_PIN)) ; return '8' ;}
if(!dio_dioLevelReadChannel(Config_keypad->COL_PORT , Config_keypad->COL3_PIN)){ _delay_ms(100); while(!dio_dioLevelReadChannel(Config_keypad->COL_PORT , Config_keypad->COL3_PIN)) ; return '9' ;}
if(!dio_dioLevelReadChannel(Config_keypad->COL_PORT , Config_keypad->COL4_PIN)){ _delay_ms(100); while(!dio_dioLevelReadChannel(Config_keypad->COL_PORT , Config_keypad->COL4_PIN)) ; return 'C' ;}	
	
	dio_vidWriteChannel(Config_keypad->ROW_PORT,Config_keypad->ROW1_PIN, STD_HIGH );
	dio_vidWriteChannel(Config_keypad->ROW_PORT,Config_keypad->ROW2_PIN, STD_HIGH );
	dio_vidWriteChannel(Config_keypad->ROW_PORT,Config_keypad->ROW3_PIN, STD_HIGH );
	dio_vidWriteChannel(Config_keypad->ROW_PORT,Config_keypad->ROW4_PIN, STD_LOW  );	
	
if(!dio_dioLevelReadChannel(Config_keypad->COL_PORT , Config_keypad->COL1_PIN)){ _delay_ms(100); while(!dio_dioLevelReadChannel(Config_keypad->COL_PORT , Config_keypad->COL1_PIN)) return '*' ;}
if(!dio_dioLevelReadChannel(Config_keypad->COL_PORT , Config_keypad->COL2_PIN)){ _delay_ms(100); while(!dio_dioLevelReadChannel(Config_keypad->COL_PORT , Config_keypad->COL2_PIN)) return '0' ;}
if(!dio_dioLevelReadChannel(Config_keypad->COL_PORT , Config_keypad->COL3_PIN)){ _delay_ms(100); while(!dio_dioLevelReadChannel(Config_keypad->COL_PORT , Config_keypad->COL3_PIN)) return '#' ;}
if(!dio_dioLevelReadChannel(Config_keypad->COL_PORT , Config_keypad->COL4_PIN)){ _delay_ms(100); while(!dio_dioLevelReadChannel(Config_keypad->COL_PORT , Config_keypad->COL4_PIN)) return 'D' ;}	
	
	
	return 'n' ; 
}

/****************************************************************/
/* Description    :  This function used to Scan the pressed key */
/*					 Inputs : void 								*/
/*					 return : u8 the pressed key		     	*/
/****************************************************************/


u8 keypad_switch_Pressed (void) {
	
	u8 key = 'n' ; 
	while(key == 'n'){
	key = keypad_scanner() ; 		
	}
	_delay_ms(50);
	return key ; 
	
}


