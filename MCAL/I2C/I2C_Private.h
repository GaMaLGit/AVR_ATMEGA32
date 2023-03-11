/****************************************************************/
/* 	Author 	 	 : Gamal Ahmed Gamal                            */
/* 	Date   		 : 10 March 2023	                                */
/* 	Version 	 : 1V 									        */
/*	 Description : contain the Memory mapped of I2C Registers	*/
/****************************************************************/


/****************************************************************/
/* Description   : Guard to protect this File from include more */
/*                 than one time .                              */
/****************************************************************/



#ifndef I2C_PRIVATE_H_
#define I2C_PRIVATE_H_

#define     TWBR_REG       ( * (volatile u8 *)0x20)
#define     TWSR_REG       ( * (volatile u8 *)0x21)
#define     TWAR_REG       ( * (volatile u8 *)0x22)
#define     TWDR_REG       ( * (volatile u8 *)0x23)
#define     TWCR_REG       ( * (volatile u8 *)0x56)

/// @brief TWBR  Bits name
#define     TWBR7       7
#define     TWBR6       6
#define     TWBR5       5
#define     TWBR4       4
#define     TWBR3       3
#define     TWBR2       2
#define     TWBR1       1
#define     TWBR0       0

/// @brief TWCR  Bits name
#define     TWINT       7
#define     TWEA        6
#define     TWSTA       5
#define     TWSTO       4
#define     TWWC        3
#define     TWEN        2
#define     TWIE        0

/// @brief TWSR  Bits name
#define     TWS7        7
#define     TWS6        6
#define     TWS5        5
#define     TWS4        4
#define     TWS3        3
#define     TWPS1       1
#define     TWPS0       0

#endif /* I2C_PRIVATE_H_ */