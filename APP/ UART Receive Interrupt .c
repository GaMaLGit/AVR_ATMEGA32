

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
#include "../MCAL/GIE/GIE_Interface.h"
#include "../HAL/LED/LED.h"
#include "../HAL/PushButton/PushButton.h"
#include "../HAL/LCD/LCD.h"
#include "../HAL/Keypad/Keypad.h"
#include "../HAL/SSD/SSD.h"
#include <stdlib.h>
#include <util/delay.h>


u8 String[] = "Done" ;
u8 i ;


void UART_RXComplete(void){

	while(String[i] != '\0'){
		UART_TransmitChr(String[i]);
		i++ ;
	}
   
   i = 0 ;
	
}


int main(void)
{
    UART_VoidRXComplete_Callback(UART_RXComplete);
	UART_Init();
	GIE_voidEnable();
	
	
	while (1)
	{
     
	 
	 
	
		
	}

}
