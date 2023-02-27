/****************************************************************/
/*   Author             :    Gamal Ahmed Gamal 				    */
/*	 Date 				:    25 Feb 2023 						*/
/*	 Version 			:    1.0V 							 	*/
/*   Description	    :    prog.c for LED                     */
/****************************************************************/

#include "../HAL//LED/LED.h"
#include "../HAL//LED/LED_CFG.h"
#include "../MCAL/DIO/dio.h"

/****************************************************************/
/* Description    :  This function used to initialize LED       */
/*					 Inputs : void 								*/
/*					 return : void		 						*/
/****************************************************************/


void LED_INIT ( void ){
	
for(u8 i = 0 ; i < NUM_OF_LEDS ; i++ ){
 dio_vidConfigChannel(Config_LED[i].Port , Config_LED[i].Pin, OUTPUT);	
   }
	
}

/****************************************************************/
/* Description    :  This function used to Turn on LED          */
/*					 Inputs : LED_ID ledd 						*/
/*					 return : void		 						*/
/****************************************************************/


void LED_ON ( LED_ID ledd ){
	
	for(u8 i = 0 ; i < NUM_OF_LEDS ; i++){
		if(ledd == Config_LED[i].Num){	
		switch(Config_LED[i].State){
		  case SOURCE :  dio_vidWriteChannel(Config_LED[i].Port, Config_LED[i].Pin , STD_HIGH ); break ;
		  case SINK   :  dio_vidWriteChannel(Config_LED[i].Port, Config_LED[i].Pin , STD_LOW); break ;		
		   }
					
		}
			
	}
	
		
}

/****************************************************************/
/* Description    :  This function used to Turn off LED         */
/*					 Inputs : LED_ID ledd 						*/
/*					 return : void		 						*/
/****************************************************************/


void LED_OFF ( LED_ID ledd){
	
	for(u8 i = 0 ; i < NUM_OF_LEDS ; i++){
		if(ledd == Config_LED[i].Num){
			switch(Config_LED[i].State){
				case SOURCE :  dio_vidWriteChannel(Config_LED[i].Port, Config_LED[i].Pin , STD_LOW ); break ;
				case SINK   :  dio_vidWriteChannel(Config_LED[i].Port, Config_LED[i].Pin , STD_HIGH); break ;
			}
			
		}
		
	}

	
	
}

/****************************************************************/
/* Description    :  This function used to Toggle LED           */
/*					 Inputs : LED_ID ledd 						*/
/*					 return : void		 						*/
/****************************************************************/

void LED_TOGGLE ( LED_ID ledd){
	
		for(u8 i = 0 ; i < NUM_OF_LEDS ; i++){
			if(ledd == Config_LED[i].Num){
				
			dio_vidFlipChannel(Config_LED[i].Port , Config_LED[i].Pin);	
				
			}
			
		}
	
	
}


