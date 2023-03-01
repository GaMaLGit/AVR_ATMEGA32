

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


#define STEP_1 0
#define STEP_2 1
#define STEP_3 2
#define STEP_4 3
#define STEP_5 4


#define STEP_Init 5
#define STEP_RUN  6


int main(void)
{
	
	
	u8 step = STEP_1 ;
	u8 init = STEP_RUN ; 
	 
	u8 B1 = 0 , B2 = 0 , B3 = 0 , B4 = 0 ;
	u8 NB1 = 2 , NB2 = 2 , NB3 = 3 ;
	
	LED_INIT ();
	button_init ();
	LCD_Init();

	
	while (1)
	{
		

		if(button_get_status(BUTTON4) == PRESSED){
			B4++ ;
			_delay_ms(250);
		   LCD_Set_Cursor(1, 1);
		   if(B4 == 1 ){
		   LCD_Write_String("1");
		   }
		   else if ( B4 == 2){
			LCD_Write_String("2");   	   
		   }
		   
			}	
		
		
		
		
		if(B4 == 1 ){
		
		init = STEP_Init ; 	
		NB1 = 0 ; 
		NB2 = 0 ;
		NB3 = 0 ;
		
			
		}
		
		if(B4 == 2 ){
							
		init = STEP_RUN ; 
		B4 = 0 ;		
			
		}
		
		
		if(init == STEP_Init){
			
		if(button_get_status(BUTTON1) == PRESSED){
			NB1++ ;
			_delay_ms(250);
		}
		if(button_get_status(BUTTON2) == PRESSED){
			NB2++ ;
			_delay_ms(250);
		}
		if(button_get_status(BUTTON3) == PRESSED){
			NB3++ ;
			_delay_ms(250);
		}			
				
		}
		
		
		
		if(init == STEP_RUN) {
		
		if(button_get_status(BUTTON1) == PRESSED){
			B1++ ;
			_delay_ms(250);
		}
		if(button_get_status(BUTTON2) == PRESSED){
			B2++ ;
			_delay_ms(250);
		}
		if(button_get_status(BUTTON3) == PRESSED){
			B3++ ;
			_delay_ms(250);
		}
		
		
		
		if(step == STEP_1 ){
				
		if(B1 == NB1){
		step = STEP_2 ; 
			
		}	
		
		if(B2 > NB2 || B3 > NB3 ){
		step = STEP_5 ; 	
			
		}
		
			
		  }
		
		if(step == STEP_2 ){
			
			
			if(B2 == NB2){
				step = STEP_3 ;
				
			}
			if(B1 > NB1 || B3 > NB3 ){
				step = STEP_5 ;
				
			}
			
		}		
		
		
		if(step == STEP_3){
			
			
			if(B3 == NB3){
				step = STEP_4 ;
				
			}
			
			if(B1 > NB1 || B2 > NB2 ){
				step = STEP_5 ;
				
			}			
			
		}		
		
		
		if(step == STEP_4){		
	      LED_ON ( RED );
		  _delay_ms(500);
		  LED_OFF ( RED );
		  B3 = 0 ;
		  B2 = 0 ;
		  B1 = 0 ;	
		  step = STEP_1 ; 
		  	
		}
		
		if(step == STEP_5){
			Buzzer_ON ();
			_delay_ms(500);
			Buzzer_OFF();
			B3 = 0 ;
			B2 = 0 ;
			B1 = 0 ;
			step = STEP_1 ; 
		}		
		
		
		}
		
		
	}

}
