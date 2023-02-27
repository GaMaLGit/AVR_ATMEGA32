/****************************************************************/
/*   Author             :    Gamal Ahmed Gamal 				    */
/*	 Date 				:    25 Feb 2023 						*/
/*	 Version 			:    1.0V 							 	*/
/*	 Description        : public Accessing mechanism prototype  */
/****************************************************************/


#ifndef PUSHBUTTON_H_
#define PUSHBUTTON_H_


typedef enum
{
	BUTTON1 =0,
	BUTTON2 =1,
	BUTTON3 =2 ,
	BUTTON4 =3
	
}BUTTON_ID;


typedef enum
{
	RELEASED =0,
	PRESSED =1 
	
}button_id_t;

void button_init (void);
button_id_t button_get_status(BUTTON_ID button_id);



#endif 

/***********************************************************************************************/
/************************************* END OF PROGRAM ******************************************/
/***********************************************************************************************/