/****************************************************************/
/*   Author             :    Gamal Ahmed Gamal 				    */
/*	 Date 				:    3 March 2023 						*/
/*	 Version 			:    1.0V 							 	*/
/*	 Description 		:    Configure UART [config.h]     	    */
/****************************************************************/

/****************************************************************/
/* Description   : Guard to protect this File from include more */
/*                 than one time .                              */
/****************************************************************/


#ifndef UART_CONFIG_H_
#define UART_CONFIG_H_


typedef enum{
Baudrate_1200   = 0x340  ,
Baudrate_2400   = 0x1A0  ,
Baudrate_4800   = 0xCF  ,
Baudrate_9600   = 0x67  ,
Baudrate_19200  = 0x51  ,
Baudrate_115200 = 0x8	

}UART_Baudrate;

typedef enum{
	No_Parity      ,
	Reserved       ,
	Even_Parity    ,
	Odd_parity   

}UART_Parity;

typedef enum{
	one_bit    ,
	two_bits   

}UART_StopBits;

typedef enum{
	five_bits       ,
	six_bits        ,
	seven_bits      ,
	eight_bits      ,
	nine_bits  = 7   

}UART_DataSize;


typedef struct {
	UART_Baudrate Baud_Rate ; 
	UART_Parity   Parity    ;
	UART_StopBits StopBits  ;
	UART_DataSize DataSize  ;
}UART_config;


UART_config Config_UART[1] ; 


#endif /* UART_CONFIG_H_ */