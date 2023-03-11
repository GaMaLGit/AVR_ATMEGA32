/****************************************************************/
/*   Author             :    Gamal Ahmed Gamal 				    */
/*	 Date 				:    4 March 2023 						*/
/*	 Version 			:    1.0V 							 	*/
/*	 Description 		:    Configure I2C [config.h]     	    */
/****************************************************************/

/****************************************************************/
/* Description   : Guard to protect this File from include more */
/*                 than one time .                              */
/****************************************************************/


#ifndef I2C_CONFIG_H_
#define I2C_CONFIG_H_

typedef enum i2c_prescaller_value
{
	I2C_PRESCALLER_DIV1     = 1,
	I2C_PRESCALLER_DIV4     = 4,
	I2C_PRESCALLER_DIV16    = 16,
	I2C_PRESCALLER_DIV64    = 64
}I2C_Prescaller_t;

I2C_Prescaller_t I2C_Prescaller = I2C_PRESCALLER_DIV4;





#endif /* I2C_CONFIG_H_ */