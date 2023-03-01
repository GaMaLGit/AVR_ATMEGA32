

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
 
       LED_INIT ();
       button_init ();
	   
    while (1) 
    {
		
		
	if(button_get_status(BUTTON1) == PRESSED){

		 LED_ON ( RED );
		
	}
	else {
		
		LED_OFF ( RED );
		
	}
	
	if(button_get_status(BUTTON2) == PRESSED){

		LED_ON ( GREEN );
		
	}
	else {
		
		LED_OFF ( GREEN );
		
	}
	
	if(button_get_status(BUTTON3) == PRESSED){

		LED_ON ( BLUE );
		
	}
	else {
		
		LED_OFF ( BLUE );
		
	}
		
		
		
   
}

}
