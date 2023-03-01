

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

u16 TMR_Compare_MatchCycles ;

u16 TMR_Delay_S ;



void TMR_0_Compare_Match(void){
	TMR_Compare_MatchCycles++ ;
	TIMER0_void_SetCompareVal(200);
	
	if(TMR_Compare_MatchCycles == (TMR_Delay_S * 78) ){
		LED_TOGGLE( BLUE );
		TMR_Compare_MatchCycles = 0 ;
	}
}

int main(void)
{


	TIMER0_void_SetCTCCallBack(TMR_0_Compare_Match) ;
	TIMER0_void_Init();
	TIMER0_void_EnableCTCInt();
	TIMER0_void_SetCompareVal(200);
	
    LED_INIT ();


	GIE_voidEnable();
				
	
    TMR_Delay_S = 5 ;
	
	
	while (1)
	{
		

		
	}

}