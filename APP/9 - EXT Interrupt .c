

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



void EXT1(void){
	
	
	LED_ON ( RED );
	_delay_ms(500);
	LED_OFF ( RED );
	_delay_ms(500);
	
}




int main(void)
{
	dio_vidConfigChannel(DIO_PORTD , DIO_PIN3, INPUT);
	EXT_voidInit();
	EXT_voidEnable();
	EXT1_voidCallBack(EXT1);
	LED_INIT ();
	GIE_voidEnable();
	
	
	while (1)
	{

		
		
		
	}

}