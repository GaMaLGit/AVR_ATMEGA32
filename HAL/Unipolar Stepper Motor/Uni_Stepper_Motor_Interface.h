/****************************************************************/
/*   Author             :    Gamal Ahmed Gamal 				    */
/*	 Date 				:    27 Feb 2023 						*/
/*	 Version 			:    1.0V 							 	*/
/*	 Description 		:   public Accessing mechanism prototype*/
/*							for Stepper Motor [interface.h]     */
/****************************************************************/

/****************************************************************/
/* Description   : Guard to protect this File from include more */
/*                 than one time .                              */
/****************************************************************/

#ifndef UNI_STEPPER_MOTOR_INTERFACE_H_
#define UNI_STEPPER_MOTOR_INTERFACE_H_

/********************************************************************/
/* Description    :  This function used to initialize Stepper Motor */
/*					 Inputs : void			 				     	*/
/*					 return : void		 					    	*/
/********************************************************************/

void UniStepperMotor_voidInit();

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

void UniStepperMotor_voidRotCW (u8 StepperMotorNum , u16 StepCounts);

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


void UniStepperMotor_voidRotCCW (u8 StepperMotorNum , u16 StepCounts);



#endif /* UNI_STEPPER_MOTOR_INTERFACE_H_ */