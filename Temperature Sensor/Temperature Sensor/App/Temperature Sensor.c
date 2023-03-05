/*
 * main.c
 *
 * Created: 22/09/2022 7:53:40 PM
 *  Author: SEIFELDIN AHMED ISMAIL
 */
//#include <avr/interrupt.h>
#include <avr/io.h>
#define F_CPU 8000000UL
#include "util\delay.h"

#include "../LIB/STD_Types.h"
#include "../HAL/PORT/PORT_int.h"
#include "../HAL/LCD/LCD_int.h"
#include "../MCAL/ADC/ADC_int.h"

void function (u16* DigitalValue)
{   LCD_enuSendInstruction(LCD_u8_CLEAR_DISPLAY);
	LCD_enuSendString("Temperature: ");
	// 1 degree ----> 10mv
	// x degree ---->  ?
	u16 AnalogValue = ((*DigitalValue)*5000.0)/1024; // to be in mili volt
	AnalogValue /=10; 
	LCD_enuSendNumber(AnalogValue);
     LCD_enuSendCharacter(0xDF);
     LCD_enuSendCharacter(0x43);
	_delay_ms(300);
	LED_enuTurnOff(DIO_u8_PORTD,0);
}


int main(void)
{
	
	PORT_vidInit();
	LCD_VidInit();
	ADC_enuEnable(ADC_u8_AVCC,ADC_u8_ADC7,ADC_INTERRUPT_ENABLE);
	INT_vidEnableGlobalINT();
	ADC_enuGetValue_Asynch(function);
	_delay_ms(500);
	while(1)
	{        ADC_enuStartConvertion_Asynchronous();
		    LED_enuTurnOn(DIO_u8_PORTD,0);
	}
	
	
	return 0;
}
