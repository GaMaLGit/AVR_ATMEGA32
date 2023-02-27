//****************************************************************/
/*   Author             :    Gamal Ahmed Gamal 				     */
/*	 Date 				:    25 Feb 2023 						 */
/*	 Version 			:    1.0V 							 	 */
/*	 Description : public Accessing mechanism prototype          */
/*				   and DIO Definition [int.h]                    */
/*****************************************************************/

#ifndef DIO_H_H
#define DIO_H_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "dio_types.h"
#include "bit_math.h"
#include "dio_reg.h"
#include "std_types.h"


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
void dio_vidConfigChannel(dio_portId_t port, dio_channelId_t channel, dio_direction_t direction);
void dio_vidWriteChannel(dio_portId_t port, dio_channelId_t channel, dio_level_t level);
void Dio_WriteChannelGroup(dio_portId_t port , u8 mask , u8 value );
void dio_vidFlipChannel(dio_portId_t port, dio_channelId_t channel);
dio_level_t dio_dioLevelReadChannel(dio_portId_t port, dio_channelId_t channel);
void dio_vidEnablePullUp(dio_portId_t port, dio_channelId_t channel);
u8 Dio_ReadChannelGroup(dio_portId_t port , u8 mask );

 
#endif  /* DIO_H_H */

/**********************************************************************************************************************
 *  END OF FILE: dio.h
 *********************************************************************************************************************/
