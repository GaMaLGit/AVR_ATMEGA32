/****************************************************************/
/*   Author             :    Gamal Ahmed Gamal 				    */
/*	 Date 				:    25 Feb 2023 						*/
/*	 Version 			:    1.0V 							 	*/
/*	 Description 		:    Configure TIMER2 [config.h]     	*/
/****************************************************************/

/****************************************************************/
/* Description   : Guard to protect this File from include more */
/*                 than one time .                              */
/****************************************************************/

#ifndef TMR2_CONFIG_H_
#define TMR2_CONFIG_H_

typedef enum {
	Normal_Mode ,
	Phase_PWM ,
	CTC       ,
	Fast_PWM
}Timer2_Mode;


typedef enum {
	NO_Prescaler ,
	Div_By_1     ,
	Div_By_8     ,
	Div_By_32    ,
	Div_By_64    ,
	Div_By_128   ,
	Div_By_256   ,
	Div_By_1024
}Timee2_Prescaler;


typedef enum {
	Normal_com ,
	Toggle ,
	Clear  ,
	Set
}Timer2_Com;

typedef struct {
	Timer2_Mode       TMR2_Mode      ;
	Timee2_Prescaler  TMR2_Prescaler ;
	Timer2_Com        TMR2_Com       ;
}TMR2_Config;


TMR2_Config Config_Timer2[1] ; 


#endif 

/***********************************************************************************************/
/************************************* END OF PROGRAM ******************************************/
/***********************************************************************************************/