/****************************************************************/
/*   Author             :    Gamal Ahmed Gamal 				    */
/*	 Date 				:    11 March 2023 						*/
/*	 Version 			:    1.0V 							 	*/
/*   Description	    :    prog.c for EEPROM                  */
/****************************************************************/

/****************************************************************/
/*********************** STD LIB DIRECTIVES *********************/
/****************************************************************/

#include "../LIB/std_types.h"
#include "../LIB/bit_math.h"


/****************************************************************/
/*********************** Component DIRECTIVES *******************/
/****************************************************************/

#include "../MCAL/EEPROM/EEPROM_Interface.h"
#include "../MCAL/EEPROM/EEPROM_Private.h"

void EEPROM_VoidWrite(u16 u16Address, u8 u8Data){
	
     while(CHECK_BIT(EECR , EEWE ));	         /* Wait for completion of previous write */
     
     EEAR = u16Address ;                      /* Set up address and data registers */
     
     EEDR = u8Data ;
     
     SET_BIT(EECR ,EEMWE );                   /* Write logical one to EEMWE */
     
     SET_BIT(EECR,EEWE);                       /* Start eeprom write by setting EEWE */

	
}



u8 EEPROM_read(u16 u16Address){

    while(CHECK_BIT(EECR,EEWE));              /* Wait for completion of previous write */
   
    EEAR = u16Address ;                       /* Set up address register */
  
    SET_BIT(EECR , EERE );                   /* Start eeprom read by writing EERE */
 
    return EEDR;                              /* Return data from data register */
}


