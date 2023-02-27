/****************************************************************/
/*   Author             :    Gamal Ahmed Gamal 				    */
/*	 Date 				:    25 Feb 2023 						*/
/*	 Version 			:    1.0V 							 	*/
/*   Description	    :    prog.c for EXT	                    */
/****************************************************************/


/****************************************************************/
/*********************** STD LIB DIRECTIVES *********************/
/****************************************************************/

#include "../LIB/std_types.h"
#include "../LIB/bit_math.h"


/****************************************************************/
/*********************** Component DIRECTIVES *******************/
/****************************************************************/

#include "../MCAL/EXT/EXT_Interface.h"
#include "../MCAL/EXT/EXT_Config.h"
#include "../MCAL/EXT/EXT_Private.h" 

/****************************************************************/
/******************************* Macros *************************/
/****************************************************************/

#define  MCUCR_MASK 0b11110011



/***********************************************************/
/**!comment   :  pointer to function for callback	       */
/***********************************************************/
void (*GLOBAL_EXT0) (void);
void (*GLOBAL_EXT1) (void);
void (*GLOBAL_EXT2) (void);

/****************************************************************/
/*********************** Function Implementation  ***************/
/****************************************************************/


/****************************************************************/
/* Description    :  This function used to initialize EXT       */
/*					 Inputs : void 								*/
/*					 return : void		 						*/
/****************************************************************/


void EXT_voidInit (void)
{

	
	for(u8 i = 0 ; i <NUM_OF_EXT ; i++){
	//Configure Sense Mode
	MCUCR &= MCUCR_MASK ; 
	MCUCR |= Config_EXT[i].Sense_Mode << 2 ;
	// disable EXT0 in initialization function 
	switch(Config_EXT[i].EXT_Number){
		
		case  EXT0 : CLEAR_BIT(GICR , 6 );
		             SET_BIT  (GIFR , 6 ); 
		break ;
		
		case  EXT1 : CLEAR_BIT(GICR , 7 );
		             SET_BIT  (GIFR , 7 ); 
		break ;
		
		case  EXT2 : CLEAR_BIT(GICR , 5 ); 
		             SET_BIT  (GIFR , 5 );
		break ;
		
	}
		
	}
	
	
	
}



/****************************************************************/
/* Description    : This function used to Enable EXT			*/ 
/*																*/
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after Interrupt */
/*     				 initialized 							    */
/****************************************************************/


void EXT_voidEnable()
{
	
for(u8 i = 0 ; i <NUM_OF_EXT ; i++){
	
	switch(Config_EXT[i].EXT_Number){
		
		case  EXT0 : SET_BIT(GICR , 6 ); break ;		
		case  EXT1 : SET_BIT(GICR , 7 ); break ;
		case  EXT2 : SET_BIT(GICR , 5 ); break ;
	
	}
	
}
	

}



/****************************************************************/
/* Description    : This function used to Disable EXT			*/ 
/*																*/
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after Interrupt */
/*     				 initialized 							    */
/****************************************************************/
void EXT_voidDisable()
{
	
	for(u8 i = 0 ; i <NUM_OF_EXT ; i++){
		
		switch(Config_EXT[i].EXT_Number){
			
			case  EXT0 : CLEAR_BIT(GICR , 6 ); break ;
			case  EXT1 : CLEAR_BIT(GICR , 7 ); break ;
			case  EXT2 : CLEAR_BIT(GICR , 5 ); break ;
			
		}
		
	}
	
}


/****************************************************************/
/* Description    : This function used to communicate with the	*/
/*					function in App Layer(The Callback function)*/ 
/*						[ Layer Architecture Problem Solved ]	*/
/*																*/
/*					Inputs : Pointer to function that points to	*/
/*							 the first line of the function(ISR)*/
/*					Return : void								*/
/****************************************************************/
/* Pre_condition  :  this function must be used after Interrupt */
/*     				 initialized 							    */
/****************************************************************/

void EXT0_voidCallBack(void (*addresscpy)(void))
{

	GLOBAL_EXT0 = addresscpy;
	
}

/****************************************************************/
/* Description    : This function used to communicate with the	*/
/*					function in App Layer(The Callback function)*/
/*						[ Layer Architecture Problem Solved ]	*/
/*																*/
/*					Inputs : Pointer to function that points to	*/
/*							 the first line of the function(ISR)*/
/*					Return : void								*/
/****************************************************************/
/* Pre_condition  :  this function must be used after Interrupt */
/*     				 initialized 							    */
/****************************************************************/

void EXT1_voidCallBack(void (*addresscpy)(void))
{

		GLOBAL_EXT1 = addresscpy;
	
}

/****************************************************************/
/* Description    : This function used to communicate with the	*/
/*					function in App Layer(The Callback function)*/
/*						[ Layer Architecture Problem Solved ]	*/
/*																*/
/*					Inputs : Pointer to function that points to	*/
/*							 the first line of the function(ISR)*/
/*					Return : void								*/
/****************************************************************/
/* Pre_condition  :  this function must be used after Interrupt */
/*     				 initialized 							    */
/****************************************************************/

void EXT2_voidCallBack(void (*addresscpy)(void))
{

	GLOBAL_EXT2 = addresscpy;
	
}



/****************************************************************/
/* Description    : This function used to Set latch Interrupt	*/
/*									 happens.					*/ 
/*																*/
/*					Inputs : Sense Mode				  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after Interrupt */
/*     				 initialized 							    */
/****************************************************************/
void EXT_voidSetSignalch(u8 SenseCpy)
{
	

	if(SenseCpy == Config_EXT[0].Sense_Mode){
	SET_BIT  (MCUCR , 2);
	CLEAR_BIT(MCUCR , 3);		
	}
	else if(SenseCpy == Config_EXT[0].Sense_Mode){
	SET_BIT(MCUCR , 2);
	SET_BIT(MCUCR , 3);
	}
	else if(SenseCpy == Config_EXT[0].Sense_Mode){
	CLEAR_BIT(MCUCR , 2);
	SET_BIT  (MCUCR , 3);
		}
	else if(SenseCpy == Config_EXT[0].Sense_Mode){
	CLEAR_BIT(MCUCR , 2);
	CLEAR_BIT(MCUCR , 3);
	}
			
}


/** Linker Problem solved */

void __vector_1(void)   // INT0 ISR
{
	(*GLOBAL_EXT0) ();
	
}

void __vector_2(void)   // INT1 ISR
{
	 (*GLOBAL_EXT1) ();
	
}

void __vector_3(void)   // INT1 ISR
{
	(*GLOBAL_EXT2) ();
	
}

/***********************************************************************************************/
/************************************* END OF PROGRAM ******************************************/
/***********************************************************************************************/