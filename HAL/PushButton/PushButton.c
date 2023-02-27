/****************************************************************/
/*   Author             :    Gamal Ahmed Gamal 				    */
/*	 Date 				:    25 Feb 2023 						*/
/*	 Version 			:    1.0V 							 	*/
/*   Description	    :    prog.c for Push Buttons	        */
/****************************************************************/


#include "../HAL/PushButton/PushButton.h"
#include "../HAL/PushButton/PushButtonCFG.h"
#include "../MCAL/DIO/dio.h"


/****************************************************************/
/* Description    :  initiate buttons                           */
/*					 Inputs : void 								*/
/*					 return : void		 						*/
/****************************************************************/

void button_init (void){
	
for( volatile u8 i = 0 ; i < NUM_OF_Buttons ; i ++ ){
		
 dio_vidConfigChannel( Config[i].Port , Config[i].Pin, INPUT);
	
}
	
}

/****************************************************************/
/* Description    :  Get button status                          */
/*					 Inputs : button_id   button number  		*/
/*					 return : button_id_t  Pressed              */
/*                                         Released			    */
/****************************************************************/


button_id_t button_get_status(BUTTON_ID button_id){
	


for(volatile u8 i = 0 ; i < NUM_OF_Buttons ; i ++ ){
	

if(button_id == Config[i].Num  ){
	
switch(Config[i].state) {
	case PULL_DOWN :
		if(dio_dioLevelReadChannel(Config[i].Port,Config[i].Pin)){
			
			return PRESSED ;
		}
		else{
			
			return RELEASED ;
			
		}
		break ;
		
	case PULL_UP :
	
		if(!dio_dioLevelReadChannel(Config[i].Port,Config[i].Pin)){
			
			return PRESSED ;
		}
		else{
			
			return RELEASED ;
			
		}
		break ;	
}

	
}
	

}
	
	  return RELEASED ;
	
	}

/***********************************************************************************************/
/************************************* END OF PROGRAM ******************************************/
/***********************************************************************************************/