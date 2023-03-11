/****************************************************************/
/* 	Author 	 	 : Gamal Ahmed Gamal                            */
/* 	Date   		 : 10 March 2023	                            */
/* 	Version 	 : 1V 									        */
/*	 Description : contain the Memory mapped of EEPROM Register */
/****************************************************************/


/****************************************************************/
/* Description   : Guard to protect this File from include more */
/*                 than one time .                              */
/****************************************************************/


#ifndef EEPROM_PRIVATE_H_
#define EEPROM_PRIVATE_H_

#define EEAR  (*(volatile u16 *) 0x3E )
#define EEARL (*(volatile u8  *) 0x3E )
#define EEARH (*(volatile u8  *) 0x3F )
#define EEDR  (*(volatile u8  *) 0x3D )
#define EECR  (*(volatile u8  *) 0x3C )


//Bits MACROS

#define EERE   0 
#define EEWE   1
#define EEMWE  2
#define EERIE  3










#endif /* EEPROM_PRIVATE_H_ */