#ifndef INTERRUPT_PRIVATE_H_
#define INTERRUPT_PRIVATE_H_


#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* Registers Addresses for ATmega32 */
#define MCUCR   *((volatile u8*)0x55)
#define GICR    *((volatile u8*)0x5B)

/* MCUCR Bits */
#define MCUCR_ISC00     0
#define MCUCR_ISC01     1
#define MCUCR_ISC10     2
#define MCUCR_ISC11     3

/* GICR Bits */
#define GICR_INT0       6
#define GICR_INT1       7






#endif /* INTERRUPT_PRIVATE_H_ */