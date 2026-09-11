#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_int.h"
#include "UART_int.h"

int main(void) {
	u8 Local_u8ReceivedData = 0;
	UART_Init();
	DIO_SetPinDirection(PORTC, PIN0, OUTPUT);
	DIO_SetPinDirection(PORTC, PIN1,OUTPUT);
	DIO_SetPinDirection(PORTC, PIN2, OUTPUT);
	DIO_SetPinValue(PORTC, PIN0, LOW);
	DIO_SetPinValue(PORTC, PIN1,LOW);
	DIO_SetPinValue(PORTC, PIN2, LOW);

	while (1) {
		
		Local_u8ReceivedData = UART_ReceivData();
		switch (Local_u8ReceivedData) {
			case '1':
			DIO_TogglePinValue(PORTC, PIN0);
			break;
			case '2':
			DIO_TogglePinValue(PORTC, PIN1);
			break;
			case '3':
			DIO_TogglePinValue(PORTC, PIN2);
			break;
			default:
			break;
		}
	}

	return 0;
}
