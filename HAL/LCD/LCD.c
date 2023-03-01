/****************************************************************/
/*   Author             :    Gamal Ahmed Gamal 				    */
/*	 Date 				:    25 Feb 2023 						*/
/*	 Version 			:    1.0V 							 	*/
/*   Description	    :    prog.c for LCD	                    */
/****************************************************************/

/****************************************************************/
/******************************* Macros *************************/
/****************************************************************/

#define F_CPU 16000000UL

/****************************************************************/
/*********************** Component DIRECTIVES *******************/
/****************************************************************/

#include "../HAL/LCD/LCD.h"
#include "../HAL/LCD/LCD_CFG.h"
#include "../MCAL/DIO/dio.h"
#include <util/delay.h>

/****************************************************************/
/* Description    :  This function used to Send Data to LCD     */
/*					 Inputs : u8 data			     			*/
/*					 return : void		 						*/
/****************************************************************/

void LCD_DATA(u8 data){	
	if(data & 1)
	dio_vidWriteChannel(Config_LCD->LCD_DATA_PORT, Config_LCD->D4 , STD_HIGH );
	else
	dio_vidWriteChannel(Config_LCD->LCD_DATA_PORT, Config_LCD->D4 , STD_LOW );
	if(data & 2)
	dio_vidWriteChannel(Config_LCD->LCD_DATA_PORT, Config_LCD->D5 , STD_HIGH );
	else
	dio_vidWriteChannel(Config_LCD->LCD_DATA_PORT, Config_LCD->D5 , STD_LOW );
	if(data & 4)
	dio_vidWriteChannel(Config_LCD->LCD_DATA_PORT, Config_LCD->D6 , STD_HIGH );
	else
	dio_vidWriteChannel(Config_LCD->LCD_DATA_PORT, Config_LCD->D6 , STD_LOW );
	if(data & 8)
	dio_vidWriteChannel(Config_LCD->LCD_DATA_PORT, Config_LCD->D7 , STD_HIGH );
	else
	dio_vidWriteChannel(Config_LCD->LCD_DATA_PORT, Config_LCD->D7 , STD_LOW );
}

/****************************************************************/
/* Description    :  This function used to Send Command to LCD  */
/*					 Inputs : unsigned char CMD					*/
/*					 return : void		 						*/
/****************************************************************/

void LCD_CMD(unsigned char CMD){
	// Select Command Register
	dio_vidWriteChannel(Config_LCD->LCD_Control_PORT ,Config_LCD->RS , STD_LOW );
	// Move The Command Data To LCD
	LCD_DATA(CMD);
	// Send The EN Clock Signal
	dio_vidWriteChannel(Config_LCD->LCD_Control_PORT ,Config_LCD->EN , STD_HIGH);
	_delay_us(500); 
	dio_vidWriteChannel(Config_LCD->LCD_Control_PORT ,Config_LCD->EN , STD_LOW);
}

/****************************************************************/
/* Description    :  This function used to initialize LCD       */
/*					 Inputs : void				             	*/
/*					 return : void		 						*/
/****************************************************************/

void LCD_Init(){
	// IO Pin Configurations
	
	 dio_vidConfigChannel(Config_LCD->LCD_DATA_PORT ,Config_LCD->D4 , OUTPUT);	
	 dio_vidConfigChannel(Config_LCD->LCD_DATA_PORT ,Config_LCD->D5 , OUTPUT);	
	 dio_vidConfigChannel(Config_LCD->LCD_DATA_PORT ,Config_LCD->D6 , OUTPUT);	
	 dio_vidConfigChannel(Config_LCD->LCD_DATA_PORT ,Config_LCD->D7 , OUTPUT);
	 dio_vidConfigChannel(Config_LCD->LCD_Control_PORT ,Config_LCD->RS , OUTPUT);	
	 dio_vidConfigChannel(Config_LCD->LCD_Control_PORT ,Config_LCD->EN , OUTPUT);	
	// The Initiate Procedure
	LCD_DATA(0x00);
	_delay_ms(30);  	
	_delay_us(500); 
	LCD_CMD(0x03);
	_delay_ms(5);
	LCD_CMD(0x03);
	_delay_us(150);
	LCD_CMD(0x03);
	LCD_CMD(0x02);
	LCD_CMD(0x02);
	LCD_CMD(0x08);
	LCD_CMD(0x00);
	LCD_CMD(0x0C);
	LCD_CMD(0x00);
	LCD_CMD(0x06);
	LCD_Clear();
}

