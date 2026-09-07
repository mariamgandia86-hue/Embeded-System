#include <avr/interrupt.h>
#include <avr/io.h>
#include "BIT_MATH.h"
#include "Interrupt_Interface.h"

int main(void)
{
	DDRD &=~(1<<PD2)&~(1<<PD3);
	PORTD |=(1<<PD2)|(1<<PD3);
	DDRA=0b00000011;
	 initExternalInterrupts();
	sei();
	while (1)
	{
		
	}
}
ISR(INT0_vect){
	 TOG_BIT(PORTA,0);
}
ISR(INT1_vect){
	 TOG_BIT(PORTA,1);
}