#ifndef F_CPU
#define F_CPU 1000000UL
#endif

#include <util/delay.h>
#include "../LIB/STD_TYPES.h"
#include "../DIO/DIO_INTERFACE.h" 
#include "LCD_Interface.h"
#define LCD_DATA_PORT      PORTC 
#define LCD_CTRL_PORT      PORTD  

#define RS_PIN             PIN0   
#define RW_PIN             PIN1   
#define EN_PIN             PIN2   

void LCD_SendCommand(u8 command) {
	DIO_SetPortValue(LCD_DATA_PORT, command);
	DIO_SetPinValue(LCD_CTRL_PORT, RS_PIN, LOW);
	DIO_SetPinValue(LCD_CTRL_PORT, RW_PIN, LOW);
	
	DIO_SetPinValue(LCD_CTRL_PORT, EN_PIN, HIGH);
	_delay_us(1);
	DIO_SetPinValue(LCD_CTRL_PORT, EN_PIN, LOW);
	
	_delay_ms(3);
}

void LCD_sendChar(u8 Data) {
	DIO_SetPortValue(LCD_DATA_PORT, Data);
	DIO_SetPinValue(LCD_CTRL_PORT, RS_PIN, HIGH);
	DIO_SetPinValue(LCD_CTRL_PORT, RW_PIN, LOW);
	DIO_SetPinValue(LCD_CTRL_PORT, EN_PIN, HIGH);
	_delay_us(1);
	DIO_SetPinValue(LCD_CTRL_PORT, EN_PIN, LOW);
	
	_delay_ms(1);
}

void LCD_init(void) {
	DIO_SetPortDirection(LCD_DATA_PORT, OUTPUT);
	DIO_SetPinDirection(LCD_CTRL_PORT, RS_PIN, OUTPUT);
	DIO_SetPinDirection(LCD_CTRL_PORT, RW_PIN, OUTPUT);
	DIO_SetPinDirection(LCD_CTRL_PORT, EN_PIN, OUTPUT);
	
	_delay_ms(35);       
	
	LCD_SendCommand(0x38); 
	_delay_us(50);
	
	LCD_SendCommand(0x0C); 
	_delay_us(50);

	LCD_SendCommand(0x06); 
	_delay_us(50);
	
	LCD_SendCommand(0x01); 
	_delay_ms(2);
}

void LCD_SendString(u8 *str) {
	int i = 0;
	while (str[i] != '\0') {
		LCD_sendChar(str[i]);
		i++;
	}
	void GoToXY(u8 x,u8 y){
			u8 local_u8Address;
			
			if (y == 0) {
				local_u8Address = 0x80 + x; 
				} else if (y == 1) {
				local_u8Address = 0xC0 + x; 
			}
			
			LCD_SendCommand(local_u8Address); 
		}

		void LCD_voidWriteNumber(s32 num) {
			u8 arr[10];
			s8 i = 0;

			
			if (num == 0) {
				LCD_sendChar('0');
				return;
			}

			if (num < 0) {
				LCD_sendChar('-');
				num = -num;
			}

			while (num > 0) {
				arr[i] = (num % 10) + '0'; 
				num /= 10;
				i++;
			}

			
			for (i = i - 1; i >= 0; i--) {
				LCD_sendChar(arr[i]);
			}
		}
	}
