/*
 * LED_prg.c

 *
 *  Created on: Aug 24, 2022
 *      Author: Seif
 */

#include "../../LIB/STD_Types.h"

#include "LED_int.h"


/*
 * Name: LED_enuTurnOn
 * Description: turn on the led
 * Arguments:   void
 * Return: Error status>>>>>>>>>   LED_OK , LED_NOK
 * */
LED_tenuErrorStatus LED_enuTurnOn(u8 Copy_u8Port,u8 Copy_u8Pin)
{
	LED_tenuErrorStatus Local_enuErrorStatus = LED_OK;
	if(DIO_enuSetPinValue (Copy_u8Port, Copy_u8Pin,DIO_u8_HIGH)== DIO_NOK)
	{
		Local_enuErrorStatus=LED_NOK;
	}
	return Local_enuErrorStatus;
}


/*
 * Name: LED_enuTurnOff
 * Description: turn off the led
 * Arguments:   First Argument :    Copy_u8Port      options(DIO_u8_PORTA,DIO_u8_PORTB,DIO_u8_PORTC,DIO)
 *              Second Argument:    Copy_u8Pin,         options(from DIO_u8_PIN0 to DIO_u8_PIN7)
 * Return: Error status>>>>>>>>>   LED_OK , LED_NOK
 * */
LED_tenuErrorStatus LED_enuTurnOff(u8 Copy_u8Port,u8 Copy_u8Pin)
{
	    LED_tenuErrorStatus Local_enuErrorStatus = LED_OK;
		if(DIO_enuSetPinValue (Copy_u8Port, Copy_u8Pin,DIO_u8_LOW)== DIO_NOK)
		{
			Local_enuErrorStatus=LED_NOK;
		}
		return Local_enuErrorStatus;
}




/*
 * Name: LED_enuToggleLed
 * Description: toggle the led
 * Arguments:  First Argument :    Copy_u8Port      options(DIO_u8_PORTA,DIO_u8_PORTB,DIO_u8_PORTC,DIO_u8_PORTD)
 *             Second Argument:    Copy_u8Pin,         options(from DIO_u8_PIN0 to DIO_u8_PIN7)
 * Return: Error status>>>>>>>>>  LED_OK , LED_NOK
 * */
LED_tenuErrorStatus LED_enuToggle(u8 Copy_u8Port,u8 Copy_u8Pin)
{
    LED_tenuErrorStatus Local_enuErrorStatus = LED_OK;
	
           if(DIO_enuTogglePin( Copy_u8Port, Copy_u8Pin)== DIO_NOK)
		   {
			   Local_enuErrorStatus=LED_NOK;
		   }
	return Local_enuErrorStatus;
}

LED_tenuErrorStatus LED_enuReadStatus(u8 Copy_u8Port,u8 Copy_u8Pin , u8* Add_u8Value)
{
	LED_tenuErrorStatus Local_enuErrorStatus = LED_OK;
	
	if(DIO_enuGetPinValue( Copy_u8Port, Copy_u8Pin,Add_u8Value)== DIO_NOK)
	{
		Local_enuErrorStatus=LED_NOK;
	}
	return Local_enuErrorStatus;
}
