/*
 * LCD_cfg.h
 *
 *  Created on: Aug 26, 2022
 *      Author: Dell
 */

#ifndef HAL_LCD_LCD_CFG_H_
#define HAL_LCD_LCD_CFG_H_

//************ OPTIONS ****************//
/*
 1- eight_bit_mode 
 2- four_bit_mode

*/

#define four_bit_mode


//  RS PIN //
#define LCD_u8_RS_PORT				DIO_u8_PORTA
#define LCD_u8_RS_PIN				DIO_u8_PIN0

// RW PIN //
#define LCD_u8_RW_PORT				DIO_u8_PORTA
#define LCD_u8_RW_PIN				DIO_u8_PIN1

// E PIN //
#define LCD_u8_E_PORT				DIO_u8_PORTA
#define LCD_u8_E_PIN				DIO_u8_PIN2

//DO PIN //
#define LCD_u8_D0_PORT				DIO_u8_PORTC
#define LCD_u8_D0_PIN				DIO_u8_PIN0

//D1 PIN //
#define LCD_u8_D1_PORT				DIO_u8_PORTC
#define LCD_u8_D1_PIN				DIO_u8_PIN1

//D2 PIN //
#define LCD_u8_D2_PORT				DIO_u8_PORTC
#define LCD_u8_D2_PIN				DIO_u8_PIN2

//D3 PIN //
#define LCD_u8_D3_PORT				DIO_u8_PORTC
#define LCD_u8_D3_PIN				DIO_u8_PIN3

//D4 PIN //
#define LCD_u8_D4_PORT				DIO_u8_PORTB
#define LCD_u8_D4_PIN				DIO_u8_PIN4

//D5 PIN //
#define LCD_u8_D5_PORT				DIO_u8_PORTB
#define LCD_u8_D5_PIN				DIO_u8_PIN5

//D6 PIN //
#define LCD_u8_D6_PORT				DIO_u8_PORTB
#define LCD_u8_D6_PIN				DIO_u8_PIN6

//D7 PIN //
#define LCD_u8_D7_PORT				DIO_u8_PORTB
#define LCD_u8_D7_PIN				DIO_u8_PIN7



#define LCD_u8_DATA_LENGTH_MODE         LCD_u8_4_BIT_MODE
#define LCD_u8_NUMBER_OF_LINES          LCD_u8_TWO_LINE
#define LCD_u8_FONT_MODE                LCD_u8_FONT_5_7

//----------------------------------------options----------------------------------------//

/* Data Length */

#define LCD_u8_8_BIT_MODE       0X10
#define LCD_u8_4_BIT_MODE       0X00


/* Number Of Lines */

#define LCD_u8_ONE_LINE         0x00
#define LCD_u8_TWO_LINE         0x08


 /* CHAR FONT */
#define LCD_u8_FONT_5_7			0X00
#define LCD_u8_FONT_5_10		0X04


#endif /* HAL_LCD_LCD_CFG_H_ */
