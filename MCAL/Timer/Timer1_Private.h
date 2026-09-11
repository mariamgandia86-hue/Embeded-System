#ifndef TIMER1_PRIVATE_H_
#define TIMER1_PRIVATE_H_


#define TCCR1A_REG            *((volatile uint8*)0x4F)
#define TCCR1B_REG            *((volatile uint8*)0x4E)
#define TCNT1_REG             *((volatile uint16*)0x4C)
#define OCR1A_REG             *((volatile uint16*)0x4A)
#define OCR1B_REG             *((volatile uint16*)0x48)
#define ICR1_REG              *((volatile uint16*)0x46)
#define TIMSK_REG             *((volatile uint8*)0x59)
#define TIMER1_PRESCALER_MASK  0xF8
#define TIMER1_PRESCALER_1     1
#define TIMER1_PRESCALER_8     2
#define TIMER1_PRESCALER_64    3
#define TIMER1_PRESCALER_256   4
#define TIMER1_PRESCALER_1024  5

#endif /* TIMER1_PRIVATE_H_ */