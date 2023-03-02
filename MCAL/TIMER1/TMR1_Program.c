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

#include "../MCAL/TIMER1/TMR1_Interface.h"
#include "../MCAL/TIMER1/TMR1_Private.h"
#include "../MCAL/TIMER1/TMR1_Config.h"

/****************************************************************/
/******************************* Macros *************************/
/****************************************************************/

#define  TCCR1B_MASK1 0b11111000

/***********************************************************/
/**!comment   :  pointer to function for callback	       */
/***********************************************************/

void (*TIMER1_OV_CallBack)   (void) ;
void (*TIMER1_CTCB_CallBack) (void) ;
void (*TIMER1_CTCA_CallBack) (void) ;
void (*TIMER1_CAPT_CallBack) (void) ;

/****************************************************************/
/* Description    :  This function used to initialize TIMER1    */
/*					 Inputs : void 								*/
/*					 return : void		 						*/
/****************************************************************/

void TIMER1_void_Init(void)
{
	// Set Timer1 Mode
	switch(Config_Timer1[0].TMR1_Mode){
		
		case Normal_Mode :  CLEAR_BIT(TCCR1A , 0);
		CLEAR_BIT(TCCR1A , 1);
		CLEAR_BIT(TCCR1B , 3);
		CLEAR_BIT(TCCR1B , 4);
		break ;
		
		case Phase_PWM_8 :  SET_BIT(TCCR1A , 0);
		CLEAR_BIT(TCCR1A , 1);
		CLEAR_BIT(TCCR1B , 3);
		CLEAR_BIT(TCCR1B , 4);
		break ;
		
		case Phase_PWM_9 :  CLEAR_BIT(TCCR1A , 0);
		SET_BIT(TCCR1A , 1);
		CLEAR_BIT(TCCR1B , 3);
		CLEAR_BIT(TCCR1B , 4);
		break;
		
		case Phase_PWM_10 : SET_BIT(TCCR1A , 0);
		SET_BIT(TCCR1A , 1);
		CLEAR_BIT(TCCR1B , 3);
		CLEAR_BIT(TCCR1B , 4);
		break ;
		
		case CTC :         	CLEAR_BIT(TCCR1A , 0);
		CLEAR_BIT(TCCR1A , 1);
		SET_BIT(TCCR1B , 3);
		CLEAR_BIT(TCCR1B , 4);
		break ;
		
		case Fast_PWM_8 : 	SET_BIT(TCCR1A , 0);
		CLEAR_BIT(TCCR1A , 1);
		SET_BIT(TCCR1B , 3);
		CLEAR_BIT(TCCR1B , 4);
		break ;
		
		case Fast_PWM_9 :  	CLEAR_BIT(TCCR1A , 0);
		SET_BIT(TCCR1A , 1);
		SET_BIT(TCCR1B , 3);
		CLEAR_BIT(TCCR1B , 4);
		break ;
		
		case Fast_PWM_10 : 	SET_BIT(TCCR1A , 0);
		SET_BIT(TCCR1A , 1);
		SET_BIT(TCCR1B , 3);
		CLEAR_BIT(TCCR1B , 4);
		break ;
		
		case PWM_PF_ICR  : 	CLEAR_BIT(TCCR1A , 0);
		CLEAR_BIT(TCCR1A , 1);
		CLEAR_BIT(TCCR1B , 3);
		SET_BIT(TCCR1B , 4);
		break ;
		
		case PWM_PF_OCR  :  CLEAR_BIT(TCCR1A , 0);
		CLEAR_BIT(TCCR1A , 1);
		CLEAR_BIT(TCCR1B , 3);
		SET_BIT(TCCR1B , 4);
		break ;
		
		case PWM_P_ICR :   	CLEAR_BIT(TCCR1A , 0);
		SET_BIT(TCCR1A , 1);
		CLEAR_BIT(TCCR1B , 3);
		SET_BIT(TCCR1B , 4);
		break ;
		
		case PWM_P_OCR :   	SET_BIT(TCCR1A , 0);
		SET_BIT(TCCR1A , 1);
		CLEAR_BIT(TCCR1B , 3);
		SET_BIT(TCCR1B , 4);
		break ;
		
		case CTC_ICR   :   	CLEAR_BIT(TCCR1A , 0);
		CLEAR_BIT(TCCR1A , 1);
		SET_BIT(TCCR1B , 3);
		SET_BIT(TCCR1B , 4);
		break ;
		
		case FPWM_ICR  :    CLEAR_BIT(TCCR1A , 0);
		SET_BIT(TCCR1A , 1);
		SET_BIT(TCCR1B , 3);
		SET_BIT(TCCR1B , 4);
		break ;
		
		case FPWM_OCR  :   	SET_BIT(TCCR1A , 0);
		SET_BIT(TCCR1A , 1);
		SET_BIT(TCCR1B , 3);
		SET_BIT(TCCR1B , 4);
		break ;
	}
	
	// Set Prescaler Value
	
	TCCR1B &= TCCR1B_MASK1 ;
	TCCR1B |= Config_Timer1[0].TMR1_Prescaler ;
	
	

	switch(Config_Timer1[0].TMR1_Com_A){
		
		case Normal_com : 	CLEAR_BIT(TCCR1A , 4);
		                    CLEAR_BIT(TCCR1A , 5);
		                    CLEAR_BIT(TCCR1A , 6);
		                    CLEAR_BIT(TCCR1A , 7);
		break ;
		
		case Toggle  :     	CLEAR_BIT(TCCR1A , 4);
		                    CLEAR_BIT(TCCR1A , 5);
		                    SET_BIT(TCCR1A , 6);
		                    CLEAR_BIT(TCCR1A , 7);
		break ;
		
		case Clear   :      CLEAR_BIT(TCCR1A , 4);
		                    CLEAR_BIT(TCCR1A , 5);
		                    CLEAR_BIT(TCCR1A , 6);
		                    SET_BIT(TCCR1A , 7);
		break ;
		
		case Set     :      CLEAR_BIT(TCCR1A , 4);
		                    CLEAR_BIT(TCCR1A , 5);
		                    SET_BIT(TCCR1A , 6);
		                    SET_BIT(TCCR1A , 7);
		break ;
		
		
	}

	switch(Config_Timer1[0].TMR1_Com_B){
		
		case Normal_com : 	CLEAR_BIT(TCCR1A , 4);
		                    CLEAR_BIT(TCCR1A , 5);
		                    CLEAR_BIT(TCCR1A , 6);
		                    CLEAR_BIT(TCCR1A , 7);
		break ;
		
		case Toggle  :     SET_BIT(TCCR1A , 4);
		                   CLEAR_BIT(TCCR1A , 5);
		                   CLEAR_BIT(TCCR1A , 6);
		                   CLEAR_BIT(TCCR1A , 7);
		break ;
		
		case Clear   :     CLEAR_BIT(TCCR1A , 4);
		                   SET_BIT(TCCR1A , 5);
		                   CLEAR_BIT(TCCR1A , 6);
		                   CLEAR_BIT(TCCR1A , 7);
		break ;
		
		case Set     :     SET_BIT(TCCR1A , 4);
		                   SET_BIT(TCCR1A , 5);
		                   CLEAR_BIT(TCCR1A , 6);
		                   CLEAR_BIT(TCCR1A , 7);
		break ;
		
		
	}

	

	/*Disable Interrupts*/
	CLEAR_BIT(TIMSK , 2);
	CLEAR_BIT(TIMSK , 3);
	CLEAR_BIT(TIMSK , 4);
	CLEAR_BIT(TIMSK , 5);
	/*CLEAR FLAGS*/
	SET_BIT(TIFR , 2);
	SET_BIT(TIFR , 3);
	SET_BIT(TIFR , 4);
	SET_BIT(TIFR , 5);
	/*Clear register*/
	TCNT1L = 0 ;
	TCNT1H = 0 ;
	OCR1AH = 0 ;
	OCR1AL = 0 ;
	OCR1BH = 0 ;
	OCR1BL = 0 ;
	
	
}

