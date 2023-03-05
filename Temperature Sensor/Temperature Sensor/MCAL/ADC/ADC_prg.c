/*
 * ADC_prg.c
 *
 *  Created on: Sep 4, 2022
 *      Author: Dell
 */

#include "../../LIB/STD_Types.h"
#include "ADC_int.h"
#include "ADC_prv.h"



static u16 ADC_u16Value = 0;
func_ptr_one_argument ADC_pfun ;



ADC_tenuErrorStatus ADC_enuEnable(u8 Copy_ReferenceSelection,u8 Copy_Channel,u8 Copy_u8InterruptMode)
{
	ADC_tenuErrorStatus Local_enuErrorStatus = ADC_OK;

	if( ( ( ADC_u8_VOLTAGE_SELECTION_CHECK(Copy_ReferenceSelection))==0 ) || (Copy_Channel > ADC_u8_ADC7))
	{
		 Local_enuErrorStatus = ADC_NOK;
	}
	else
	{          
		ADC_u8_ADMUX_REG |=Copy_ReferenceSelection;
		ADC_u8_ADMUX_REG |=Copy_Channel;
		ADC_u8_ADCSRA_REG |= 0X06; //PRESCALER = 64 // Freq= 125khzc	//can take 9615 Samples per second
		ADC_u8_ADCSRA_REG |= 0x80; // ADC Enable
		ADC_u8_ADCSRA_REG |= Copy_u8InterruptMode;
	}

	return Local_enuErrorStatus;
}

ADC_tenuErrorStatus ADC_enuStartConvertion(void)
{
	ADC_tenuErrorStatus Local_enuErrorStatus = ADC_OK;
     u16 Local_u16TimeOut=5000;
	ADC_u8_ADCSRA_REG |= 0X40; //Start Conversion

	while((((ADC_u8_ADCSRA_REG>>4) & 0X01) == 0 ) && Local_u16TimeOut--); // Poling on the flag

	if(Local_u16TimeOut == 0)
	{
		 Local_enuErrorStatus = ADC_NOK;
	}
	else
	{
		ADC_u8_ADCSRA_REG |= 0X10; //Clear Flag

	}

	return Local_enuErrorStatus;
}


void ADC_enuDisable(void)
{

	ADC_u8_ADCSRA_REG &= ~(1<<8); // ADC Disable


}

ADC_tenuErrorStatus ADC_enuGetValue(u16* Add_Value)
{
	ADC_tenuErrorStatus Local_enuErrorStatus = ADC_OK;
     if(Add_Value == NULL)
     {
		 Local_enuErrorStatus = ADC_NOK;

     }
     else
     {
    	    *Add_Value=(u16)(ADC_u8_ADCL_REG );
			*Add_Value |=(ADC_u8_ADCH_REG << 8);


     }
	return Local_enuErrorStatus;

}

// NEW FUNCTIONS //

void ADC_enuStartConvertion_Asynchronous(void)
{
   
	ADC_u8_ADCSRA_REG |= 0X40; //Start Conversion
}

ADC_tenuErrorStatus ADC_enuGetValue_Asynch(func_ptr_one_argument Add_pfuncCBF)
{
	ADC_tenuErrorStatus  Local_enuErrorStatus = ADC_OK;
	/* Check Arguments */
	if(Add_pfuncCBF == NULL )
	{
		Local_enuErrorStatus=ADC_NOK;
	}
	else
	{
			ADC_pfun=Add_pfuncCBF;
	}
	return Local_enuErrorStatus;
}




void __vector_16(void)    __attribute__((signal,used));
void __vector_16(void)
{
	ADC_u16Value = (u16)(ADC_u8_ADCL_REG | (ADC_u8_ADCH_REG << 8));
	
	if(ADC_pfun != NULL)
	    ADC_pfun(&ADC_u16Value);
	
}
