#include <util/delay.h>   
#include "STD_TYPES.h"    
#include "BIT_MATH.h"    
#include "DIO_int.h" 
#include "ADC.h" 
#define DARKNESS_THRESHOLD   500

int main(void)
{
	 
	ADC_Init(); 
u16 Local_u16ADCResult = 0;
	DIO_SetPinDirection(PORTA, PIN1, OUTPUT);
	DIO_SetPinDirection(PORTA, PIN0, INPUT);

	while(1)
	{
		
		Local_u16ADCResult=ADC_Read(0);
		
		if(Local_u16ADCResult < DARKNESS_THRESHOLD)
		{
			
			DIO_SetPinValue(PORTA, PIN1, HIGH);
		}
		else
		{
			
			DIO_SetPinValue(PORTA,PIN1, LOW);
		}
		
		_delay_ms(100); 
	}
	
	return 0;
}
