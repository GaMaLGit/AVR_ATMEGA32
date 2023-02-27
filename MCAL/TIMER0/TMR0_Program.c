/****************************************************************/
/*   Author             :    Gamal Ahmed Gamal 				    */
/*	 Date 				:    25 Feb 2023 						*/
/*	 Version 			:    1.0V 							 	*/
/*   Description	    :    prog.c for TIMER0                  */
/****************************************************************/

/****************************************************************/
/*********************** STD LIB DIRECTIVES *********************/
/****************************************************************/

#include "../LIB/std_types.h"
#include "../LIB/bit_math.h"


/****************************************************************/
/*********************** Component DIRECTIVES *******************/
/****************************************************************/

#include "../MCAL/TIMER0/TMR0_Interface.h"
#include "../MCAL/TIMER0/TMR0_Private.h"
#include "../MCAL/TIMER0/TMR0_Config.h"

/****************************************************************/
/******************************* Macros *************************/
/****************************************************************/

#define  TCCR0_MASK1 0b11111000
#define  TCCR0_MASK2 0b11001111


/***********************************************************/
/**!comment   :  pointer to function for callback	       */
/***********************************************************/

void (*TIMER0_OV_CallBack) (void) ;
void (*TIMER0_CTC_CallBack) (void) ;


/****************************************************************/
/* Description    :  This function used to initialize TIMER0    */
/*					 Inputs : void 								*/
/*					 return : void		 						*/
/****************************************************************/


void TIMER0_void_Init(void)
{
	
	// Set Timer0 Mode	
	switch(Config_Timer0[0].TMR0_Mode){
       
	   case Normal_Mode : CLEAR_BIT(TCCR0 , 6);
	                      CLEAR_BIT(TCCR0 , 3);
	   break;			 	
	
	   case CTC         : CLEAR_BIT(TCCR0 , 6);
					      SET_BIT  (TCCR0 , 3);
	   break;		    
					    
	   case Fast_PWM    : SET_BIT(TCCR0 , 6);	
						  SET_BIT(TCCR0 , 3);
	   break;		    
	   				    
	   case Phase_PWM   : SET_BIT  (TCCR0 , 6);
	                      CLEAR_BIT(TCCR0 , 3);
	   break;					
	  	
	}
	
	// Set Prescaler Value
	
	TCCR0 &= TCCR0_MASK1 ; 
	TCCR0 |= Config_Timer0[0].TMR0_Prescaler ;
	
    // Set Timer0 Com Event	
	
	TCCR0 &= TCCR0_MASK2 ;
	TCCR0 |= Config_Timer0[0].TMR0_Com << 4  ;
	
	// Disable Interrupts
	CLEAR_BIT(TIMSK , 0);
	CLEAR_BIT(TIMSK , 1);
	// CLEAR FLAGS
	SET_BIT(TIFR , 0);
	SET_BIT(TIFR , 1);
	// Clear register
	TCNT0 = 0 ;
	OCR0 = 0 ;
	
	
}

/********************************************************************/
/* Description    :  This function used to write in TIMER0 register */
/*					 Inputs : u8 Copy_uint8Val   				    */
/*					 return : void		 						    */
/********************************************************************/

void TIMER0_void_SetTimerReg(u8 Copy_uint8Val)
{
	TCNT0 = Copy_uint8Val ;
}

/************************************************************************************/
/* Description    :  This function used to write in OCR register for compare match  */
/*					 Inputs : u8 Copy_uint8Val   				                    */
/*					 return : void		 						                    */
/************************************************************************************/

void TIMER0_void_SetCompareVal(u8 Copy_uint8Val)
{
	OCR0 = Copy_uint8Val ;
}

/*************************************************************************/
/* Description    :  This function used to Enable Over flow interrupt    */
/*					 Inputs : void 								         */
/*					 return : void		 						         */
/*************************************************************************/

void TIMER0_void_EnableOVInt(void)
{
	SET_BIT(TIMSK , 0);
}

/*************************************************************************/
/* Description    :  This function used to Disable Over flow interrupt   */
/*					 Inputs : void 								         */
/*					 return : void		 						         */
/*************************************************************************/

void TIMER0_void_DisableOVInt(void)
{
	CLEAR_BIT(TIMSK , 0);
}

/**************************************************************************/
/* Description    :  This function used to Enable Compare Match interrupt */
/*					 Inputs : void 								          */
/*					 return : void		 						          */
/**************************************************************************/

void TIMER0_void_EnableCTCInt(void)
{
	SET_BIT(TIMSK , 1);
}

/***************************************************************************/
/* Description    :  This function used to Disable Compare Match interrupt */
/*					 Inputs : void 								           */
/*					 return : void		 						           */
/***************************************************************************/

void TIMER0_void_DisableCTCInt(void)
{
	CLEAR_BIT(TIMSK , 1);
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



void TIMER0_void_SetOVCallBack(void (*Copy_ptr) (void) )
{
	TIMER0_OV_CallBack = Copy_ptr ;
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

void TIMER0_void_SetCTCCallBack(void (*Copy_ptr) (void) )
{
	TIMER0_CTC_CallBack = Copy_ptr ;
	
}


/** Linker Problem solved */


void __vector_11(void)
{
	
	TIMER0_OV_CallBack();
}


void __vector_10(void)
{
	
	TIMER0_CTC_CallBack();
}

/***********************************************************************************************/
/************************************* END OF PROGRAM ******************************************/
/***********************************************************************************************/
