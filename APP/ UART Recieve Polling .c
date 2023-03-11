

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





int main(void)
{
	u8 String[] = "Done" ;
    u8 i , UART_Data ;
	UART_Init();
	
	
	while (1)
	{
          UART_Data = UART_ReceiveChr();
		if(UART_Data == 'A'){  
	      while(String[i] != '\0'){
		      UART_TransmitChr(String[i]);
		      i++ ;
	      }
	      
	      i = 0 ;
		}
	
		
	}

}
