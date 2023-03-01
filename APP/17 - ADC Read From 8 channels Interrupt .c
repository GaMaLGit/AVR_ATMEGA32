

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

char String[5];
u16 ADCvalue;
u8 ADC_Channel , ADC_Flag , LCD_Cursor_Position ;

void ADC1(void){
     
	 ADC_Flag = 1 ; 
	 
	if(Config_ADC[0].Adj == Right_Adjustment){
		ADCvalue = ADC ;
	}
	else if (Config_ADC[0].Adj == Left_Adjustment){
		ADCvalue = ADC >>6 ;
	}
	
}


int main(void)
{

		// make all Port A pins input 
        Dio_WriteChannelGroup(DIO_PORTA , 0x00 , 0x00 );
		
		ADC_u8ReadADC(ADC1 , ADC_Channel );
		ADC_voidInit ();
		ADC_voidEnable();
		ADC_voidInterrputEnable();
		ADC_voidAutoTrigger();
		LCD_Init();
		LCD_Set_Cursor(1, 1);
		GIE_voidEnable();
		
	    ADC_voidStartConversion();
		
	while (1)
	{
		
		if(ADC_Flag == 1 ) {
			//Present on LCD
			itoa(ADCvalue,String,10);
			LCD_Write_String(String);
			LCD_Cursor_Position = LCD_Cursor_Position+5 ;
			LCD_Set_Cursor(1, LCD_Cursor_Position );
			// wait 1 second
			_delay_ms(1000);
			// increment channel 
			ADC_Channel++ ;
			ADC_u8ReadADC(ADC1 , ADC_Channel );
			
			if(ADC_Channel == 7 ){
			  // return to First channel and cursor position	
			  ADC_Channel = 0 ;	
			  LCD_Cursor_Position = 1 ;
			}
			
			ADC_voidStartConversion();
			
		  ADC_Flag = 0 ; 	
		}
		
		
	}

}