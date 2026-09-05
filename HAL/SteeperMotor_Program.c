#include "STD_TYPES.h"
#include "DIO_int.h"
#include "SteeperMotor_Interface.h"


void STEPMOTOR_init(void)
{
	
	DIO_SetPinDirection(PORTC, PIN0, OUTPUT);
	DIO_SetPinDirection(PORTC, PIN1, OUTPUT);
	DIO_SetPinDirection(PORTC, PIN2, OUTPUT);
	DIO_SetPinDirection(PORTC, PIN3, OUTPUT);
}


void FULL_STEP(u8 Direction)
{
	if(Direction == 1) 
	{
		DIO_SetPortValue(PORTC, 0x01); 
		_delay_ms(20);
		
		DIO_SetPortValue(PORTC, 0x02); 
		_delay_ms(20);
		
		DIO_SetPortValue(PORTC, 0x04); 
		_delay_ms(20);
		
		DIO_SetPortValue(PORTC, 0x08); 
		_delay_ms(20);
	}
	else if(Direction == 0) 
	{
		DIO_SetPortValue(PORTC, 0x08);
		_delay_ms(20);
		
		DIO_SetPortValue(PORTC, 0x04);
		_delay_ms(20);
		
		DIO_SetPortValue(PORTC, 0x02);
		_delay_ms(20);
		
		DIO_SetPortValue(PORTC, 0x01);
		_delay_ms(20);
	}
}


void HALF_STEP(u8 Direction)
{
	if(Direction == 1) 
	{
		DIO_SetPortValue(PORTC, 0x01);
		 _delay_ms(20);
		DIO_SetPortValue(PORTC, 0x03);
		 _delay_ms(20);
		DIO_SetPortValue(PORTC, 0x02); 
		_delay_ms(20);
		DIO_SetPortValue(PORTC, 0x06); 
		_delay_ms(20);
		DIO_SetPortValue(PORTC, 0x04); 
		_delay_ms(20);
		DIO_SetPortValue(PORTC, 0x0C); 
		_delay_ms(20);
		DIO_SetPortValue(PORTC, 0x08); 
		_delay_ms(20);
		DIO_SetPortValue(PORTC, 0x09); 
		_delay_ms(20);
	}
	else if(Direction == 0) 
	{
		DIO_SetPortValue(PORTC, 0x09);
		
		 _delay_ms(20);
		DIO_SetPortValue(PORTC, 0x08);
		 _delay_ms(20);
		DIO_SetPortValue(PORTC, 0x0C); 
		_delay_ms(20);
		DIO_SetPortValue(PORTC, 0x04);
		 _delay_ms(20);
		DIO_SetPortValue(PORTC, 0x06); 
		_delay_ms(20);
		DIO_SetPortValue(PORTC, 0x02); 
		_delay_ms(20);
		DIO_SetPortValue(PORTC, 0x03);
		 _delay_ms(20);
		DIO_SetPortValue(PORTC, 0x01);
		 _delay_ms(20);
	}
}