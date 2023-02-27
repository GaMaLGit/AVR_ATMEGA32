/****************************************************************/
/*   Author             :    Gamal Ahmed Gamal 				    */
/*	 Date 				:    25 Feb 2023 						*/
/*	 Version 			:    1.0V 							 	*/
/*	 Description 		:    Configure Sense Mode [config.h] 	*/
/****************************************************************/

#ifndef DIO_TYPES_H
#define DIO_TYPES_H



/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef enum
{
	DIO_PORTA =0,	
	DIO_PORTB =1,
	DIO_PORTC =2,
	DIO_PORTD =3
}dio_portId_t;

typedef enum
{
	DIO_PIN0 = 0,
	DIO_PIN1 = 1,
	DIO_PIN2 = 2,
	DIO_PIN3 = 3,
	DIO_PIN4 = 4,
	DIO_PIN5 = 5,
	DIO_PIN6 = 6,
	DIO_PIN7 = 7
}dio_channelId_t;

typedef enum{
	INPUT = 0,
	OUTPUT = 1
}dio_direction_t;

typedef enum{
	STD_LOW = 0,
	STD_HIGH = 1
}dio_level_t;


 
#endif  /* DIO_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: dio_types.h
 *********************************************************************************************************************/
