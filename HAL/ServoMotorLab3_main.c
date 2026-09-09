#ifdef  F_CPU
#define F_CPU 16000000UL
#endif
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_int.h"
#include "SERVO_interface.h"
#include <util/delay.h>

int main(void) {
	
	DIO_SetPinDirection(PORTD, PIN5, OUTPUT);
	SERVO_voidInit();
	SERVO_voidSetAngle(0);
		_delay_ms(1000);
	while(1) {
		
		SERVO_voidSetAngle(0);
		_delay_ms(1000);

		
		SERVO_voidSetAngle(90);
		_delay_ms(1000);

		SERVO_voidSetAngle(180);
		_delay_ms(1000);
	}
}