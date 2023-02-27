/****************************************************************/
/*   Author             :    Gamal Ahmed Gamal 				    */
/*	 Date 				:    25 Feb 2023 						*/
/*	 Version 			:    1.0V 							 	*/
/*	 Description : public Accessing mechanism prototype         */
/****************************************************************/

/****************************************************************/
/* Description   : Guard to protect this File from include more */
/*                 than one time .                              */
/****************************************************************/

#ifndef LCD_H_
#define LCD_H_

void LCD_DATA(unsigned char data);
void LCD_CMD(unsigned char CMD);
void LCD_Init();
void LCD_Write_Char(char Data);
void LCD_Write_String(char *str);
void LCD_Clear();
void LCD_Set_Cursor(unsigned char r, unsigned char c);
void LCD_SR();
void LCD_SL();



#endif 