/****************************************************************/
/*   Author             :    Gamal Ahmed Gamal 				    */
/*	 Date 				:    10 March 2023 						*/
/*	 Version 			:    1.0V 							 	*/
/*   Description	    :    prog.c for I2C                     */
/****************************************************************/

/****************************************************************/
/*********************** STD LIB DIRECTIVES *********************/
/****************************************************************/

#include "../LIB/std_types.h"
#include "../LIB/bit_math.h"


/****************************************************************/
/*********************** Component DIRECTIVES *******************/
/****************************************************************/

#include "../MCAL/I2C/I2C_Interface.h"
#include "../MCAL/I2C/I2C_Private.h"
#include "../MCAL/I2C/I2C_Config.h"

/****************************************************************/
/******************************* Macros *************************/
/****************************************************************/
#define         FCPU                16000000UL
#define         SCL_FREQ            100000UL
#define         I2C_STATUS_MASK     0XF8


#define         I2C_SC_ACK          0x08
#define         I2C_RSC_ACK         0x10
#define         I2C_MT_SLA_R_ACK    0x40
#define         I2C_MT_SLA_W_ACK    0x18
#define         I2C_MT_DATA_ACK     0x28
#define         I2C_MR_DATA_ACK     0x48
#define         I2C_SR_DATA_ACK     0x80

void I2C_Master_vInit(void)
{
	switch (I2C_Prescaller)
	{
		case I2C_PRESCALLER_DIV1:
		TWSR_REG |= 0;
		break;
		case I2C_PRESCALLER_DIV4:
		TWSR_REG |= 1;
		break;
		case I2C_PRESCALLER_DIV16:
		TWSR_REG |= 2;
		break;
		case I2C_PRESCALLER_DIV64:
		TWSR_REG |= 3;
		break;
		default:
		break;
	}
	TWBR_REG = ((FCPU / SCL_FREQ) - 16) / (2 * 1);      /* Set Bit rate Based on pre define SCL value */
	SET_BIT(TWCR_REG , TWEA);                            /* Enable Ack Mode                            */
	SET_BIT(TWCR_REG , TWEN);                            /* Enable I2C                                 */
}


void I2C_Slave_vInit(u8 I2C_Address)
{
	switch (I2C_Prescaller)
	{
		case I2C_PRESCALLER_DIV1:
		TWSR_REG |= 0;
		break;
		case I2C_PRESCALLER_DIV4:
		TWSR_REG |= 1;
		break;
		case I2C_PRESCALLER_DIV16:
		TWSR_REG |= 2;
		break;
		case I2C_PRESCALLER_DIV64:
		TWSR_REG |= 3;
		break;
		default:
		break;
	}
	TWBR_REG = ((FCPU / SCL_FREQ) - 16) / (2 * 1);      /* Set Bit rate Based on pre define SCL value */
	SET_BIT(TWCR_REG , TWEA);                            /* Enable Ack Mode                            */
	TWAR_REG = I2C_Address << 1;                        /* Set Slave Address in TWAR reg              */
	SET_BIT(TWCR_REG , TWEN);                            /* Enable I2C                                 */
}



I2C_ErrorState_t I2C_Master_enuSendSC(void)
{
	SET_BIT(TWCR_REG , TWSTA);                           /* Send Start Condition                         */
	SET_BIT(TWCR_REG , TWINT);                           /* Clear the flag to start the operatoin of i2c */
	while(CHECK_BIT(TWCR_REG , TWINT) == 0);               /* Polling untill the transmitting done         */
	if((TWSR_REG &  I2C_STATUS_MASK) != I2C_SC_ACK)     /* Check for i2c Status                         */
	{
		return I2C_SC_ERROR;
	}
	else
	{
		return I2C_OK;
	}
}




I2C_ErrorState_t I2C_Master_enuSendRSC(void)
{
	SET_BIT(TWCR_REG , TWSTA);                           /* Send Start Condition                         */
	SET_BIT(TWCR_REG , TWINT);                           /* Clear the flag to start the operation of i2c */
	while(CHECK_BIT(TWCR_REG , TWINT) == 0);               /* Polling until the transmitting done         */
	if((TWSR_REG &  I2C_STATUS_MASK) != I2C_RSC_ACK)    /* Check for i2c Status                         */
	{
		return I2C_RSC_ERROR;
	}
	else
	{
		return I2C_OK;
	}
}


