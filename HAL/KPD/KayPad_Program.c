#ifndef F_CPU
#define F_CPU 1000000UL 
#endif

#include <util/delay.h>


#include "../Service/STD_TYPES.h"
#include "../MCAL/DIO_Interface.h"
#include "Keypad_Interface.h"
#include "KPD_Config.h"

static u8 KPD_u8Buttons[4][4] = KPD_KEYS_MATRIX;

void KPD_Init(void) {
	DIO_SetPinDirection(KPD_PORT, KPD_R0, INPUT);
	DIO_SetPinValue(KPD_PORT, KPD_R0, HIGH);

	DIO_SetPinDirection(KPD_PORT, KPD_R1, INPUT);
	DIO_SetPinValue(KPD_PORT, KPD_R1, HIGH);

	DIO_SetPinDirection(KPD_PORT, KPD_R2, INPUT);
	DIO_SetPinValue(KPD_PORT, KPD_R2, HIGH);

	DIO_SetPinDirection(KPD_PORT, KPD_R3, INPUT);
	DIO_SetPinValue(KPD_PORT, KPD_R3, HIGH);

	DIO_SetPinDirection(KPD_PORT, KPD_C0, OUTPUT);
	DIO_SetPinValue(KPD_PORT, KPD_C0, HIGH);

	DIO_SetPinDirection(KPD_PORT, KPD_C1, OUTPUT);
	DIO_SetPinValue(KPD_PORT, KPD_C1, HIGH);

	DIO_SetPinDirection(KPD_PORT, KPD_C2, OUTPUT);
	DIO_SetPinValue(KPD_PORT, KPD_C2, HIGH);

	DIO_SetPinDirection(KPD_PORT, KPD_C3, OUTPUT);
	DIO_SetPinValue(KPD_PORT, KPD_C3, HIGH);
}

u8 KPD_u8GetPressedKey(void) {
	u8 LOC_u8ReturnData = KPD_NO_PRESSED_KEY;
	u8 LOC_u8GetPressed;
	u8 LOC_u8Row;
	u8 LOC_u8Col;

	for (LOC_u8Col = 0 + KPD_COL_INIT; LOC_u8Col < KPD_COL_END + 1; LOC_u8Col++) {
		
		DIO_SetPinValue(KPD_PORT, LOC_u8Col, LOW);

		for (LOC_u8Row = 0 + KPD_ROW_INIT; LOC_u8Row < KPD_ROW_END + 1; LOC_u8Row++) {
			
			LOC_u8GetPressed = DIO_GetPinValue(KPD_PORT, LOC_u8Row);

			if (LOC_u8GetPressed == LOW) {
				
				_delay_ms(50); 
				LOC_u8GetPressed = DIO_GetPinValue(KPD_PORT, LOC_u8Row);

				if (LOC_u8GetPressed == LOW) {
				
					LOC_u8ReturnData = KPD_u8Buttons[LOC_u8Row - KPD_ROW_INIT][LOC_u8Col - KPD_COL_INIT];
					
					while (LOC_u8GetPressed == LOW) {
						LOC_u8GetPressed = DIO_GetPinValue(KPD_PORT, LOC_u8Row);
					}
					
				
					DIO_SetPinValue(KPD_PORT, LOC_u8Col, HIGH);
					return LOC_u8ReturnData;
				}
			}
		}
		
		
		DIO_SetPinValue(KPD_PORT, LOC_u8Col, HIGH);
	}

	return LOC_u8ReturnData;
}