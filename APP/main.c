

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
u16 ADCvalue , ADC_Flag ;

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

	
	dio_vidConfigChannel(DIO_PORTA , DIO_PIN0, INPUT);
	ADC_voidInit ();
	ADC_voidEnable();
	ADC_voidInterrputEnable();
	ADC_u8ReadADC(ADC1 , 0 );
	LCD_Init();
	LCD_Set_Cursor(1, 1);
	ADC_voidStartConversion();
	while (1)
	{
		if(ADC_Flag == 1 ) {
			//Present on LCD
			itoa(ADCvalue,String,10);
			LCD_Write_String(String);
			_delay_ms(1000);
			LCD_Write_String("  ");
			LCD_Set_Cursor(1, 1);
			
			ADC_voidStartConversion();
			
			ADC_Flag = 0 ;

		}
		
		
	}

}