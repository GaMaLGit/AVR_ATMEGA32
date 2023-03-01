/****************************************************************/
/*   Author             :    Gamal Ahmed Gamal 				    */
/*	 Date 				:    27 Feb 2023 						*/
/*	 Version 			:    1.0V 							 	*/
/*	 Description 		:   Program  for Stepper Motor	        */
/****************************************************************/

/****************************************************************/
/******************************* Macros *************************/
/****************************************************************/

#define F_CPU 16000000UL

/****************************************************************/
/*********************** STD LIB DIRECTIVES *********************/
/****************************************************************/

#include "../LIB/std_types.h"
#include "../LIB/bit_math.h"
#include  <util/delay.h>

/****************************************************************/
/*********************** Component DIRECTIVES *******************/
/****************************************************************/

#include "../HAL/Unipolar Stepper Motor/Uni_Stepper_Motor_Interface.h"
#include "../HAL/Unipolar Stepper Motor/Uni_Stepper_Motor_Config.h"
#include "../MCAL/DIO/dio.h"

/********************************************************************/
/* Description    :  This function used to initialize Stepper Motor */
/*					 Inputs : void			 				     	*/
/*					 return : void		 					    	*/
/********************************************************************/


void UniStepperMotor_voidInit(){

//Configure output pins and clear them 
		
for(u8 i = 0 ; i < NUMBER_OF_STEPPER_MOTORS ; i++ ){
	 // OutPut Pins
     dio_vidConfigChannel(Config_StepperMotor[i].Stepper_Port , Config_StepperMotor[i].Stepper_Pin1, OUTPUT);
	 dio_vidConfigChannel(Config_StepperMotor[i].Stepper_Port , Config_StepperMotor[i].Stepper_Pin2, OUTPUT);
	 dio_vidConfigChannel(Config_StepperMotor[i].Stepper_Port , Config_StepperMotor[i].Stepper_Pin3, OUTPUT);
	 dio_vidConfigChannel(Config_StepperMotor[i].Stepper_Port , Config_StepperMotor[i].Stepper_Pin4, OUTPUT); 
	 // Clear Pins 
	 dio_vidWriteChannel(Config_StepperMotor[i].Stepper_Port , Config_StepperMotor[i].Stepper_Pin1 , STD_LOW);
	 dio_vidWriteChannel(Config_StepperMotor[i].Stepper_Port , Config_StepperMotor[i].Stepper_Pin2 , STD_LOW);
	 dio_vidWriteChannel(Config_StepperMotor[i].Stepper_Port , Config_StepperMotor[i].Stepper_Pin3 , STD_LOW);
	 dio_vidWriteChannel(Config_StepperMotor[i].Stepper_Port , Config_StepperMotor[i].Stepper_Pin4 , STD_LOW);
}
		
}



/********************************************************************/
/* Description    :  This function used to Rotate Stepper Motor	    */
/*					 Clock Wise and Num of steps 				    */
/*					 Inputs : Stepper Motor Number 	 ,  		    */
/*   						                                        */
/*					 return : void                                  */
/********************************************************************/
/* Pre_condition  :  this function must be used after Stepper Motor */
/*     				 initialized								    */
/********************************************************************/


