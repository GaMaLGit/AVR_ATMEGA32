/****************************************************************/
/*   Author             :    Gamal Ahmed Gamal 				    */
/*	 Date 				:    10 March 2023 						*/
/*	 Version 			:    1.0V 							 	*/
/*	 Description        : public Accessing mechanism prototype  */
/****************************************************************/

/****************************************************************/
/* Description   : Guard to protect this File from include more */
/*                 than one time .                              */
/****************************************************************/

#ifndef EEPROM_INTERFACE_H_
#define EEPROM_INTERFACE_H_

void EEPROM_VoidWrite(u16 u16Address, u8 u8Data);

u8 EEPROM_read(u16 u16Address);



#endif /* EEPROM_INTERFACE_H_ */