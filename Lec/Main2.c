#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"
#include "DIO/DIO_Interface.h"

int main(void)
{
	
	DIO_SetPortDirection(PORTA, INPUT);  
	DIO_SetPortDirection(PORTB, OUTPUT);
	DIO_SetPortDirection(PORTC, OUTPUT); 
	DIO_SetPortDirection(PORTD, OUTPUT); 

	
	DIO_SetPinValue(PORTA, PIN0, HIGH);
	DIO_SetPinValue(PORTA, PIN1, HIGH);
	DIO_SetPinValue(PORTA, PIN2, HIGH);
	DIO_SetPinValue(PORTA, PIN3, HIGH);

	u8 Switch1, Switch2, Switch3, Switch4;

	while (1)
	{
		Switch1 = DIO_GetPinValue(PORTA, PIN0);
		Switch2 = DIO_GetPinValue(PORTA, PIN1);
		Switch3 = DIO_GetPinValue(PORTA, PIN2);
		Switch4 = DIO_GetPinValue(PORTA, PIN3);

		if (Switch4 == 0)
		{
			DIO_SetPortValue(PORTB, 0xFF);
			DIO_SetPortValue(PORTC, 0xFF);
			DIO_SetPortValue(PORTD, 0xFF);
		}
		else
		{
			DIO_SetPortValue(PORTB, 0x00);
			DIO_SetPortValue(PORTC, 0x00);
			DIO_SetPortValue(PORTD, 0x00);

			
			if (Switch1 == 0) DIO_SetPinValue(PORTB, PIN0, HIGH);
			if (Switch2 == 0) DIO_SetPinValue(PORTC, PIN0, HIGH);
			if (Switch3 == 0) DIO_SetPinValue(PORTD, PIN0, HIGH);
		}
	}
}