void UniStepperMotor_voidRotCW (u8 StepperMotorNum , u16 StepCounts) {
	
	for(u8 i = 0 ; i < StepCounts ; i++ ){
		
	  switch (Config_StepperMotor[StepperMotorNum].Stepper_Mode){
	  	
	   case Full_Step :
	    dio_vidWriteChannel(Config_StepperMotor[i].Stepper_Port , Config_StepperMotor[i].Stepper_Pin1 , STD_HIGH);
	    dio_vidWriteChannel(Config_StepperMotor[i].Stepper_Port , Config_StepperMotor[i].Stepper_Pin2 , STD_LOW);
	    dio_vidWriteChannel(Config_StepperMotor[i].Stepper_Port , Config_StepperMotor[i].Stepper_Pin3 , STD_LOW);
	    dio_vidWriteChannel(Config_StepperMotor[i].Stepper_Port , Config_StepperMotor[i].Stepper_Pin4 , STD_HIGH);
	  	_delay_ms(5);
	    dio_vidWriteChannel(Config_StepperMotor[i].Stepper_Port , Config_StepperMotor[i].Stepper_Pin1 , STD_LOW);
	    dio_vidWriteChannel(Config_StepperMotor[i].Stepper_Port , Config_StepperMotor[i].Stepper_Pin2 , STD_LOW);
	    dio_vidWriteChannel(Config_StepperMotor[i].Stepper_Port , Config_StepperMotor[i].Stepper_Pin3 , STD_HIGH);
	    dio_vidWriteChannel(Config_StepperMotor[i].Stepper_Port , Config_StepperMotor[i].Stepper_Pin4 , STD_HIGH);
	    _delay_ms(5);
	    dio_vidWriteChannel(Config_StepperMotor[i].Stepper_Port , Config_StepperMotor[i].Stepper_Pin1 , STD_LOW);
	    dio_vidWriteChannel(Config_StepperMotor[i].Stepper_Port , Config_StepperMotor[i].Stepper_Pin2 , STD_HIGH);
	    dio_vidWriteChannel(Config_StepperMotor[i].Stepper_Port , Config_StepperMotor[i].Stepper_Pin3 , STD_HIGH);
	    dio_vidWriteChannel(Config_StepperMotor[i].Stepper_Port , Config_StepperMotor[i].Stepper_Pin4 , STD_LOW);
	    _delay_ms(5);
	    dio_vidWriteChannel(Config_StepperMotor[i].Stepper_Port , Config_StepperMotor[i].Stepper_Pin1 , STD_HIGH);
	    dio_vidWriteChannel(Config_StepperMotor[i].Stepper_Port , Config_StepperMotor[i].Stepper_Pin2 , STD_HIGH);
	    dio_vidWriteChannel(Config_StepperMotor[i].Stepper_Port , Config_StepperMotor[i].Stepper_Pin3 , STD_LOW);
	    dio_vidWriteChannel(Config_StepperMotor[i].Stepper_Port , Config_StepperMotor[i].Stepper_Pin4 , STD_LOW);
	    _delay_ms(5);						  				 
	  	break ; 
		  
	  case Half_Step : 
	    dio_vidWriteChannel(Config_StepperMotor[i].Stepper_Port , Config_StepperMotor[i].Stepper_Pin1 , STD_HIGH);
	    dio_vidWriteChannel(Config_StepperMotor[i].Stepper_Port , Config_StepperMotor[i].Stepper_Pin2 , STD_LOW);
	    dio_vidWriteChannel(Config_StepperMotor[i].Stepper_Port , Config_StepperMotor[i].Stepper_Pin3 , STD_LOW);
	    dio_vidWriteChannel(Config_StepperMotor[i].Stepper_Port , Config_StepperMotor[i].Stepper_Pin4 , STD_HIGH);
	    _delay_ms(5);
	    dio_vidWriteChannel(Config_StepperMotor[i].Stepper_Port , Config_StepperMotor[i].Stepper_Pin1 , STD_LOW);
	    dio_vidWriteChannel(Config_StepperMotor[i].Stepper_Port , Config_StepperMotor[i].Stepper_Pin2 , STD_LOW);
	    dio_vidWriteChannel(Config_StepperMotor[i].Stepper_Port , Config_StepperMotor[i].Stepper_Pin3 , STD_LOW);
	    dio_vidWriteChannel(Config_StepperMotor[i].Stepper_Port , Config_StepperMotor[i].Stepper_Pin4 , STD_HIGH);
	    _delay_ms(5);
	    dio_vidWriteChannel(Config_StepperMotor[i].Stepper_Port , Config_StepperMotor[i].Stepper_Pin1 , STD_LOW);
	    dio_vidWriteChannel(Config_StepperMotor[i].Stepper_Port , Config_StepperMotor[i].Stepper_Pin2 , STD_LOW);
	    dio_vidWriteChannel(Config_StepperMotor[i].Stepper_Port , Config_StepperMotor[i].Stepper_Pin3 , STD_HIGH);
	    dio_vidWriteChannel(Config_StepperMotor[i].Stepper_Port , Config_StepperMotor[i].Stepper_Pin4 , STD_HIGH);
	    _delay_ms(5);
	    dio_vidWriteChannel(Config_StepperMotor[i].Stepper_Port , Config_StepperMotor[i].Stepper_Pin1 , STD_LOW);
	    dio_vidWriteChannel(Config_StepperMotor[i].Stepper_Port , Config_StepperMotor[i].Stepper_Pin2 , STD_LOW);
	    dio_vidWriteChannel(Config_StepperMotor[i].Stepper_Port , Config_StepperMotor[i].Stepper_Pin3 , STD_HIGH);
	    dio_vidWriteChannel(Config_StepperMotor[i].Stepper_Port , Config_StepperMotor[i].Stepper_Pin4 , STD_LOW);
	    _delay_ms(5);	    	
	    dio_vidWriteChannel(Config_StepperMotor[i].Stepper_Port , Config_StepperMotor[i].Stepper_Pin1 , STD_LOW);
	    dio_vidWriteChannel(Config_StepperMotor[i].Stepper_Port , Config_StepperMotor[i].Stepper_Pin2 , STD_HIGH);
	    dio_vidWriteChannel(Config_StepperMotor[i].Stepper_Port , Config_StepperMotor[i].Stepper_Pin3 , STD_HIGH);
	    dio_vidWriteChannel(Config_StepperMotor[i].Stepper_Port , Config_StepperMotor[i].Stepper_Pin4 , STD_LOW);
	    _delay_ms(5);
	    dio_vidWriteChannel(Config_StepperMotor[i].Stepper_Port , Config_StepperMotor[i].Stepper_Pin1 , STD_LOW);
	    dio_vidWriteChannel(Config_StepperMotor[i].Stepper_Port , Config_StepperMotor[i].Stepper_Pin2 , STD_HIGH);
	    dio_vidWriteChannel(Config_StepperMotor[i].Stepper_Port , Config_StepperMotor[i].Stepper_Pin3 , STD_LOW);
	    dio_vidWriteChannel(Config_StepperMotor[i].Stepper_Port , Config_StepperMotor[i].Stepper_Pin4 , STD_LOW);
	    _delay_ms(5);
	    dio_vidWriteChannel(Config_StepperMotor[i].Stepper_Port , Config_StepperMotor[i].Stepper_Pin1 , STD_HIGH);
	    dio_vidWriteChannel(Config_StepperMotor[i].Stepper_Port , Config_StepperMotor[i].Stepper_Pin2 , STD_HIGH);
	    dio_vidWriteChannel(Config_StepperMotor[i].Stepper_Port , Config_StepperMotor[i].Stepper_Pin3 , STD_LOW);
	    dio_vidWriteChannel(Config_StepperMotor[i].Stepper_Port , Config_StepperMotor[i].Stepper_Pin4 , STD_LOW);
	    _delay_ms(5);
	    dio_vidWriteChannel(Config_StepperMotor[i].Stepper_Port , Config_StepperMotor[i].Stepper_Pin1 , STD_HIGH);
	    dio_vidWriteChannel(Config_StepperMotor[i].Stepper_Port , Config_StepperMotor[i].Stepper_Pin2 , STD_LOW);
	    dio_vidWriteChannel(Config_StepperMotor[i].Stepper_Port , Config_StepperMotor[i].Stepper_Pin3 , STD_LOW);
	    dio_vidWriteChannel(Config_StepperMotor[i].Stepper_Port , Config_StepperMotor[i].Stepper_Pin4 , STD_LOW);
	    _delay_ms(5);	  	
	  	break; 
	  	
	  	
	  }
					
	}
	
		
	}

