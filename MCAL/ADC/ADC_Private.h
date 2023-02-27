/****************************************************************/
/* 	Author 	 	 : Gamal Ahmed Gamal                            */
/* 	Date   		 : 25 Feb 2023	                                */
/* 	Version 	 : 1V 									        */
/*	 Description : contain the Memory mapped of		            */
/*				   ADC Registers                                */
/****************************************************************/


/****************************************************************/
/* Description   : Guard to protect this File from include more */
/*                 than one time .                              */
/****************************************************************/

#ifndef _ADC_PRIV_H
#define _ADC_PRIV_H


/****************************************************************/
/** !comment : From Data Sheet :  Memory mapped of ADCSRA    	*/
/**			   Register	is  0X26						    	*/
/****************************************************************/
/**			   ADCSRA : MCU Control Register contains control	*/
/** 		   bits for interrupt sense control and general 	*/
/**            MCU functions.							    	*/
/****************************************************************/

#define ADCSRA		(*((volatile u8 * ) (0X26)))

/****************************************************************/
/** !comment : From Data Sheet :  Memory mapped of MCUCSR   	*/
/**			   Register	is  0X54.								*/
/****************************************************************/
/**			   MCUCSR : MCU Control and Status Register			*/
/****************************************************************/

#define ADMUX       (*((volatile u8 * ) (0X27)))

/****************************************************************/
/** !comment : From Data Sheet :  Memory mapped of GICR     	*/
/**			   Register	is  0X5B.								*/
/****************************************************************/
/**			   GICR : General Interrupt Control Register		*/
/****************************************************************/

#define ADCL        *((volatile u8 * ) (0X24))

#define ADC         *((volatile u16 *) (0X24))

/****************************************************************/
/** !comment : From Data Sheet :  Memory mapped of GIFR     	*/
/**			   Register	is  0X5A.						    	*/
/****************************************************************/
/**			   GIFR : General Interrupt Flag Register			*/
/****************************************************************/

#define ADCH        *((volatile u8 * ) (0X25))

#define SFIOR       *((volatile u8 * ) (0X50))


/** Linker Problem solved */
void __vector_16(void) __attribute__(( signal , used ));


#endif	/**!comment : End of the guard [_ADC_PRIV_H]		   **/