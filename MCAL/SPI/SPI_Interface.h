/****************************************************************/
/*   Author             :    Gamal Ahmed Gamal 				    */
/*	 Date 				:    4 March 2023 						*/
/*	 Version 			:    1.0V 							 	*/
/*	 Description        : public Accessing mechanism prototype  */
/****************************************************************/

/****************************************************************/
/* Description   : Guard to protect this File from include more */
/*                 than one time .                              */
/****************************************************************/

#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_

void SPI_Init(void);

void SPI_Interrupt_Enable(void);
void SPI_Interrupt_Disable(void);

void SPI_Send_Byte(u8 Byte);
u8 SPI_Receive_Byte(void);
u8 SPI_Tranfere_Byte(u8 Byte);

void SPI_Transmition_Callback(void (*AddresCpy)(void));

void __vector_12(void) __attribute__((signal , used));


#endif /* SPI_INTERFACE_H_ */