

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
   
    dio_vidConfigChannel(DIO_PORTC , DIO_PIN0, OUTPUT);  

    while (1) 
    {
		dio_vidWriteChannel(DIO_PORTC,  DIO_PIN0 , STD_HIGH);
		 _delay_ms(500);  	
		dio_vidWriteChannel(DIO_PORTC,  DIO_PIN0 , STD_LOW);
		 _delay_ms(500); 
    }
	
}

