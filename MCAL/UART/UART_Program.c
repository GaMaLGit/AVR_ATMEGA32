/****************************************************************/
/*   Author             :    Gamal Ahmed Gamal 				    */
/*	 Date 				:    3 March 2023 						*/
/*	 Version 			:    1.0V 							 	*/
/*   Description	    :    prog.c for UART                    */
/****************************************************************/

/****************************************************************/
/*********************** STD LIB DIRECTIVES *********************/
/****************************************************************/

#include "../LIB/std_types.h"
#include "../LIB/bit_math.h"


/****************************************************************/
/*********************** Component DIRECTIVES *******************/
/****************************************************************/

#include "../MCAL/UART/UART_Interface.h"
#include "../MCAL/UART/UART_Private.h"
#include "../MCAL/UART/UART_Config.h"

/****************************************************************/
/******************************* Macros *************************/
/****************************************************************/

#define  UCSRC_MASK1 0b11001111
#define  UCSRC_MASK2 0b11110111
#define  UCSRC_MASK3 0b11111001

/***********************************************************/
/**!comment   :  pointer to function for callback	       */
/***********************************************************/

void (*UART_RXComplete_CallBack) (void) ;
void (*UART_TXComplete_CallBack) (void) ;
void (*UART_DataRegEmpty_CallBack) (void) ;
/****************************************************************/
/* Description    :  This function used to initialize UART      */
/*					 Inputs : void 								*/
/*					 return : void		 						*/
/****************************************************************/

void UART_Init(void)
{
	/* Set baud rate */
	
	UART_UBRRL = (u8)Config_UART[0].Baud_Rate;
	UART_UBRRH = (u8)(Config_UART[0].Baud_Rate>>8);

	/* Enable receiver and transmitter */
	SET_BIT(UART_UCSRB,RXEN_BIT_NO);  /* Enable Receiver*/
	SET_BIT(UART_UCSRB,TXEN_BIT_NO);  /* Enable Transmitter */
	// Enable Select to write in UCSRC
	SET_BIT(UART_UCSRC,URSEL_BIT_NO);
	// Configure Parity bits
	UART_UCSRC &= UCSRC_MASK1 ;
	UART_UCSRC |= Config_UART[0].Parity<< 4 ;
	// Configure Stop Bits
	UART_UCSRC &= UCSRC_MASK2 ;
	UART_UCSRC |= Config_UART[0].StopBits<<3 ;
	// Configure Data Size
	UART_UCSRC &= UCSRC_MASK3 ;
	UART_UCSRC |= Config_UART[0].DataSize<<1 ;
	

	SET_BIT(UART_UCSRB,7); /*	Enable Rx Complete Interrupt	*/
	SET_BIT(UART_UCSRB,6); /*	Enable Tx Complete Interrupt	*/
}

/****************************************************************/
/* Description    :  This function used to Transmit Data        */
/*					 Inputs : u8 data 						    */
/*					 return : void		 						*/
/****************************************************************/

void UART_TransmitChr(u8 data)
{
	/* Put data into buffer*/
	while ( !( UART_UCSRA & (1<<UDRE_BIT_NO))) ;
	UART_UDR = data;
}

/****************************************************************/
/* Description    :  This function used to Receive Data         */
/*					 Inputs : void						        */
/*					 return : u8 UART_UDR		 			 	*/
/****************************************************************/
u8 UART_ReceiveChr(void)
{
	while ( !(UART_UCSRA & (1<<RXC_BIT_NO)) ) ;
	return UART_UDR;
}


void UART_VoidRXComplete_Callback(void (*AddresCpy)(void)){
	
	UART_RXComplete_CallBack = AddresCpy ;
	
}


void UART_VoidTXComplete_Callback(void (*AddresCpy)(void)){
	
	UART_TXComplete_CallBack = AddresCpy ;
	
}

void UART_DataRegEmpty_Callback(void(*AddresCpy)(void)){
	
	UART_DataRegEmpty_CallBack = AddresCpy ; 
	
}



/** Linker Problem solved */


void __vector_13(void)
{
	
	UART_RXComplete_CallBack();
	
}


void __vector_14(void)
{
	
	UART_DataRegEmpty_CallBack();
}

void __vector_15(void)
{
	
	UART_TXComplete_CallBack();
}