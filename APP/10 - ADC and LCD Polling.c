

#define F_CPU 16000000UL




#include "../LIB/bit_math.h"
#include "../LIB/std_types.h"
#include "../MCAL//DIO/dio.h"
#include "../MCAL//EXT/EXT_Interface.h"
#include "../MCAL/ADC/ADC_Interface.h"
#include "../MCAL/ADC/ADC_Private.h"
#include "../MCAL/ADC/ADC_Config.h"
#include "../MCAL/TIMER0/TMR0_Interface.h"
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

   char String[5];
   u16 value;

	dio_vidConfigChannel(DIO_PORTA , DIO_PIN0, INPUT); 
	ADC_voidInit ();
	ADC_voidEnable();
	LCD_Init();
	LCD_Set_Cursor(1, 1);
	
	while (1)
	{
     
	 
	 value = ADC_u16ReadADCInMV();
	 itoa(value,String,10);
	 LCD_Write_String(String);
	 LCD_Write_String("  ");
	 LCD_Set_Cursor(1, 1);
	_delay_ms(1000);	
	}

}