/*******************************************************************/
/* Description    :  This function used to write character to LCD  */
/*					 Inputs : char Data				               */
/*					 return : void		 						   */
/*******************************************************************/

void LCD_Write_Char(char Data){
	char Low4,High4;
	Low4 = Data & 0x0F;
	High4 = Data & 0xF0;
	dio_vidWriteChannel(Config_LCD->LCD_Control_PORT ,Config_LCD->RS , STD_HIGH );  // select data mode
	LCD_DATA(High4>>4);
	dio_vidWriteChannel(Config_LCD->LCD_Control_PORT ,Config_LCD->EN , STD_HIGH);
	_delay_us(500); 
	dio_vidWriteChannel(Config_LCD->LCD_Control_PORT ,Config_LCD->EN , STD_LOW);
	_delay_us(500); 
	LCD_DATA(Low4);
	dio_vidWriteChannel(Config_LCD->LCD_Control_PORT ,Config_LCD->EN , STD_HIGH);
	_delay_us(500); 
	dio_vidWriteChannel(Config_LCD->LCD_Control_PORT ,Config_LCD->EN , STD_LOW);
	_delay_us(500); 
}

/*******************************************************************/
/* Description    :  This function used to write String to LCD     */
/*					 Inputs : char *str				               */
/*					 return : void		 						   */
/*******************************************************************/

void LCD_Write_String(char *str){
	int i;
	for(i=0;str[i]!='\0';i++)
	LCD_Write_Char(str[i]);
}

/*******************************************************************/
/* Description    :  This function used to Clear the LCD           */
/*					 Inputs : void			                       */
/*					 return : void		 						   */
/*******************************************************************/

void LCD_Clear(){
	LCD_CMD(0);
	LCD_CMD(1);
}

/*******************************************************************/
/* Description    :  This function used to Set the cursor position */
/*					 Inputs : unsigned char row	                   */
/*                            unsigned char column				   */
/*					 return : void		 						   */
/*******************************************************************/

void LCD_Set_Cursor(unsigned char r, unsigned char c) { // r = ROW , c = Column
	unsigned char Temp,Low4,High4;
	if(r == 1)
	{
		Temp = 0x80 + c - 1; //0x80 is used to move the cursor
		High4 = Temp >> 4;
		Low4 = Temp & 0x0F;
		LCD_CMD(High4);
		LCD_CMD(Low4);
	}
	if(r == 2)
	{
		Temp = 0xC0 + c - 1;
		High4 = Temp >> 4;
		Low4 = Temp & 0x0F;
		LCD_CMD(High4);
		LCD_CMD(Low4);
	}
	if(r == 3)
	{
		Temp = 0x94 + c - 1;
		High4 = Temp >> 4;
		Low4 = Temp & 0x0F;
		LCD_CMD(High4);
		LCD_CMD(Low4);
	}
	if(r == 4)
	{
		Temp = 0xD4 + c - 1;
		High4 = Temp >> 4;
		Low4 = Temp & 0x0F;
		LCD_CMD(High4);
		LCD_CMD(Low4);
	}
}


/***************************************************************************/
/* Description    :  This function used to shift all the display to right  */
/*					 Inputs : void			                               */
/*					 return : void		 						           */
/***************************************************************************/

void LCD_SR(){ 
	LCD_CMD(0x01);
	LCD_CMD(0x0C);
}

/***************************************************************************/
/* Description    :  This function used to shift all the display to Left   */
/*					 Inputs : void			                               */
/*					 return : void		 						           */
/***************************************************************************/

void LCD_SL(){ 
	LCD_CMD(0x01);
	LCD_CMD(0x08);
}


