/****************************************************************/
/* 	Author 	 	 : Gamal Ahmed Gamal                            */
/* 	Date   		 : 2 March 2023	                                */
/* 	Version 	 : 1V 									        */
/*	 Description : contain the Memory mapped of		            */
/*				  [OCR2,TCCR2,TCNT2] Registers                  */
/****************************************************************/


/****************************************************************/
/* Description   : Guard to protect this File from include more */
/*                 than one time .                              */
/****************************************************************/

#ifndef TMR2_PRIVATE_H_
#define TMR2_PRIVATE_H_

#define TCCR2  (*(volatile u8 * )0x45) 
#define TCNT2  (*(volatile u8 * )0x44)
#define OCR2   (*(volatile u8 * )0x43)



void __vector_5(void) __attribute__((signal , used));
void __vector_4(void) __attribute__((signal , used));


#endif 

/***********************************************************************************************/
/************************************* END OF PROGRAM ******************************************/
/***********************************************************************************************/