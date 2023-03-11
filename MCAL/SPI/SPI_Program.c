/****************************************************************/
/*   Author             :    Gamal Ahmed Gamal 				    */
/*	 Date 				:    4 March 2023 						*/
/*	 Version 			:    1.0V 							 	*/
/*   Description	    :    prog.c for SPI                     */
/****************************************************************/

/****************************************************************/
/*********************** STD LIB DIRECTIVES *********************/
/****************************************************************/

#include "../LIB/std_types.h"
#include "../LIB/bit_math.h"


/****************************************************************/
/*********************** Component DIRECTIVES *******************/
/****************************************************************/

#include "../MCAL/SPI/SPI_Interface.h"
#include "../MCAL/SPI/SPI_Private.h"
#include "../MCAL/SPI/SPI_Config.h"
#include "../MCAL/DIO/dio.h"

/****************************************************************/
/******************************* Macros *************************/
/****************************************************************/

#define  SPCR_MASK1 0b11011111
#define  SPCR_MASK2 0b11111011
#define  SPCR_MASK3 0b11110111
#define  SPCR_MASK4 0b11111100

/***********************************************************/
/**!comment   :  pointer to function for callback	       */
/***********************************************************/

void (*SPI_TransmitionComplete_CallBack) (void);

/****************************************************************/
/* Description    :  This function used to initialize SPI      */
/*					 Inputs : void 								*/
/*					 return : void		 						*/
/****************************************************************/


void SPI_Init(void){
	
	switch(Config_SPI[0].M_S_Select){
		
		case Master_SPI : SET_BIT(SPCR , 4) ;
		dio_vidConfigChannel(DIO_PORTB , DIO_PIN5, OUTPUT);  //MOSI Output
		dio_vidConfigChannel(DIO_PORTB , DIO_PIN6, INPUT);   //MISO Input
		dio_vidConfigChannel(DIO_PORTB , DIO_PIN7, OUTPUT);  //CLK Output
		
		break;
		
		case Slave_SPI  : CLEAR_BIT(SPCR,4) ;
		dio_vidConfigChannel(DIO_PORTB , DIO_PIN4, INPUT);  //Slave Select Input
		dio_vidConfigChannel(DIO_PORTB , DIO_PIN5, INPUT);  //MOSI Input
		dio_vidConfigChannel(DIO_PORTB , DIO_PIN6, OUTPUT); //MISO Output
		dio_vidConfigChannel(DIO_PORTB , DIO_PIN7, INPUT);  //CLK Input
		
		break;
		
	}
	// Enable SPI
	SET_BIT(SPCR , 6) ;
	// Configure Clock Rate
	SPCR &= SPCR_MASK4 ;
	SPCR |= Config_SPI[0].CLK_Rate ;
	CLEAR_BIT(SPSR,0);	
	// Configure Data Order
	SPCR &= SPCR_MASK1 ;
	SPCR |= Config_SPI[0].SPI_Data_Order << 5 ;
	// Configure Clock Phase
	SPCR &= SPCR_MASK2 ;
	SPCR |= Config_SPI[0].CLK_Phase << 2 ;
	// Configure Clock Polarity
	SPCR &= SPCR_MASK3 ;
	SPCR |= Config_SPI[0].CLK_Polarity << 3 ;



	


	
}


void SPI_Interrupt_Enable(void){
	//Interrupt Enable
	SET_BIT(SPCR , 7);
}

void SPI_Interrupt_Disable(void){
	//Interrupt Disable
	CLEAR_BIT(SPCR , 7);
}


/****************************************************************/
/* Description    :  This function used to Transmit Data        */
/*					 Inputs : u8 data 						    */
/*					 return : void		 						*/
/****************************************************************/

void SPI_Send_Byte(u8 Byte){
	
	SPDR = Byte ;
	while(!CHECK_BIT(SPSR,7));  //Wait for transmition complete
	
}

/***********************************************************************/
/* Description    :  This function used to Transmit and Receive Data   */
/*					 Inputs : u8 data 						           */
/*					 return : void		 						       */
/***********************************************************************/

u8 SPI_Tranfere_Byte(u8 Byte){
	
	SPDR = Byte ;
	while(CHECK_BIT(SPSR,7) == 0 );  //Wait for transmition complete
	
	return SPDR ;
	
	
}


/****************************************************************/
/* Description    :  This function used to Receive Data         */
/*					 Inputs : void						        */
/*					 return : u8 UART_UDR		 			 	*/
/****************************************************************/

u8 SPI_Receive_Byte(void){
	
	while(!CHECK_BIT(SPSR,7));  //Wait for transmition complete
	
	return SPDR ;
	
}


void SPI_Transmition_Callback(void (*AddresCpy)(void)){
	
	SPI_TransmitionComplete_CallBack = AddresCpy ;
	
}

/** Linker Problem solved */

void __vector_12(void)
{
	
	SPI_TransmitionComplete_CallBack();
	
}