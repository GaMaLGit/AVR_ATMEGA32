/****************************************************************/
/*   Author             :    Gamal Ahmed Gamal 				    */
/*	 Date 				:    2 March 2023 						*/
/*	 Version 			:    1.0V 							 	*/
/*	 Description : public Accessing mechanism prototype         */
/****************************************************************/

/****************************************************************/
/* Description   : Guard to protect this File from include more */
/*                 than one time .                              */
/****************************************************************/


#ifndef TMR2_INTERFACE_H_
#define TMR2_INTERFACE_H_


void TIMER2_void_Init(void);

void TIMER2_void_SetTimerReg(u8 Copy_uint8Val);
		  
void TIMER2_void_SetCompareVal(u8 Copy_uint8Val);
		  
void TIMER2_void_EnableOVInt(void);
		  
void TIMER2_void_DisableOVInt(void);
		  
void TIMER2_void_EnableCTCInt(void);
		  
void TIMER2_void_DisableCTCInt(void);
		  
void TIMER2_void_SetOVCallBack(void (*Copy_ptr) (void) ) ;
		  
void TIMER2_void_SetCTCCallBack(void (*Copy_ptr) (void) ) ;





#endif 

/***********************************************************************************************/
/************************************* END OF PROGRAM ******************************************/
/***********************************************************************************************/