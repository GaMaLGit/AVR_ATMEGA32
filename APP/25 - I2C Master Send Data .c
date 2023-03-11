

#define F_CPU 16000000UL


#include "../LIB/bit_math.h"
#include "../LIB/std_types.h"
#include "../MCAL//DIO/dio.h"
#include "../MCAL//EXT/EXT_Interface.h"
#include "../MCAL//EXT/EXT_Config.h"
#include "../MCAL/ADC/ADC_Interface.h"
#include "../MCAL/ADC/ADC_Private.h"
#include "../MCAL/ADC/ADC_Config.h"
#include "../MCAL/TIMER0/TMR0_Interface.h"
#include "../MCAL/TIMER0/TMR0_Private.h"
#include "../MCAL/TIMER1/TMR1_Interface.h"
#include "../MCAL/TIMER2/TMR2_Interface.h"
#include "../MCAL/UART/UART_Interface.h"
#include "../MCAL/UART/UART_Private.h"
#include "../MCAL/SPI/SPI_Interface.h"
#include "../MCAL/SPI/SPI_Private.h"
#include "../MCAL/GIE/GIE_Interface.h"
#include "../MCAL/I2C/I2C_Interface.h"
#include "../HAL/LED/LED.h"
#include "../HAL/PushButton/PushButton.h"
#include "../HAL/LCD/LCD.h"
#include "../HAL/Keypad/Keypad.h"
#include "../HAL/SSD/SSD.h"
#include <stdlib.h>
#include <util/delay.h>




int main(void)
{
    
	 I2C_Master_vInit();
	 I2C_ErrorState_t Error = I2C_OK;
	 u8 SendData = 48 ;
	  
	while (1)
	{
	
	Error = I2C_Master_enuSendSC();	
	Error = I2C_Master_enuSendSlaveAddress_WR(0x10 , I2C_SEND_ADDRESS_WITH_WRITE);
	I2C_Master_enuData_SR(&SendData , I2C_MASTER_SEND_DATA);
	I2C_Master_vSendStopCond();	
  
    _delay_ms(500);  
		
	}

}