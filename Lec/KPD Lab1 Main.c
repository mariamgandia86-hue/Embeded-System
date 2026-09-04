#ifndef F_CPU
#define F_CPU 1000000UL
#endif

#include <util/delay.h>
#include "Service/STD_TYPES.h"
#include "MCAL/DIO_Interface.h"
#include "HAL/Keypad_InterFace.h"

int main(void)
{
	u8 local_u8PressedKey;
	u8 local_au8SevSegDec[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};

	KPD_Init();

	DIO_SetPortDirection(PORTB, 0xFF);
	
	
	DIO_SetPortValue(PORTB, local_au8SevSegDec[0]);

	while (1)
	{
		
		local_u8PressedKey = KPD_u8GetPressedKey();


		if (local_u8PressedKey != KPD_NO_PRESSED_KEY)
		{

			if (local_u8PressedKey >= '1' && local_u8PressedKey <= '9')
			{
				
				u8 local_u8Number = local_u8PressedKey - '0';

				
				DIO_SetPortValue(PORTB, local_au8SevSegDec[local_u8Number]);
			}
		}
	}

	return 0;
}