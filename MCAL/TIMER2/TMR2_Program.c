/****************************************************************/
/*   Author             :    Gamal Ahmed Gamal 				    */
/*	 Date 				:    2 March 2023 						*/
/*	 Version 			:    1.0V 							 	*/
/*   Description	    :    prog.c for TIMER2                  */
/****************************************************************/

/****************************************************************/
/*********************** STD LIB DIRECTIVES *********************/
/****************************************************************/

#include "../LIB/std_types.h"
#include "../LIB/bit_math.h"


/****************************************************************/
/*********************** Component DIRECTIVES *******************/
/****************************************************************/

#include "../MCAL/TIMER2/TMR2_Interface.h"
#include "../MCAL/TIMER2/TMR2_Private.h"
#include "../MCAL/TIMER0/TMR0_Private.h"
#include "../MCAL/TIMER2/TMR2_Config.h"


/****************************************************************/
/******************************* Macros *************************/
/****************************************************************/

#define  TCCR2_MASK1 0b11111000
#define  TCCR2_MASK2 0b11001111


/***********************************************************/
/**!comment   :  pointer to function for callback	       */
/***********************************************************/

void (*TIMER2_OV_CallBack) (void) ;
void (*TIMER2_CTC_CallBack) (void) ;

/****************************************************************/
/* Description    :  This function used to initialize TIMER2    */
/*					 Inputs : void 								*/
/*					 return : void		 						*/
/****************************************************************/


void TIMER2_void_Init(void)
{
	
	// Set Timer2 Mode
	switch(Config_Timer2[0].TMR2_Mode){
		
		case Normal_Mode : CLEAR_BIT(TCCR2 , 6);
		                   CLEAR_BIT(TCCR2 , 3);
		break;
		
		case CTC         : CLEAR_BIT(TCCR2 , 6);
		                   SET_BIT  (TCCR2 , 3);
		break;
		
		case Fast_PWM    : SET_BIT(TCCR2 , 6);
		                   SET_BIT(TCCR2 , 3);
		break;
		
		case Phase_PWM   : SET_BIT  (TCCR2 , 6);
		                   CLEAR_BIT(TCCR2 , 3);
		break;
		
	}
	
	// Set Prescaler Value
	
	TCCR2 &= TCCR2_MASK1 ;
	TCCR2 |= Config_Timer2[0].TMR2_Prescaler ;
	
	// Set Timer0 Com Event
	
	TCCR2 &= TCCR2_MASK2 ;
	TCCR2 |= Config_Timer2[0].TMR2_Com << 4  ;
	
	// Disable Interrupts
	CLEAR_BIT(TIMSK , 6);
	CLEAR_BIT(TIMSK , 7);
	// CLEAR FLAGS
	SET_BIT(TIFR , 6);
	SET_BIT(TIFR , 7);
	// Clear register
	TCNT2 = 0 ;
	OCR2 = 0 ;
	
	
}

/********************************************************************/
/* Description    :  This function used to write in TIMER2 register */
/*					 Inputs : u8 Copy_uint8Val   				    */
/*					 return : void		 						    */
/********************************************************************/

void TIMER2_void_SetTimerReg(u8 Copy_uint8Val)
{
	TCNT2 = Copy_uint8Val ;
}

/************************************************************************************/
/* Description    :  This function used to write in OCR register for compare match  */
/*					 Inputs : u8 Copy_uint8Val   				                    */
/*					 return : void		 						                    */
/************************************************************************************/

void TIMER2_void_SetCompareVal(u8 Copy_uint8Val)
{
	OCR0 = Copy_uint8Val ;
}

/*************************************************************************/
/* Description    :  This function used to Enable Over flow interrupt    */
/*					 Inputs : void 								         */
/*					 return : void		 						         */
/*************************************************************************/

void TIMER2_void_EnableOVInt(void)
{
	SET_BIT(TIMSK , 6);
}

/*************************************************************************/
/* Description    :  This function used to Disable Over flow interrupt   */
/*					 Inputs : void 								         */
/*					 return : void		 						         */
/*************************************************************************/

void TIMER2_void_DisableOVInt(void)
{
	CLEAR_BIT(TIMSK , 6);
}

/**************************************************************************/
/* Description    :  This function used to Enable Compare Match interrupt */
/*					 Inputs : void 								          */
/*					 return : void		 						          */
/**************************************************************************/

void TIMER2_void_EnableCTCInt(void)
{
	SET_BIT(TIMSK , 7);
}

/***************************************************************************/
/* Description    :  This function used to Disable Compare Match interrupt */
/*					 Inputs : void 								           */
/*					 return : void		 						           */
/***************************************************************************/

void TIMER2_void_DisableCTCInt(void)
{
	CLEAR_BIT(TIMSK , 7);
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



void TIMER2_void_SetOVCallBack(void (*Copy_ptr) (void) )
{
	TIMER2_OV_CallBack = Copy_ptr ;
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

void TIMER2_void_SetCTCCallBack(void (*Copy_ptr) (void) )
{
	TIMER2_CTC_CallBack = Copy_ptr ;
	
}


/** Linker Problem solved */


void __vector_5(void)
{
	
	TIMER2_OV_CallBack();
}


void __vector_4(void)
{
	
	TIMER2_CTC_CallBack();
}

/***********************************************************************************************/
/************************************* END OF PROGRAM ******************************************/
/***********************************************************************************************/

