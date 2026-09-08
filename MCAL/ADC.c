#include "STD_TYPES.h" 
#include "ADC.h"

void ADC_Init (void)
{
	ADMUX_Reg = (1 << 6);
	ADCSRA_Reg = (1 << 7) | (1 << 2) | (1 << 1) | (1 << 0);
}

u16 ADC_Read (u8 Copy_u8Channel)
{

	Copy_u8Channel &= 0x07;
	
	ADMUX_Reg &= 0xE0;
	ADMUX_Reg |= Copy_u8Channel;
	ADCSRA_Reg |= (1 << 6);
	while ( (ADCSRA_Reg & (1 << 6)) != 0 );

	u16 Local_u16Result = ADCL_Reg;
	Local_u16Result |= (ADCH_Reg << 8);
	
	return Local_u16Result;
}