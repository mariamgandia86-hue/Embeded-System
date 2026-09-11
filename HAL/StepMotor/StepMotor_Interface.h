#ifndef STEPMOTOR_INTERFACE_H_
#define STEPMOTOR_INTERFACE_H_

#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>

typedef unsigned char u8;


void STEPMOTOR_init(void);
void FULL_STEP(u8 Direction);
void HALF_STEP(u8 Direction);

#endif /* STEEPERMOTOR_INTERFACE_H_ */