

#define F_CPU 16000000UL


#include "../LIB/bit_math.h"
#include "../LIB/std_types.h"
#include "../MCAL//DIO/dio.h"
#include "../MCAL//EXT/EXT_Interface.h"
#include "../MCAL//EXT/EXT_Config.h"
#include "../MCAL/ADC/ADC_Interface.h"
#include "../MCAL/ADC/ADC_Private.h"
#include "../MCAL/ADC/ADC_Config.h"
#include "../MCAL/TIMER0/TMR0_Interface.h"
#include "../MCAL/TIMER0/TMR0_Private.h"
#include "../MCAL/TIMER1/TMR1_Interface.h"
#include "../MCAL/TIMER2/TMR2_Interface.h"
#include "../MCAL/UART/UART_Interface.h"
#include "../MCAL/UART/UART_Private.h"
#include "../MCAL/SPI/SPI_Interface.h"
#include "../MCAL/SPI/SPI_Private.h"
#include "../MCAL/GIE/GIE_Interface.h"
#include "../MCAL/I2C/I2C_Interface.h"
#include "../HAL/LED/LED.h"
#include "../HAL/PushButton/PushButton.h"
#include "../HAL/LCD/LCD.h"
#include "../HAL/Keypad/Keypad.h"
#include "../HAL/SSD/SSD.h"
#include <stdlib.h>
#include <util/delay.h>


u16 firstReading = 1 , ovf = 0 ,  previousState = 0 ;
volatile u8 flag ;

float ton = 0 ,  toff = 0 ;
char tonSTR[5] , toffSTR[5] ; 


void TMR_0_OverFlow(void){
	ovf++ ;
}


void EXT1_ISR(void){
	
	if(firstReading == 1 ){
	TIMER0_void_Start();
	EXT_voidSetSignalch(Falling);
	firstReading = 2 ; 
	}
	
	else if(firstReading == 2){
	TIMER0_void_Stop();	
	ton = (float)((ovf * 256) + TCNT0)*(1024.0/16000000.0) ;
	ovf = 0 ; 
	TCNT0 = 0 ; 	
	EXT_voidSetSignalch(Rising);
    firstReading = 3 ;	
	TIMER0_void_Start();	
	}
	
	else if(firstReading == 3 ){
	TIMER0_void_Stop();		
	toff = (float)((ovf * 256) + TCNT0)*(1024.0/16000000.0) ;
	ovf = 0 ;
	TCNT0 = 0 ;	
	EXT_voidSetSignalch(Falling);		
	firstReading = 2 ; 
	TIMER0_void_Start();	
	}
	

	
}




int main(void)
{
	char dutyStr[5]  , freqStr[5] ; 
	u16 duty = 0 , freq = 0 ;
	float f = 0 ;
	
	EXT1_voidCallBack(EXT1_ISR);
	TIMER0_void_SetOVCallBack(TMR_0_OverFlow);
    dio_vidConfigChannel(DIO_PORTD , DIO_PIN3, INPUT);
	TIMER0_void_Init();
	TIMER0_void_Stop();	
	TIMER0_void_EnableOVInt();
	TIMER0_void_SetTimerReg(0);
    EXT_voidInit();
    EXT_voidEnable();
	GIE_voidEnable();
	LCD_Init();
	LCD_Set_Cursor(1, 1);
    
	dio_vidConfigChannel(DIO_PORTC , DIO_PIN0, OUTPUT);
	
	while (1)
	{
	 duty = (100 * ton) /( ton + toff);
	 f = 1 / (ton + toff); // Tperiod = TON + TOFF	
     freq =  (u16)f ;
	 
	 itoa(duty,dutyStr,10);
	 LCD_Set_Cursor(1, 1);
	 LCD_Write_String(dutyStr);
	 
	 itoa(freq,freqStr,10);
	 LCD_Set_Cursor(2, 1);
	 LCD_Write_String(freqStr);
	 	  
		
	}

}
