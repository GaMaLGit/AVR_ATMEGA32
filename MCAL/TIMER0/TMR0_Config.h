/****************************************************************/
/*   Author             :    Gamal Ahmed Gamal 				    */
/*	 Date 				:    25 Feb 2023 						*/
/*	 Version 			:    1.0V 							 	*/
/*	 Description 		:    Configure TIMER0 [config.h]     	*/
/****************************************************************/

/****************************************************************/
/* Description   : Guard to protect this File from include more */
/*                 than one time .                              */
/****************************************************************/

#ifndef _TIMER0_CONFIG_H
#define _TIMER0_CONFIG_H


typedef enum {
  Normal_Mode , 
  Phase_PWM , 
  CTC       , 
  Fast_PWM 	
}Timer0_Mode;



typedef enum {
	NO_Prescaler , 
	Div_By_1     ,
	Div_By_8     ,
	Div_By_64     ,
	Div_By_256     ,
	Div_By_1024
}Timee0_Prescaler;


typedef enum {
  Normal_com , 
  Toggle , 
  Clear  , 
  Set	
}Timer0_Com;

typedef struct {
 Timer0_Mode       TMR0_Mode      ; 
 Timee0_Prescaler  TMR0_Prescaler ;	
 Timer0_Com        TMR0_Com       ; 	
}TMR0_Config;

TMR0_Config Config_Timer0[1] ; 



#endif

/***********************************************************************************************/
/************************************* END OF PROGRAM ******************************************/
/***********************************************************************************************/
