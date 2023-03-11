/****************************************************************/
/*   Author             :    Gamal Ahmed Gamal 				    */
/*	 Date 				:    10 March 2023 						*/
/*	 Version 			:    1.0V 							 	*/
/*	 Description        : public Accessing mechanism prototype  */
/****************************************************************/

/****************************************************************/
/* Description   : Guard to protect this File from include more */
/*                 than one time .                              */
/****************************************************************/


#ifndef I2C_INTERFACE_H_
#define I2C_INTERFACE_H_

typedef enum event_state
{
	EVENT_OK,
	START_STATE_NOT_SENT,
	REPEATED_START_NOT_SENT,
	SLA_W_ACK_SENT,
	SLA_W_NACK_SENT,
	SLA_R_ACK_SENT,
	SLA_R_NACK_SENT,
	SLA_RW_FAILD,
	DATA_W_ACK_SENT,
	DATA_W_NACK_SENT,
	DATA_W_FAILD,
	DATA_R_ACK_SENT,
	DATA_R_NACK_SENT,
	DATA_R_FAILD
}Event_Status_t;

typedef void (*I2C_callback_t) (void);

/**
 * @brief Macro to Status of master Send & Receive Modes
 */
#define     START_STATE                 0X08            /* Master   */
#define     REPEATED_START_STATE        0X10            /* Master   */

#define     SLAVE_W_ACK_STATE           0X18            /* Master   */
#define     SLAVE_W_NACK_STATE          0X20            /* Master   */

#define     SLAVE_R_ACK_STATE           0X40            /* Master   */
#define     SLAVE_R_NACK_STATE          0X48            /* Master   */
#define     DATA_W_ACK_STATE            0X28            /* Master   */
#define     DATA_W_NACK_STATE           0X30            /* Master   */
#define     DATA_R_ACK_STATE            0X50            /* Master   */
#define     DATA_R_NACK_STATE           0X58            /* Master   */


typedef enum
{
	I2C_SEND_ADDRESS_WITH_WRITE,
	I2C_SEND_ADDRESS_WITH_READ
}I2C_Send_Add_WR_t;

typedef enum
{
	I2C_MASTER_SEND_DATA,
	I2C_MASTER_RECIVE_DATA
}I2C_Data_SR_Option_t;

typedef enum
{
	I2C_OK = 0,
	I2C_SC_ERROR,
	I2C_RSC_ERROR,
	I2C_MT_SLA_R_ERROR,
	I2C_MT_SLA_W_ERROR,
	I2C_MT_DATA_ERROR,
	I2C_MR_DATA_ERROR,
	I2C_SR_DATA_ERROR
}I2C_ErrorState_t;


void I2C_Master_vInit(void);

void I2C_Slave_vInit(u8 I2C_Address);

I2C_ErrorState_t I2C_Master_enuSendSC(void);

I2C_ErrorState_t I2C_Master_enuSendRSC(void);

I2C_ErrorState_t I2C_Master_enuSendSlaveAddress_WR(u8 I2C_Address , I2C_Send_Add_WR_t WR_Option);

I2C_ErrorState_t I2C_Master_enuData_SR(u8 *I2C_Data , I2C_Data_SR_Option_t DataOption);

void I2C_Master_vSendStopCond(void);

void I2C_Slave_vListen(void);

I2C_ErrorState_t I2C_Slave_enuReadu8Data(u8 *I2C_Data);



#endif /* I2C_INTERFACE_H_ */