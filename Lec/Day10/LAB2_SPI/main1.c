#define F_CPU 8000000UL
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_int.h"
#include "SPI_interface.h"
#include <util/delay.h>

void  main(void)
{
	SPI_voidInitMaster();

	
	DIO_SetPinValue(PORTB, PIN4, LOW);

	while(1)
	{
		
		SPI_u8Tranceive(1);
		_delay_ms(1000);

		
		SPI_u8Tranceive(0);
		_delay_ms(1000);
	}
}

