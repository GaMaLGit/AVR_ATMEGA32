/****************************************************************/
/* 	Author 	 	 : Gamal Ahmed Gamal                            */
/* 	Date   		 : 25 Feb 2023	                                */
/* 	Version 	 : 1V 									        */
/*	 Description : contain the Memory mapped of		            */
/*				   [SREG] Registers                             */
/****************************************************************/

/****************************************************************/
/* Description   : Guard to protect this File from include more */
/*                 than one time .                              */
/****************************************************************/

#ifndef GIE_PRIVATE_H_
#define GIE_PRIVATE_H_

/****************************************************************/
/** !comment : From Data Sheet :  Memory mapped of SREG     	*/
/**			   Register	is  0X5F.						    	*/
/****************************************************************/
/**			   SREG : Status Register		                	*/
/****************************************************************/

#define SREG        *((volatile u8 * ) (0X5F))



#endif /** !comment  :  End of guard                          **/