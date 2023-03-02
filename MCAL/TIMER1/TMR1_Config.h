/****************************************************************/
/*   Author             :    Gamal Ahmed Gamal 				    */
/*	 Date 				:    2 March 2023 						*/
/*	 Version 			:    1.0V 							 	*/
/*	 Description 		:    Configure TIMER1 [config.h]     	*/
/****************************************************************/

/****************************************************************/
/* Description   : Guard to protect this File from include more */
/*                 than one time .                              */
/****************************************************************/


#ifndef TMR1_CONFIG_H_
#define TMR1_CONFIG_H_

typedef enum {
	Normal_Mode  ,
	Phase_PWM_8  ,
	Phase_PWM_9  ,
	Phase_PWM_10 ,
	CTC          ,
	Fast_PWM_8   ,
	Fast_PWM_9   ,
	Fast_PWM_10  ,
	PWM_PF_ICR   ,
	PWM_PF_OCR   ,
	PWM_P_ICR    ,
	PWM_P_OCR    ,
	CTC_ICR      ,
	FPWM_ICR     ,
	FPWM_OCR
	
}Timer1_Mode;


typedef enum {
	NO_Prescaler ,
	Div_By_1     ,
	Div_By_8     ,
	Div_By_64    ,
	Div_By_256   ,
	Div_By_1024  , 
	Falling_Edge , 
	Rising_Edge
	
}Timee1_Prescaler;


typedef enum {
	Normal_com ,
	Toggle ,
	Clear  ,
	Set
}Timer1_Com;



typedef struct {
	Timer1_Mode       TMR1_Mode      ;
	Timee1_Prescaler  TMR1_Prescaler ;
	Timer1_Com        TMR1_Com_A     ;
	Timer1_Com        TMR1_Com_B     ;
}TMR1_Config;

TMR1_Config Config_Timer1[1] ; 


#endif 

/***********************************************************************************************/
/************************************* END OF PROGRAM ******************************************/
/***********************************************************************************************/
