

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
 
   LCD_Init();
   LCD_Set_Cursor(1, 1);
   LCD_Write_String("GaMaL");
   LCD_Set_Cursor(2, 1);
   LCD_Write_String("Did");
   LCD_Set_Cursor(3, 1);
   LCD_Write_String("It");
   LCD_Set_Cursor(4, 1);
   LCD_Write_String("again");
	
	   
    while (1) 
    {
		
			
    }

}
