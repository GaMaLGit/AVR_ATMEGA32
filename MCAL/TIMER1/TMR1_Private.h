/****************************************************************/
/* 	Author 	 	 : Gamal Ahmed Gamal                            */
/* 	Date   		 : 2 March 2023	                                */
/* 	Version 	 : 1V 									        */
/*	 Description : contain the Memory mapped of		            */
/*				  [TIMSK,OCR0,TCCR0,TCNT0,TIFR] Registers       */
/****************************************************************/


/****************************************************************/
/* Description   : Guard to protect this File from include more */
/*                 than one time .                              */
/****************************************************************/

#ifndef TMR1_PRIVATE_H_
#define TMR1_PRIVATE_H_


#define TIMSK	 (*(volatile u8 * )0x59)
#define TIFR	 (*(volatile u8 * )0x58)
#define SFIOR	 (*(volatile u8 * )0x50)
#define TCCR1A	 (*(volatile u8 * )0x4F)
#define TCCR1B	 (*(volatile u8 * )0x4E)
#define TCNT1H	 (*(volatile u8 * )0x4D)
#define TCNT1L	 (*(volatile u8 * )0x4C)
#define OCR1AH	 (*(volatile u8 * )0x4B)
#define OCR1AL	 (*(volatile u8 * )0x4A)
#define OCR1BH	 (*(volatile u8 * )0x49)
#define OCR1BL	 (*(volatile u8 * )0x48)
#define ICR1H	 (*(volatile u8 * )0x47)
#define ICR1L	 (*(volatile u8 * )0x46)







#endif 

/***********************************************************************************************/
/************************************* END OF PROGRAM ******************************************/
/***********************************************************************************************/