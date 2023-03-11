/****************************************************************/
/*   Author             :    Gamal Ahmed Gamal 				    */
/*	 Date 				:    3 March 2023 						*/
/*	 Version 			:    1.0V 							 	*/
/*	 Description        : public Accessing mechanism prototype  */
/****************************************************************/

/****************************************************************/
/* Description   : Guard to protect this File from include more */
/*                 than one time .                              */
/****************************************************************/


#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_

void UART_Init(void);

void UART_TransmitChr(u8 data);

u8 UART_ReceiveChr(void);

void UART_VoidRXComplete_Callback(void (*AddresCpy)(void));
void UART_VoidTXComplete_Callback(void (*AddresCpy)(void));
void UART_DataRegEmpty_Callback(void(*AddresCpy)(void));

void __vector_13(void) __attribute__((signal , used));
void __vector_14(void) __attribute__((signal , used));
void __vector_15(void) __attribute__((signal , used));

#endif /* UART_INTERFACE_H_ */