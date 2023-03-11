

#define F_CPU 16000000UL


#include "../LIB/bit_math.h"
#include "../LIB/std_types.h"
#include "../MCAL//DIO/dio.h"
#include "../MCAL//EXT/EXT_Interface.h"
#include "../MCAL/ADC/ADC_Interface.h"
#include "../MCAL/ADC/ADC_Private.h"
#include "../MCAL/ADC/ADC_Config.h"
#include "../MCAL/TIMER0/TMR0_Interface.h"
#include "../MCAL/TIMER1/TMR1_Interface.h"
#include "../MCAL/TIMER2/TMR2_Interface.h"
#include "../MCAL/UART/UART_Interface.h"
#include "../MCAL/UART/UART_Private.h"
#include "../MCAL/SPI/SPI_Interface.h"
#include "../MCAL/SPI/SPI_Private.h"
#include "../MCAL/GIE/GIE_Interface.h"
#include "../HAL/LED/LED.h"
#include "../HAL/PushButton/PushButton.h"
#include "../HAL/LCD/LCD.h"
#include "../HAL/Keypad/Keypad.h"
#include "../HAL/SSD/SSD.h"
#include <stdlib.h>
#include <util/delay.h>





int main(void)
{
    char String[10]  ;
    u8 data = 0 ;
	SPI_Init();
	GIE_voidEnable();
	LCD_Init();
	LCD_Set_Cursor(1, 1);
    dio_vidConfigChannel(DIO_PORTC , DIO_PIN0, OUTPUT); 
	
	
	while (1)
	{
          
	
	 
	 if(CHECK_BIT(SPSR,7)){
		 
		  data = SPI_Tranfere_Byte(3); 
		  itoa(data,String,10);
		  LCD_Write_String(String);
		  LCD_Write_String("  ");
		  LCD_Set_Cursor(1, 1);
	 }
	 
	
	 
	 if(data == 2 ){
		dio_vidWriteChannel(DIO_PORTC,  DIO_PIN0 , STD_HIGH);
		_delay_ms(500);
		dio_vidWriteChannel(DIO_PORTC,  DIO_PIN0 , STD_LOW);
		_delay_ms(500);
		 
	 }
	
	
		
	}

}
