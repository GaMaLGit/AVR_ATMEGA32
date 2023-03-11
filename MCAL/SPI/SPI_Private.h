/****************************************************************/
/* 	Author 	 	 : Gamal Ahmed Gamal                            */
/* 	Date   		 : 4 March 2023	                                */
/* 	Version 	 : 1V 									        */
/*	 Description : contain the Memory mapped of SPI Registers	*/
/****************************************************************/


/****************************************************************/
/* Description   : Guard to protect this File from include more */
/*                 than one time .                              */
/****************************************************************/


#ifndef SPI_PRIVATE_H_
#define SPI_PRIVATE_H_

#define SPDR (*(volatile u8 *) 0x2F )  
#define SPSR (*(volatile u8 *) 0x2E ) 
#define SPCR (*(volatile u8 *) 0x2D )





#endif /* SPI_PRIVATE_H_ */