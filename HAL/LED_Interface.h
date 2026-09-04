#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_

#include "../../LIB/STD_TYPES.h"

typedef struct {
    u8 Port;
    u8 Pin;
    u8 ActiveState; 
} LED_t;

#define LED_ACTIVE_HIGH  1
#define LED_ACTIVE_LOW   0

void LED_voidInit(LED_t* Copy_pLED);
void LED_voidOn(LED_t* Copy_pLED);
void LED_voidOff(LED_t* Copy_pLED);
void LED_voidToggle(LED_t* Copy_pLED);

#endif