/********************************************************************/
/* Description    :  This function used to Rotate Stepper Motor	    */
/*					 Counter Clock Wise and Num of steps 		    */
/*					 Inputs : Stepper Motor Number 	 ,  		    */
/*   						                                        */
/*					 return : void                                  */
/********************************************************************/
/* Pre_condition  :  this function must be used after Stepper Motor */
/*     				 initialized								    */
/********************************************************************/


void UniStepperMotor_voidRotCCW (u8 StepperMotorNum , u16 StepCounts) {
	
	for(u8 i = 0 ; i < StepCounts ; i++ ){
		
		switch (Config_StepperMotor[StepperMotorNum].Stepper_Mode){
			
			case Full_Step :
			dio_vidWriteChannel(Config_StepperMotor[i].Stepper_Port , Config_StepperMotor[i].Stepper_Pin1 , STD_HIGH);
			dio_vidWriteChannel(Config_StepperMotor[i].Stepper_Port , Config_StepperMotor[i].Stepper_Pin2 , STD_LOW);
			dio_vidWriteChannel(Config_StepperMotor[i].Stepper_Port , Config_StepperMotor[i].Stepper_Pin3 , STD_LOW);
			dio_vidWriteChannel(Config_StepperMotor[i].Stepper_Port , Config_StepperMotor[i].Stepper_Pin4 , STD_HIGH);
			_delay_ms(5);
			dio_vidWriteChannel(Config_StepperMotor[i].Stepper_Port , Config_StepperMotor[i].Stepper_Pin1 , STD_HIGH);
			dio_vidWriteChannel(Config_StepperMotor[i].Stepper_Port , Config_StepperMotor[i].Stepper_Pin2 , STD_HIGH);
			dio_vidWriteChannel(Config_StepperMotor[i].Stepper_Port , Config_StepperMotor[i].Stepper_Pin3 , STD_LOW);
			dio_vidWriteChannel(Config_StepperMotor[i].Stepper_Port , Config_StepperMotor[i].Stepper_Pin4 , STD_LOW);
			_delay_ms(5);
			dio_vidWriteChannel(Config_StepperMotor[i].Stepper_Port , Config_StepperMotor[i].Stepper_Pin1 , STD_LOW);
			dio_vidWriteChannel(Config_StepperMotor[i].Stepper_Port , Config_StepperMotor[i].Stepper_Pin2 , STD_HIGH);
			dio_vidWriteChannel(Config_StepperMotor[i].Stepper_Port , Config_StepperMotor[i].Stepper_Pin3 , STD_HIGH);
			dio_vidWriteChannel(Config_StepperMotor[i].Stepper_Port , Config_StepperMotor[i].Stepper_Pin4 , STD_LOW);
			_delay_ms(5);
			dio_vidWriteChannel(Config_StepperMotor[i].Stepper_Port , Config_StepperMotor[i].Stepper_Pin1 , STD_LOW);
			dio_vidWriteChannel(Config_StepperMotor[i].Stepper_Port , Config_StepperMotor[i].Stepper_Pin2 , STD_LOW);
			dio_vidWriteChannel(Config_StepperMotor[i].Stepper_Port , Config_StepperMotor[i].Stepper_Pin3 , STD_HIGH);
			dio_vidWriteChannel(Config_StepperMotor[i].Stepper_Port , Config_StepperMotor[i].Stepper_Pin4 , STD_HIGH);
			_delay_ms(5);
			break ;
			
			case Half_Step :
			dio_vidWriteChannel(Config_StepperMotor[i].Stepper_Port , Config_StepperMotor[i].Stepper_Pin1 , STD_HIGH);
			dio_vidWriteChannel(Config_StepperMotor[i].Stepper_Port , Config_StepperMotor[i].Stepper_Pin2 , STD_LOW);
			dio_vidWriteChannel(Config_StepperMotor[i].Stepper_Port , Config_StepperMotor[i].Stepper_Pin3 , STD_LOW);
			dio_vidWriteChannel(Config_StepperMotor[i].Stepper_Port , Config_StepperMotor[i].Stepper_Pin4 , STD_HIGH);
			_delay_ms(5);
			dio_vidWriteChannel(Config_StepperMotor[i].Stepper_Port , Config_StepperMotor[i].Stepper_Pin1 , STD_HIGH);
			dio_vidWriteChannel(Config_StepperMotor[i].Stepper_Port , Config_StepperMotor[i].Stepper_Pin2 , STD_LOW);
			dio_vidWriteChannel(Config_StepperMotor[i].Stepper_Port , Config_StepperMotor[i].Stepper_Pin3 , STD_LOW);
			dio_vidWriteChannel(Config_StepperMotor[i].Stepper_Port , Config_StepperMotor[i].Stepper_Pin4 , STD_LOW);
			_delay_ms(5);
			dio_vidWriteChannel(Config_StepperMotor[i].Stepper_Port , Config_StepperMotor[i].Stepper_Pin1 , STD_HIGH);
			dio_vidWriteChannel(Config_StepperMotor[i].Stepper_Port , Config_StepperMotor[i].Stepper_Pin2 , STD_HIGH);
			dio_vidWriteChannel(Config_StepperMotor[i].Stepper_Port , Config_StepperMotor[i].Stepper_Pin3 , STD_LOW);
			dio_vidWriteChannel(Config_StepperMotor[i].Stepper_Port , Config_StepperMotor[i].Stepper_Pin4 , STD_LOW);
			_delay_ms(5);
			dio_vidWriteChannel(Config_StepperMotor[i].Stepper_Port , Config_StepperMotor[i].Stepper_Pin1 , STD_LOW);
			dio_vidWriteChannel(Config_StepperMotor[i].Stepper_Port , Config_StepperMotor[i].Stepper_Pin2 , STD_HIGH);
			dio_vidWriteChannel(Config_StepperMotor[i].Stepper_Port , Config_StepperMotor[i].Stepper_Pin3 , STD_LOW);
			dio_vidWriteChannel(Config_StepperMotor[i].Stepper_Port , Config_StepperMotor[i].Stepper_Pin4 , STD_LOW);
			_delay_ms(5);
			dio_vidWriteChannel(Config_StepperMotor[i].Stepper_Port , Config_StepperMotor[i].Stepper_Pin1 , STD_LOW);
			dio_vidWriteChannel(Config_StepperMotor[i].Stepper_Port , Config_StepperMotor[i].Stepper_Pin2 , STD_HIGH);
			dio_vidWriteChannel(Config_StepperMotor[i].Stepper_Port , Config_StepperMotor[i].Stepper_Pin3 , STD_HIGH);
			dio_vidWriteChannel(Config_StepperMotor[i].Stepper_Port , Config_StepperMotor[i].Stepper_Pin4 , STD_LOW);
			_delay_ms(5);
			dio_vidWriteChannel(Config_StepperMotor[i].Stepper_Port , Config_StepperMotor[i].Stepper_Pin1 , STD_LOW);
			dio_vidWriteChannel(Config_StepperMotor[i].Stepper_Port , Config_StepperMotor[i].Stepper_Pin2 , STD_LOW);
			dio_vidWriteChannel(Config_StepperMotor[i].Stepper_Port , Config_StepperMotor[i].Stepper_Pin3 , STD_HIGH);
			dio_vidWriteChannel(Config_StepperMotor[i].Stepper_Port , Config_StepperMotor[i].Stepper_Pin4 , STD_LOW);
			_delay_ms(5);
			dio_vidWriteChannel(Config_StepperMotor[i].Stepper_Port , Config_StepperMotor[i].Stepper_Pin1 , STD_LOW);
			dio_vidWriteChannel(Config_StepperMotor[i].Stepper_Port , Config_StepperMotor[i].Stepper_Pin2 , STD_LOW);
			dio_vidWriteChannel(Config_StepperMotor[i].Stepper_Port , Config_StepperMotor[i].Stepper_Pin3 , STD_HIGH);
			dio_vidWriteChannel(Config_StepperMotor[i].Stepper_Port , Config_StepperMotor[i].Stepper_Pin4 , STD_HIGH);
			_delay_ms(5);
			dio_vidWriteChannel(Config_StepperMotor[i].Stepper_Port , Config_StepperMotor[i].Stepper_Pin1 , STD_LOW);
			dio_vidWriteChannel(Config_StepperMotor[i].Stepper_Port , Config_StepperMotor[i].Stepper_Pin2 , STD_LOW);
			dio_vidWriteChannel(Config_StepperMotor[i].Stepper_Port , Config_StepperMotor[i].Stepper_Pin3 , STD_LOW);
			dio_vidWriteChannel(Config_StepperMotor[i].Stepper_Port , Config_StepperMotor[i].Stepper_Pin4 , STD_HIGH);
			_delay_ms(5);
			break;
			
			
		}
		
	}
	
	
}


/***********************************************************************************************/
/************************************* END OF PROGRAM ******************************************/
/***********************************************************************************************/