#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_int.h"
#include "UART_int.h"
#include <util/delay.h>

int main(void) {
	UART_Init();
	while (1) {
		
		UART_voidSendData('1');
		_delay_ms(1000);

		
		UART_voidSendData('2');
		_delay_ms(1000);

		
		UART_voidSendData('3');
		_delay_ms(1000);
	}

	return 0;
}
