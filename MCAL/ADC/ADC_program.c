/************************************************************/
/* 	Author 	 	 : Gamal Ahmed Gamal                        */
/* 	Date   		 : 25 Feb 2023	                            */
/* 	Version 	 : 1V 									    */
/* 	Description	 : prog.c for ADC		                    */
/************************************************************/

/****************************************************************/
/*********************** Macros *********************************/
/****************************************************************/
#define F_CPU        16000000UL
#define ADMUX1_MASK  0b00111111
#define ADMUX2_MASK  0b11011111
#define ADMUX3_MASK  0b11100000

#define ADCSRA1_MASK 0b11111000

#define SFIOR1_MASK  0b00011111
/****************************************************************/
/*********************** STD LIB DIRECTIVES *********************/
/****************************************************************/

#include "../LIB/std_types.h"
#include "../LIB/bit_math.h"
#include <util/delay.h>

/****************************************************************/
/*********************** Component DIRECTIVES *******************/
/****************************************************************/

#include "../MCAL/ADC/ADC_Interface.h"
#include "../MCAL/ADC/ADC_Config.h"
#include "../MCAL/ADC/ADC_Private.h"

/****************************************************************/
/*********************** Function Implementation  ***************/
/****************************************************************/

void (*Global_ADC) (void);


/****************************************************************/
/* Description    :  This function used to initialize ADC 	    */
/*					 Inputs : void 								*/
/*					 return : void		 						*/
/****************************************************************/

void ADC_voidInit (void)
{
	// Configure Voltage Reference 
	ADMUX &= ADMUX1_MASK ; 
	ADMUX |= (Config_ADC[0].V_Ref << 6 );
	
	// Configure Right / Left Adjustment
    ADMUX &= ADMUX2_MASK;
    ADMUX |=( ( Config_ADC[0].Adj )<< 5)  ;
    // Configure Prescaler
	ADCSRA &= ADCSRA1_MASK;
	ADCSRA |= Config_ADC[0].Prescaler ;
		
}


/****************************************************************/
/* Description    : This function used to Enable ADC			*/
/*																*/
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after ADC		*/
/*     				 initialized 							    */
/****************************************************************/

void ADC_voidEnable()
{
	
	SET_BIT( ADCSRA , 7 );
	
}

/****************************************************************/
/* Description    : This function used to Enable ADC Interrput	*/
/*																*/
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after ADC		*/
/*     				 initialized 							    */
/****************************************************************/

void ADC_voidInterrputEnable()
{
	
	SET_BIT( ADCSRA , 3 );

}


/****************************************************************/
/* Description    : This function used to Disable ADC			*/
/*																*/
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after ADC 		*/
/*     				 initialized 							    */
/****************************************************************/

void ADC_voidDisable()
{
	
	CLEAR_BIT( ADCSRA , 7 );
	
}


/****************************************************************/
/* Description    : This function used to Start converting		*/
/*																*/
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after ADC 		*/
/*     				 initialized 							    */
/****************************************************************/

void ADC_voidStartConversion()
{
	
	SET_BIT( ADCSRA , 6 );
	
}


/****************************************************************/
/* Description    : This function used to Set latch Interrupt	*/
/*									 happens.					*/
/*																*/
/*					Inputs : Config_ADC				  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after Interrupt */
/*     				 initialized 							    */
/****************************************************************/

void ADC_voidAutoTrigger()
{	
	/****************************************************************/
	/** !comment : From Data Sheet : Starting conversion on positive*/
	/*			   edge when ADATE = 1						    	*/
	/****************************************************************/

	/** Enable ADC Auto Trigger	 							   **/
	/** ADATE = 1 =====> 	SET_BIT( ADATE , 5 ); 			   **/

	 SET_BIT( ADCSRA , 5 );
     // Configure Auto Trigger Source 
     SFIOR &= SFIOR1_MASK ; 
     SFIOR |= Config_ADC[0].Trig_S ;
	
}


/****************************************************************/
/* Description    : This function used to Read ADC and 			*/
/*																*/
/*					Inputs : Channel you want to read from		*/
/*					Return : u16 Digital Converting milli Volt	*/
/****************************************************************/
/* Pre_condition  :  this function must be used after ADC 		*/
/*     				 initialized 							    */
/****************************************************************/

u16 ADC_u16ReadADCInMV(u8 channel )
{
	u16 ADCvalue = 0 ; 
	// Choose Channel from 0 to 7
	ADMUX &= ADMUX3_MASK ;
	ADMUX |= channel    ;
	// Start Convertion
	ADC_voidStartConversion();
	// wait for flag
	while((CHECK_BIT(ADCSRA, 4))==0); 
	_delay_us(10);
	
	if(Config_ADC[0].Adj == Right_Adjustment){
		
	 ADCvalue = ADC ;	
		
	}
	else if (Config_ADC[0].Adj == Left_Adjustment){
	
	ADCvalue = ADC >>6 ;	
		
	}
	
	return ADCvalue ;
	
	
}

/****************************************************************/
/* Description    : This function used to Read ADC and 			*/
/*																*/
/*					Inputs : Address of ISR function            */             
/*                             Channel you want to read from    */
/*					Return : void	                            */
/****************************************************************/
/* Pre_condition  :  this function must be used after ADC 		*/
/*     				 initialized 							    */
/****************************************************************/

void ADC_u8ReadADC(void (*addresscpy)(void) , u8 channel ){
	
	 	 ADMUX &= ADMUX3_MASK ;
	 	 ADMUX |= channel    ;  
	
     	Global_ADC = addresscpy ; 
	
	
}



void __vector_16(void)   // ADC ISR
{
	(*Global_ADC) ();
	
}

/***********************************************************************************************/
/************************************* END OF PROGRAM ******************************************/
/***********************************************************************************************/