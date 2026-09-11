#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_int.h"
#include "SPI_Interface.h"

void main(void)
{
	u8 local_u8ReceivedData = 0;

	SPI_voidInitSlave();
	DIO_SetPinDirection(PORTA, PIN0, OUTPUT);

	while(1)
	{
		local_u8ReceivedData = SPI_u8Tranceive(0xFF);
		if(local_u8ReceivedData == 1)
		{
			DIO_SetPinValue(PORTA, PIN0, HIGH);
		}
		else if(local_u8ReceivedData == 0)
		{
			DIO_SetPinValue(PORTA, PIN0, LOW);  
		}
	}
}