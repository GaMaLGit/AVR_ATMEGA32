/****************************************************************/
/*   Author             :    Gamal Ahmed Gamal 				    */
/*	 Date 				:    25 Feb 2023 						*/
/*	 Version 			:    1.0V 							 	*/
/*	 Description 		:    Configure Sense Mode [config.h] 	*/
/****************************************************************/



/****************************************************************/
/* Description   : Guard to protect this File from include more */
/*                 than one time .                              */
/****************************************************************/
#ifndef _ADC_CONFIG_H
#define _ADC_CONFIG_H

/****************************************************************/
/** !comment : Please Enter Number of Channels   				*/
/****************************************************************/

#define NUM_OF_ADC 1


/****************************************************************/
/** !comment : Please Enter the Voltage Reference				*/
/****************************************************************/

typedef enum{
	AREF ,
	AVCC ,
	INTERNAL = 3 
}Voltage_Reference;




/****************************************************************/
/** !comment : Please Enter the ADJUSTMENT						*/
/****************************************************************/
/****************************************************************/
/** NOTE	 : The preferred adjustment for a 8 bits Resolution	*/
/*				is LEFT_ADJUSTMENT and for a 10 bits Resolution	*/
/*				is RIGHT_ADJUSTMENT								*/
/****************************************************************/

typedef enum {
Right_Adjustment , 
Left_Adjustment		
}Adjustment;




/***************************************************************************/
/** !comment : Please Enter the Voltage Reference				           */
/***************************************************************************/

typedef enum {
Free_Runnung , 
Analog_Comparator , 
EXT0 , 
Tim_Counter0_Compare ,
Tim_Counter0_Overflow , 
Tim_Counter1_Compare ,
Tim_Counter1_Overflow ,
Tim_Counter1_Capture 	
	
}Auto_Trigger_Source;


/****************************************************************/
/** !comment : Please Enter Prescaler Value      				*/
/****************************************************************/

typedef enum {
Prescaler_2     , 
Prescaler_4	= 2 , 
Prescaler_8     , 
Prescaler_16    , 
Prescaler_32    ,
Prescaler_64    ,
Prescaler_128
}ADC_Prescaler;




typedef struct {
Voltage_Reference   V_Ref     ; 
Adjustment          Adj       ;
Auto_Trigger_Source Trig_S    ;	
ADC_Prescaler       Prescaler ;	
	
}ADC_Config;


ADC_Config Config_ADC[NUM_OF_ADC] ;



#endif	/**!comment : End of the guard [_ADC_CONFIG_H]		   **/