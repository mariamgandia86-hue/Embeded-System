#define F_CPU 16000000UL
#include <util/delay.h>

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO.h"
#include "ADC2.h"
#include "TIMER0.h"

int main(void) {
   
    DIO_voidSetPinDirection(DPORTC, PIN0, OUTPUT);
    ADC_voidInit();
    TIMER0_voidInitCTC();

    u16 Local_u16AdcVal = 0;
    u8  Local_u8OcrVal  = 0;

    while (1) {
  
        Local_u16AdcVal = ADC_u16ReadChannel(0);
        Local_u8OcrVal = (u8)(Local_u16AdcVal / 4);
        if (Local_u8OcrVal == 0) {
            Local_u8OcrVal = 1;
        }

  
        TIMER0_voidSetOCR0(Local_u8OcrVal);

        _delay_ms(50);
    }

    return 0;
}