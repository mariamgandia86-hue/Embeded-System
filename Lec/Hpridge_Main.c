#ifndef F_CPU
#define F_CPU 10000000UL 
#endif
#include "DIO_int.h"
#include <util/delay.h>
#include <avr/io.h> 

int main(void)
{
	
	DDRC = 0b00000011;
	
	while (1)
	{
		
		PORTC = 0b00000001; 
		_delay_ms(500); 
		   
		PORTC = 0b00000000;
		_delay_ms(500);
		
		PORTC = 0b00000010; 
		_delay_ms(500);
		 
		PORTC = 0b00000000;
		_delay_ms(500);   
	}
}