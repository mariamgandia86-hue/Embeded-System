#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "TIMER1_interface.h"
#include "TIMER1_private.h"
#include "TIMER1_config.h"

static void (*TIMER1_pvCallBackFunc)(void) = NULL;

void TIMER1_voidInit(void) {
#if TIMER1_MODE == TIMER1_FAST_PWM_ICR1_MODE
   
    SET_BIT(TCCR1A_REG, 7);
    CLR_BIT(TCCR1A_REG, 6);
    
    /* Fast PWM with ICR1 as TOP: WGM13=1, WGM12=1, WGM11=1, WGM10=0 */
    CLR_BIT(TCCR1A_REG, 0);
    SET_BIT(TCCR1A_REG, 1);
    SET_BIT(TCCR1B_REG, 3);
    SET_BIT(TCCR1B_REG, 4);

#elif TIMER1_MODE == TIMER1_NORMAL_MODE
   
    CLR_BIT(TCCR1A_REG, 0);
    CLR_BIT(TCCR1A_REG, 1);
    CLR_BIT(TCCR1B_REG, 3);
    CLR_BIT(TCCR1B_REG, 4);
#endif

    
    TCCR1B_REG = (TCCR1B_REG & TIMER1_PRESCALER_MASK) | TIMER1_PRESCALER;
}

void TIMER1_voidSetICR1(uint16 Copy_u16TopValue) {
    ICR1_REG = Copy_u16TopValue;
}

void TIMER1_voidSetCompareMatchValue(TIMER1_ChannelType Copy_enumChannel, uint16 Copy_u16CompareValue) {
    if (Copy_enumChannel == TIMER1_CHANNEL_A) {
        OCR1A_REG = Copy_u16CompareValue;
    } else if (Copy_enumChannel == TIMER1_CHANNEL_B) {
        OCR1B_REG = Copy_u16CompareValue;
    }
}

void TIMER1_voidSetPWMFrequency(uint32 Copy_u32FrequencyHz) {
    if (Copy_u32FrequencyHz > 0) {
        
        uint32 Local_u32PrescalerVal = 64; 
        uint32 Local_u32TopValue = (TIMER1_SYSTEM_CLOCK_HZ / (Local_u32PrescalerVal * Copy_u32FrequencyHz)) - 1;
        ICR1_REG = (uint16)Local_u32TopValue;
    }
}

void TIMER1_voidSetPWMDutyCycle(TIMER1_ChannelType Copy_enumChannel, uint8 Copy_u8DutyCycle) {
    if (Copy_u8DutyCycle <= 100) {
        uint32 Local_u32CompareVal = ((uint32)Copy_u8DutyCycle * (ICR1_REG + 1)) / 100;
        TIMER1_voidSetCompareMatchValue(Copy_enumChannel, (uint16)Local_u32CompareVal);
    }
}

void TIMER1_voidSetCallBack(void (*Copy_pvoidCallBack)(void)) {
    if (Copy_pvoidCallBack != NULL) {
        TIMER1_pvCallBackFunc = Copy_pvoidCallBack;
    }
}

void TIMER1_voidStop(void) {
    TCCR1B_REG &= TIMER1_PRESCALER_MASK;
}