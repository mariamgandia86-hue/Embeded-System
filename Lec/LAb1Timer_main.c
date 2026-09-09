#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_int.h"
#include "Timer0_Interface.h"
#define SREG   *((volatile u8*)0x5F)
#define I_BIT  7
volatile u16 g_u16OverflowCounter = 0;
void Timer0_LED_Toggle_Action(void) {
	g_u16OverflowCounter++;
	
	if (g_u16OverflowCounter == 31) {
		DIO_TogglePinValue(PORTA, PIN0);
		g_u16OverflowCounter = 0;
	}
}

int main(void) {
	DIO_SetPinDirection(PORTA, PIN0, OUTPUT);

	TIMER0_voidSetCallBack(Timer0_LED_Toggle_Action);
	TIMER0_voidInit();

	SET_BIT(SREG, I_BIT);

	while (1) {
		
	}

	return 0;
}