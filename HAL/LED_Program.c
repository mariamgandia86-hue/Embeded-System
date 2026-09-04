#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "LED_interface.h"

void LED_voidInit(LED_t* Copy_pLED)
{
    DIO_voidSetPinDirection(Copy_pLED->Port, Copy_pLED->Pin, DIO_PIN_OUTPUT);
}

void LED_voidOn(LED_t* Copy_pLED)
{
    if(Copy_pLED->ActiveState == LED_ACTIVE_HIGH)
    {
        DIO_voidSetPinValue(Copy_pLED->Port, Copy_pLED->Pin, DIO_PIN_HIGH);
    }
    else
    {
        DIO_voidSetPinValue(Copy_pLED->Port, Copy_pLED->Pin, DIO_PIN_LOW);
    }
}

void LED_voidOff(LED_t* Copy_pLED)
{
    if(Copy_pLED->ActiveState == LED_ACTIVE_HIGH)
    {
        DIO_voidSetPinValue(Copy_pLED->Port, Copy_pLED->Pin, DIO_PIN_LOW);
    }
    else
    {
        DIO_voidSetPinValue(Copy_pLED->Port, Copy_pLED->Pin, DIO_PIN_HIGH);
    }
}

void LED_voidToggle(LED_t* Copy_pLED)
{
    DIO_voidTogglePin(Copy_pLED->Port, Copy_pLED->Pin);
}