/********************************************************************/
/* Description    :  This function used to write in TIMER1 register */
/*					 Inputs : void              				    */
/*					 return : u16 		 						    */
/********************************************************************/

u16 TIMER1_GetTimerReg(void){ //for counter
	return TCNT1L;
}

/********************************************************************/
/* Description    :  This function used to write in TIMER1 register */
/*					 Inputs : void              				    */
/*					 return : u16 		 						    */
/********************************************************************/

u16 TIMER1_GetTimerRegICR(void){
	return ICR1L;
}

/********************************************************************/
/* Description    :  This function used to write in TIMER1 register */
/*					 Inputs : u16 Copy_uint8Val  				    */
/*					 return : void		 						    */
/********************************************************************/

void TIMER1_void_SetTimerReg(u16 Copy_uint8Val)
{
	TCNT1L = Copy_uint8Val ;
}

/********************************************************************/
/* Description    :  This function used to write in TIMER1 register */
/*					 Inputs : u16 Copy_uint8Val  				    */
/*					 return : void		 						    */
/********************************************************************/

void TIMER1_void_SetCompareValA(u16 Copy_uint8Val)
{
	OCR1AL = Copy_uint8Val ;
}

/********************************************************************/
/* Description    :  This function used to write in TIMER1 register */
/*					 Inputs : u16 Copy_uint8Val  				    */
/*					 return : void		 						    */
/********************************************************************/