I2C_ErrorState_t I2C_Master_enuSendSlaveAddress_WR(u8 I2C_Address , I2C_Send_Add_WR_t WR_Option)
{
	TWDR_REG = I2C_Address << 1;                                        /* Shift Address By 1       */
	if(WR_Option == I2C_SEND_ADDRESS_WITH_WRITE)
	{
		CLEAR_BIT(TWDR_REG , 0);                                           /* Write Operation          */
	}
	else if(WR_Option == I2C_SEND_ADDRESS_WITH_READ)                    /* Send with read option    */
	{
		SET_BIT(TWDR_REG , 0);                                           /* Read Operation           */
	}
	CLEAR_BIT(TWCR_REG , TWSTA);                                           /* Clear the start condition */
	SET_BIT(TWCR_REG , TWINT);                                           /* Clear the flag to start the operatoin of i2c */
	while(CHECK_BIT(TWCR_REG , TWINT) == 0);                               /* Polling untill the transmitting done         */
	
	if((WR_Option == I2C_SEND_ADDRESS_WITH_WRITE) && ( (TWSR_REG &  I2C_STATUS_MASK) != I2C_MT_SLA_W_ACK) )  /* Check for i2c Status                 */
	{
		return I2C_MT_SLA_W_ERROR;
	}
	else
	{
		return I2C_OK;
	}
	if((WR_Option == I2C_SEND_ADDRESS_WITH_READ) && ( (TWSR_REG &  I2C_STATUS_MASK) != I2C_MT_SLA_R_ACK) )   /* Check for i2c Status                         */
	{
		return I2C_MT_SLA_R_ERROR;
	}
	else
	{
		return I2C_OK;
	}
}



I2C_ErrorState_t I2C_Master_enuData_SR(u8 *I2C_Data , I2C_Data_SR_Option_t DataOption)
{
	if(DataOption == I2C_MASTER_SEND_DATA)                                                                          /* Send Data  */
	{
		TWDR_REG = *I2C_Data;                                                                                       /* Set Data to Reg to send */
	}
	SET_BIT(TWCR_REG , TWINT);
                                                                                    /* Clear the flag to start the operatoin of i2c */
	while(CHECK_BIT(TWCR_REG , TWINT) == 0);
                                                                          /* Polling untill the transmitting done         */
	if( (DataOption == I2C_MASTER_SEND_DATA) && ((TWSR_REG &  I2C_STATUS_MASK) != I2C_MT_DATA_ACK ))                /* Check for i2c Status                         */
	{
		return I2C_MT_DATA_ERROR;
	}
	else
	{
		return I2C_OK;
	}
	if((DataOption == I2C_MASTER_RECIVE_DATA) && ((TWSR_REG &  I2C_STATUS_MASK) != I2C_MR_DATA_ACK ))                  /* Recive Data */
	{
		return I2C_MR_DATA_ERROR;
	}
	else
	{
		*I2C_Data = TWDR_REG;
		SET_BIT(TWCR_REG,TWEA);
		
		return I2C_OK;
	}
}



void I2C_Master_vSendStopCond(void)
{
	  SET_BIT(TWCR_REG , TWSTO);                                                                   /* Send Stop Condition */
	  SET_BIT(TWCR_REG , TWINT);                                                                   /* Clear the flag to start the operation of i2c */
}

void I2C_Slave_vListen(void)
{
	while(CHECK_BIT(TWCR_REG , TWINT) == 0);                                                       /* Polling untill the transmitting done         */
}

I2C_ErrorState_t I2C_Slave_enuReadu8Data(u8 *I2C_Data)
{
	SET_BIT(TWCR_REG , TWINT);                                                                   /* Clear the flag to start the operatoin of i2c */
	while(CHECK_BIT(TWCR_REG , TWINT) == 0);                                                       /* Polling untill the transmitting done         */
	if((TWSR_REG &  I2C_STATUS_MASK) != I2C_SR_DATA_ACK)                                        /* Check for i2c Status                         */
	{
		return I2C_SR_DATA_ERROR;
	}
	else
	{
		*I2C_Data = TWDR_REG;
		return I2C_OK;
	}

}