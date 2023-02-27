/****************************************************************/
/*   Author             :    Gamal Ahmed Gamal 				    */
/*	 Date 				:    25 Feb 2023 						*/
/*	 Version 			:    1.0V 							 	*/
/*   Description	    :    prog.c for SSD	                    */
/****************************************************************/

#include "../HAL//SSD/SSD.h"
#include "../HAL//SSD/SSD_CFG.h"
#include "../MCAL/DIO/dio.h"
#include "../LIB/bit_math.h"
#include "../LIB/std_types.h"
#include <util/delay.h>

void SSD_VidInit (void){
	
  //Configure Output pins for BCD decoder	
   dio_vidConfigChannel(Config_SSD->BCD_PORT , Config_SSD->BCD_PIN1, OUTPUT);		
   dio_vidConfigChannel(Config_SSD->BCD_PORT , Config_SSD->BCD_PIN2, OUTPUT);
   dio_vidConfigChannel(Config_SSD->BCD_PORT , Config_SSD->BCD_PIN4, OUTPUT);
   dio_vidConfigChannel(Config_SSD->BCD_PORT , Config_SSD->BCD_PIN8, OUTPUT);	
   //Configure Output pins for Multiplexing
   dio_vidConfigChannel(Config_SSD->MX_PORT1 , Config_SSD->COM4, OUTPUT);
   dio_vidConfigChannel(Config_SSD->MX_PORT1 , Config_SSD->COM3, OUTPUT);
   dio_vidConfigChannel(Config_SSD->MX_PORT2 , Config_SSD->COM2, OUTPUT);
   dio_vidConfigChannel(Config_SSD->MX_PORT2 , Config_SSD->COM1, OUTPUT);
   
   //Reset all pins
   
   dio_vidWriteChannel(Config_SSD->BCD_PORT,  Config_SSD->BCD_PIN1 , STD_LOW);
   dio_vidWriteChannel(Config_SSD->BCD_PORT,  Config_SSD->BCD_PIN2 , STD_LOW);
   dio_vidWriteChannel(Config_SSD->BCD_PORT,  Config_SSD->BCD_PIN4 , STD_LOW);
   dio_vidWriteChannel(Config_SSD->BCD_PORT,  Config_SSD->BCD_PIN8 , STD_LOW);
   dio_vidWriteChannel(Config_SSD->MX_PORT1 , Config_SSD->COM4 , STD_HIGH);
   dio_vidWriteChannel(Config_SSD->MX_PORT1 , Config_SSD->COM3 , STD_HIGH);
   dio_vidWriteChannel(Config_SSD->MX_PORT2 , Config_SSD->COM2 , STD_HIGH);
   dio_vidWriteChannel(Config_SSD->MX_PORT2 , Config_SSD->COM1 , STD_HIGH);	
	
}



void SSD_DisplayNum(u8 Num , u8 Digit){
	
	
	switch(Digit){
		case 1 :  dio_vidWriteChannel(Config_SSD->MX_PORT2 , Config_SSD->COM1 , STD_LOW);	break ;
		case 2 :  dio_vidWriteChannel(Config_SSD->MX_PORT2 , Config_SSD->COM2 , STD_LOW);	break ;
		case 3 :  dio_vidWriteChannel(Config_SSD->MX_PORT1 , Config_SSD->COM3 , STD_LOW);	break ;
		case 4 :  dio_vidWriteChannel(Config_SSD->MX_PORT1 , Config_SSD->COM4 , STD_LOW);	break ;
	}
	
	
	
	dio_vidWriteChannel(Config_SSD->BCD_PORT,  Config_SSD->BCD_PIN1 , CHECK_BIT(Num , 0 ));
	dio_vidWriteChannel(Config_SSD->BCD_PORT,  Config_SSD->BCD_PIN2 , CHECK_BIT(Num , 1 ));
	dio_vidWriteChannel(Config_SSD->BCD_PORT,  Config_SSD->BCD_PIN4 , CHECK_BIT(Num , 2 ));
	dio_vidWriteChannel(Config_SSD->BCD_PORT,  Config_SSD->BCD_PIN8 , CHECK_BIT(Num , 3 ));
	
	     _delay_ms(1);
		switch(Digit){
			case 1 :  dio_vidWriteChannel(Config_SSD->MX_PORT2 , Config_SSD->COM1 , STD_HIGH);	break ;
			case 2 :  dio_vidWriteChannel(Config_SSD->MX_PORT2 , Config_SSD->COM2 , STD_HIGH);	break ;
			case 3 :  dio_vidWriteChannel(Config_SSD->MX_PORT1 , Config_SSD->COM3 , STD_HIGH);	break ;
			case 4 :  dio_vidWriteChannel(Config_SSD->MX_PORT1 , Config_SSD->COM4 , STD_HIGH);	break ;
		}
	
	
	
}