void TIMER1_void_SetCompareValB(u16 Copy_uint8Val)
{
	OCR1BL = Copy_uint8Val ;
}

/*************************************************************************/
/* Description    :  This function used to Enable Over flow interrupt    */
/*					 Inputs : void 								         */
/*					 return : void		 						         */
/*************************************************************************/

void TIMER1_void_EnableOVInt(void)
{
	SET_BIT(TIMSK , 2);
}

/*************************************************************************/
/* Description    :  This function used to Disable Over flow interrupt   */
/*					 Inputs : void 								         */
/*					 return : void		 						         */
/*************************************************************************/

void TIMER1_void_DisableOVInt(void)
{
	CLEAR_BIT(TIMSK , 2);
}

/*****************************************************************************/
/* Description    :  This function used to Enable Compare Match A interrupt  */
/*					 Inputs : void 								             */
/*					 return : void		 						             */
/*****************************************************************************/

void TIMER1_void_EnableCTCAInt(void)
{
	SET_BIT(TIMSK , 4);
}

/*****************************************************************************/
/* Description    :  This function used to Disable Compare Match A interrupt */
/*					 Inputs : void 								             */
/*					 return : void		 						             */
/*****************************************************************************/

void TIMER1_void_DisableCTCAInt(void)
{
	CLEAR_BIT(TIMSK , 4);
}

/*****************************************************************************/
/* Description    :  This function used to Enable Compare Match B interrupt  */
/*					 Inputs : void 								             */
/*					 return : void		 						             */
/*****************************************************************************/

void TIMER1_void_EnableCTCBInt(void)
{
	SET_BIT(TIMSK , 3);
}

/*****************************************************************************/
/* Description    :  This function used to Disable Compare Match B interrupt */
/*					 Inputs : void 								             */
/*					 return : void		 						             */
/*****************************************************************************/

void TIMER1_void_DisableCTCBInt(void)
{
	CLEAR_BIT(TIMSK , 3);
}

/*****************************************************************************/
/* Description    :  This function used to Enable Capture interrupt          */
/*					 Inputs : void 								             */
/*					 return : void		 						             */
/*****************************************************************************/

void TIMER1_void_EnableCAPTInt(void)
{
	SET_BIT(TIMSK , 5);
}

/*****************************************************************************/
/* Description    :  This function used to Disable Capture interrupt          */
/*					 Inputs : void 								             */
/*					 return : void		 						             */
/*****************************************************************************/

void TIMER1_void_DisableCAPTInt(void)
{
	CLEAR_BIT(TIMSK , 5);
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

void TIMER1_void_SetOVCallBack(void (*Copy_ptr) (void) )
{
	TIMER1_OV_CallBack = Copy_ptr ;
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

void TIMER1_void_SetCTCACallBack(void (*Copy_ptr) (void) )
{
	TIMER1_CTCA_CallBack = Copy_ptr ;
	
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

void TIMER1_void_SetCTCBCallBack(void (*Copy_ptr) (void) )
{
	TIMER1_CTCB_CallBack = Copy_ptr ;
	
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

void TIMER1_void_SetCAPTCallBack(void (*Copy_ptr) (void) )
{
	TIMER1_CAPT_CallBack = Copy_ptr ;
	
}


/** Linker Problem solved */

void __vector_6(void) __attribute__((signal , used));
void __vector_6(void)
{
	
	TIMER1_CAPT_CallBack();
}

void __vector_7(void) __attribute__((signal , used));
void __vector_7(void)
{
	
	TIMER1_CTCA_CallBack();
}

void __vector_8(void) __attribute__((signal , used));
void __vector_8(void)
{
	
	TIMER1_CTCB_CallBack();
}

void __vector_9(void) __attribute__((signal , used));
void __vector_9(void)
{
	
	TIMER1_OV_CallBack();
}


/***********************************************************************************************/
/************************************* END OF PROGRAM ******************************************/
/***********************************************************************************************/




