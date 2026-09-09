#ifndef TIMER1_INTERFACE_H_
#define TIMER1_INTERFACE_H_

#include "STD_TYPES.h"
typedef enum {
    TIMER1_NORMAL_MODE = 0,
    TIMER1_CTC_ICR1_MODE,
    TIMER1_FAST_PWM_ICR1_MODE,
    TIMER1_FAST_PWM_OCR1A_MODE
} TIMER1_ModeType;

typedef enum {
    TIMER1_CHANNEL_A = 0,
    TIMER1_CHANNEL_B
} TIMER1_ChannelType;

void TIMER1_voidInit(void);
void TIMER1_voidSetICR1(uint16 Copy_u16TopValue);
void TIMER1_voidSetCompareMatchValue(TIMER1_ChannelType Copy_enumChannel, uint16 Copy_u16CompareValue);
void TIMER1_voidSetPWMFrequency(uint32 Copy_u32FrequencyHz);
void TIMER1_voidSetPWMDutyCycle(TIMER1_ChannelType Copy_enumChannel, uint8 Copy_u8DutyCycle);
void TIMER1_voidSetCallBack(void (*Copy_pvoidCallBack)(void));
void TIMER1_voidStop(void);

#endif /* TIMER1_INTERFACE_H_ */