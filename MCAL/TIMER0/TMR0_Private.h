/****************************************************************/
/* 	Author 	 	 : Gamal Ahmed Gamal                            */
/* 	Date   		 : 25 Feb 2023	                                */
/* 	Version 	 : 1V 									        */
/*	 Description : contain the Memory mapped of		            */
/*				  [TIMSK,OCR0,TCCR0,TCNT0,TIFR] Registers       */
/****************************************************************/


/****************************************************************/
/* Description   : Guard to protect this File from include more */
/*                 than one time .                              */
/****************************************************************/

#ifndef _TIMER0_PRIV
#define _TIMER0_PRIV




#define TIMSK	 (*(volatile u8 * )0x59)
#define OCR0 	 (*(volatile u8 * )0x5C)
#define TCCR0	 (*(volatile u8 * )0x53)
#define TCNT0	 (*(volatile u8 * )0x52)
#define TIFR	 (*(volatile u8 * )0x58)






#endif

/***********************************************************************************************/
/************************************* END OF PROGRAM ******************************************/
/***********************************************************************************************/