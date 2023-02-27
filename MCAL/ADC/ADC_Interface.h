/****************************************************************/
/* 	Author 	 	 : Gamal Ahmed Gamal                            */
/* 	Date   		 : 25 Feb 2023	                                */
/* 	Version 	 : 1V 									        */
/*	 Description : public Accessing mechanism prototype         */
/*				   and Sense Mode Definition [int.h] 	        */
/****************************************************************/



/****************************************************************/
/* Description   : Guard to protect this File from include more */
/*                 than one time .                              */
/****************************************************************/

#ifndef _ADC_INT_H
#define _ADC_INT_H






/****************************************************************/
/* Description    :  This function used to initialize ADC 	    */
/*					 Inputs : void 								*/
/*					 return : void		 						*/
/****************************************************************/

void ADC_voidInit (void);


//****************************************************************/
/* Description    : This function used to Enable ADC			*/
/*																*/
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after ADC		*/
/*     				 initialized 							    */
/****************************************************************/

void ADC_voidEnable();


/****************************************************************/
/* Description    : This function used to Enable ADC Interrput	*/
/*																*/
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after ADC		*/
/*     				 initialized 							    */
/****************************************************************/

void ADC_voidInterrputEnable();


/****************************************************************/
/* Description    : This function used to Disable ADC			*/
/*																*/
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after ADC 		*/
/*     				 initialized 							    */
/****************************************************************/

void ADC_voidDisable();


/****************************************************************/
/* Description    : This function used to communicate with the	*/
/*					function in App Layer(The Callback function)*/
/*						[ Layer Architecture Problem Solved ]	*/
/*																*/
/*					Inputs : Pointer to function that points to	*/
/*							 the first line of the function(ISR)*/
/*					Return : void								*/
/****************************************************************/
/* Pre_condition  :  this function must be used after Interrupt */
/*     				 initialized 							    */
/****************************************************************/
void ADC_u8ReadADC(void (*addresscpy)(void), u8 channel );


/****************************************************************/
/* Description    : This function used to Start converting		*/
/*																*/
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after ADC 		*/
/*     				 initialized 							    */
/****************************************************************/

void ADC_voidStartConversion();


/****************************************************************/
/* Description    : This function used to Set lach Interrupt	*/
/*									 happens.					*/
/*																*/
/*					Inputs : Sense Mode				  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after Interrupt */
/*     				 initialized 							    */
/****************************************************************/

void ADC_voidAutoTrigger();



/****************************************************************/
/* Description    : This function used to Read ADC and 			*/
/*																*/
/*					Inputs : void					  			*/
/*					Return : u16 Digital Converting melli Volt	*/
/****************************************************************/
/* Pre_condition  :  this function must be used after ADC 		*/
/*     				 initialized 							    */
/****************************************************************/

u16 ADC_u16ReadADCInMV(u8 channel );




#endif	/** !comment  :  End of guard                          **/