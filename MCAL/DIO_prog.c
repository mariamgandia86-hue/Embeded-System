#include "DIO_Interface.h"

 /* -------------------- DIO PINS -------------------- */

 DIO_ErrorStatus DIO_SetPinDirection(u8 u8Port, u8 u8Pin, u8 u8Direction)
 {
 DIO_ErrorStatus ret = DIO_OK;

 if ((u8Port <= PORTD) && (u8Pin <= PIN7))
 {
 if (u8Direction == OUTPUT)
 {
 switch (u8Port)
 {
 case PORTA: SET_BIT(DDRA_Register, u8Pin); break;
 case PORTB: SET_BIT(DDRB_Register, u8Pin); break;
 case PORTC: SET_BIT(DDRC_Register, u8Pin); break;
 case PORTD: SET_BIT(DDRD_Register, u8Pin); break;
 }
 }
 else if (u8Direction == INPUT)
 {
 switch (u8Port)
 {
 case PORTA: CLR_BIT(DDRA_Register, u8Pin); break;
 case PORTB: CLR_BIT(DDRB_Register, u8Pin); break;
 case PORTC: CLR_BIT(DDRC_Register, u8Pin); break;
 case PORTD: CLR_BIT(DDRD_Register, u8Pin); break;
 }
 }
 else
 {
 ret = DIO_NOK;
 }
 }
 else
 {
 ret = DIO_NOK;
 }

 return ret;
 }

 DIO_ErrorStatus DIO_SetPinValue(u8 u8Port, u8 u8Pin, u8 u8Value)
 {
 DIO_ErrorStatus ret = DIO_OK;

 if ((u8Port <= PORTD) && (u8Pin <= PIN7))
 {
 if (u8Value == HIGH)
 {
 switch (u8Port)
 {
 case PORTA: SET_BIT(PORTA_Register, u8Pin); break;
 case PORTB: SET_BIT(PORTB_Register, u8Pin); break;
 case PORTC: SET_BIT(PORTC_Register, u8Pin); break;
 case PORTD: SET_BIT(PORTD_Register, u8Pin); break;
 }
 }
 else if (u8Value == LOW)
 {
 switch (u8Port)
 {
 case PORTA: CLR_BIT(PORTA_Register, u8Pin); break;
 case PORTB: CLR_BIT(PORTB_Register, u8Pin); break;
 case PORTC: CLR_BIT(PORTC_Register, u8Pin); break;
 case PORTD: CLR_BIT(PORTD_Register, u8Pin); break;
 }
 }
 else
 {
 ret = DIO_NOK;
 }
 }
 else
 {
 ret = DIO_NOK;
 }

 return ret;
 }

 u8 DIO_GetPinValue(u8 u8Port, u8 u8Pin)
 {
 u8 u8Result = 0xFF;

 if ((u8Port <= PORTD) && (u8Pin <= PIN7))
 {
 switch (u8Port)
 {
 case PORTA: u8Result = GET_BIT(PINA_Register, u8Pin); break;
 case PORTB: u8Result = GET_BIT(PINB_Register, u8Pin); break;
 case PORTC: u8Result = GET_BIT(PINC_Register, u8Pin); break;
 case PORTD: u8Result = GET_BIT(PIND_Register, u8Pin); break;
 }
 }

 return u8Result;
 }

 DIO_ErrorStatus DIO_TogglePinValue(u8 u8Port, u8 u8Pin)
 {
 DIO_ErrorStatus ret = DIO_OK;

 if ((u8Port <= PORTD) && (u8Pin <= PIN7))
 {
 switch (u8Port)
 {
 case PORTA: TOG_BIT(PORTA_Register, u8Pin); break;
 case PORTB: TOG_BIT(PORTB_Register, u8Pin); break;
 case PORTC: TOG_BIT(PORTC_Register, u8Pin); break;
 case PORTD: TOG_BIT(PORTD_Register, u8Pin); break;
 default: ret = DIO_NOK; break;
 }
 }
 else
 {
 ret = DIO_NOK;
 }

 return ret;
 }

 /* -------------------- DIO PORTS -------------------- */

 DIO_ErrorStatus DIO_SetPortDirection(u8 u8Port, u8 u8Direction)
 {
 DIO_ErrorStatus ret = DIO_OK;

 if (u8Port <= PORTD)
 {
 switch (u8Port)
 {
 case PORTA: DDRA_Register = u8Direction; break;
 case PORTB: DDRB_Register = u8Direction; break;
 case PORTC: DDRC_Register = u8Direction; break;
 case PORTD: DDRD_Register = u8Direction; break;
 }
 }
 else
 {
 ret = DIO_NOK;
 }

 return ret;
 }

 DIO_ErrorStatus DIO_SetPortValue(u8 u8Port, u8 u8Value)
 {
 DIO_ErrorStatus ret = DIO_OK;

 if (u8Port <= PORTD)
 {
 switch (u8Port)
 {
 case PORTA: PORTA_Register = u8Value; break;
 case PORTB: PORTB_Register = u8Value; break;
 case PORTC: PORTC_Register = u8Value; break;
 case PORTD: PORTD_Register = u8Value; break;
 }
 }
 else
 {
 ret = DIO_NOK;
 }

 return ret;
 }
