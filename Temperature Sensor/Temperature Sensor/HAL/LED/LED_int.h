/*
 * LED_int.h
 *
 *  Created on: Aug 24, 2022
 *      Author: Seif
 */

#ifndef HAL_LED_LED_INT_H_
#define HAL_LED_LED_INT_H_
#include "../../MCAL/DIO/DIO_int.h"

// Check Error Status 

typedef enum {
	
LED_OK,
LED_NOK	
}LED_tenuErrorStatus;


/// Needed Functions///


/*
 * Name: LED_enuTurnOn
 * Description: turn on the led
 * Arguments:  First Argument :    Copy_u8Port      options(DIO_u8_PORTA,DIO_u8_PORTB,DIO_u8_PORTC,DIO_u8_PORTD)
 *             Second Argument:    Copy_u8Pin,         options(from DIO_u8_PIN0 to DIO_u8_PIN7)
 * Return: Error status>>>>>>>>>  LED_OK , LED_NOK
 * */
LED_tenuErrorStatus LED_enuTurnOn(u8 Copy_u8Port,u8 Copy_u8Pin);


/*
 * Name: LED_enuTurnOff
 * Description: turn off the led
 * Arguments:   First Argument :    Copy_u8Port      options(DIO_u8_PORTA,DIO_u8_PORTB,DIO_u8_PORTC,DIO)
 *              Second Argument:    Copy_u8Pin,         options(from DIO_u8_PIN0 to DIO_u8_PIN7)
 * Return: Error status>>>>>>>>>  LED_OK , LED_NOK
 * */
LED_tenuErrorStatus LED_enuTurnOff(u8 Copy_u8Port,u8 Copy_u8Pin);


/*
 * Name: LED_enuToggleLed
 * Description: toggle the led
 * Arguments:  First Argument :    Copy_u8Port      options(DIO_u8_PORTA,DIO_u8_PORTB,DIO_u8_PORTC,DIO_u8_PORTD)
 *             Second Argument:    Copy_u8Pin,         options(from DIO_u8_PIN0 to DIO_u8_PIN7)
 * Return: Error status>>>>>>>>>  LED_OK , LED_NOK
 * */
LED_tenuErrorStatus LED_enuToggle(u8 Copy_u8Port,u8 Copy_u8Pin);






//*************** New Function *****************//
LED_tenuErrorStatus LED_enuReadStatus(u8 Copy_u8Port,u8 Copy_u8Pin , u8* Add_u8Value);

#endif /* HAL_LED_LED_INT_H_ */
