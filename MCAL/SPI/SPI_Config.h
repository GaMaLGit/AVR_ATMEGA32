/****************************************************************/
/*   Author             :    Gamal Ahmed Gamal 				    */
/*	 Date 				:    4 March 2023 						*/
/*	 Version 			:    1.0V 							 	*/
/*	 Description 		:    Configure SPI [config.h]     	    */
/****************************************************************/

/****************************************************************/
/* Description   : Guard to protect this File from include more */
/*                 than one time .                              */
/****************************************************************/


#ifndef SPI_CONFIG_H_
#define SPI_CONFIG_H_


typedef enum {
MSB ,
LSB		
}Data_Order ;

typedef enum {
Master_SPI ,
Slave_SPI	
}MasterSlave_Select;

typedef enum {
Rising_SPI ,
Falling_SPI	
}Clock_Polarity;

typedef enum {
	Sample_SPI ,
	Setup_SPI
}Clock_Phase;

typedef enum {
	FOSC_div4 ,
	FOSC_div16 ,
	FOSC_div64 ,
	FOSC_div128 ,
	FOSC_div2 ,
	FOSC_div8 ,
	FOSC_div32 ,
	FOSC_div64_2
}Clock_Rate;

typedef struct {

Data_Order           SPI_Data_Order ;	
MasterSlave_Select	 M_S_Select     ;
Clock_Polarity       CLK_Polarity   ;
Clock_Phase          CLK_Phase      ;
Clock_Rate           CLK_Rate       ;
	
}SPI_Config;


SPI_Config Config_SPI[1] ; 




#endif /* SPI_CONFIG_H_ */