#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_
#include "../LIB/BIT_MATH.h"
#include "../LIB/STD_TYPES.h"
#include "DIO_Private.h"

#define PORTA 0
#define PORTB 1
#define PORTC 2
#define PORTD 3

/* PIN Defines */
#define PIN0  0
#define PIN1  1
#define PIN2  2
#define PIN3  3
#define PIN4  4
#define PIN5  5
#define PIN6  6
#define PIN7  7

#define INPUT  0
#define OUTPUT 1

#define LOW  0
#define HIGH 1

typedef enum
{
	DIO_NOK,
	DIO_OK
}DIO_ErrorStatus;



/* DIO PINS */
DIO_ErrorStatus DIO_SetPinDirection(u8 u8Port, u8 u8Pin, u8 u8Direction );
DIO_ErrorStatus DIO_SetPinValue(u8 u8Port, u8 u8Pin, u8 u8Value);
u8 DIO_GetPinValue(u8 u8Port, u8 u8Pin);
DIO_ErrorStatus DIO_TogglePinValue(u8 u8Port, u8 u8Pin);

/* DIO PORTS */
DIO_ErrorStatus DIO_SetPortDirection(u8 u8Port,  u8 u8Direction );
DIO_ErrorStatus DIO_SetPortValue(u8 u8Port,  u8 u8Value);


#endif /* DIO_INTERFACE_H_ */