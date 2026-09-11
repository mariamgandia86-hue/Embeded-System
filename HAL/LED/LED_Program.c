#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_int.h"
#include "LED_Interface.h"
void LED_voidInit(void)
{
    
    DIO_voidSetPinDirection(PORTD, PIN0, OUTPUT);
    DIO_voidSetPinDirection(PORTD, PIN1, OUTPUT);
}
void LED_voidFrontOn(void)
{
    DIO_voidSetPinValue(PORTD, PIN0, HIGH);
}
void LED_voidFrontOff(void)
{
    DIO_voidSetPinValue(PORTD, PIN0, LOW);
}
void LED_voidBackOn(void)
{
    DIO_voidSetPinValue(PORTD, PIN1, HIGH);
}

void LED_voidBackOff(void)
{
    DIO_voidSetPinValue(PORTD, PIN1, LOW);
}
void LED_voidToggleFront(void)
{
    static u8 Local_u8State = LOW;
    
    if(Local_u8State == LOW)
    {
        DIO_voidSetPinValue(PORTD, PIN0, HIGH);
        Local_u8State = HIGH;
    }
    else
    {
        DIO_voidSetPinValue(PORTD, PIN0, LOW);
        Local_u8State = LOW;
    }
}