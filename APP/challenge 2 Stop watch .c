

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


#define STEP0 0
#define STEP1 1

int main(void)
{
	u16 ms = 0  , B1ms = 0 , B2ms = 0 ;
	u8 step = 0 ;
	s8 SecDig1 = 0 , SecDig2 = 0 , MinDig1 = 0 , MinDig2 = 0 ;
    SSD_VidInit ();
	button_init ();
	
	while (1)
	{
	SSD_DisplayNum(SecDig1 ,1) ;
	SSD_DisplayNum(SecDig2 ,2) ;	
	SSD_DisplayNum(MinDig1 ,3) ;	
	SSD_DisplayNum(MinDig2 ,4) ;	
	
	if(step == STEP0){
	if(B2ms == 0 ){
	if(button_get_status(BUTTON2) == PRESSED){
      B2ms = 1 ; 
	  SecDig2 ++ ; 
	  if(SecDig2 > 5){
		MinDig1++ ; 
		SecDig2 = 0 ;  
	  }
	  if(MinDig1 > 9){
		 MinDig2++ ; 
		 MinDig1 = 0 ; 
	  }		
	}	
}

	if(B2ms >= 1){
		B2ms ++ ;
		if( B2ms >= 50){
			
			B2ms = 0 ;
		}
		
	}

if(B1ms == 0 ){
	if(button_get_status(BUTTON1) == PRESSED){
		B1ms = 1 ;
		
		if(SecDig2 > 0 ){
		SecDig2 -- ;	
		}
		
		if(SecDig2 <= 0 && MinDig1 > 0 ){
			MinDig1-- ;
			SecDig2 = 5 ;
		}
		if(MinDig1 <= 0 && MinDig2 > 0){
			MinDig2-- ;
			MinDig1 = 9 ;
		}
			
		
	}
	
}
	
	if(B1ms >= 1){
		B1ms ++ ; 
		if( B1ms >= 50){
			
			B1ms = 0 ;
		}	
		
	}
	
	
	
	}
		
	if(button_get_status(BUTTON3) == PRESSED){	
		
	step = STEP1	;
		
	}
		
	if(step == STEP1){
	
	_delay_ms(1);
	ms++ ; 	
	if(ms >= 200){
	ms = 0 ;	
	SecDig1-- ; 
	if(SecDig1 < 0 ){
	SecDig2-- ; 
	SecDig1 = 9 ;	
	}
	if(SecDig2 < 0 && MinDig1 > 0 ){
	MinDig1-- ; 	
	SecDig2 = 5 ; 	
	}
	if(MinDig1 < 0 && MinDig2 > 0 ){
		MinDig2-- ;
		MinDig1 = 9 ;
		
	}
	
		
	}
	
	
	if( SecDig1 < 1 && SecDig2 < 1 && MinDig1 < 1  && MinDig2 < 1   ){
		
		step = STEP0 ; 
		
	}		
		
	}
			
		
	}

}
