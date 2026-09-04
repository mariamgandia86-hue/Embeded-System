#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "SevSegment_config.h"
#include "SevSegment_interface.h"
#include "SevSegment_private.h"

// Common Cathode Values for 0-9
static const u8 SevSeg_Numbers[10] = {0b00111111, 0b00000110, 0b01011011,  0b01001111, 0b01100110, 0b01101101,  0b01111101, 0b00000111, 0b01111111, 0b01101111  };

void SevSegment_voidInit(void)
{
    DIO_voidSetPortDirection(SEVSEG_PORT, 0xFF);
}

void SevSegment_voidSetValue(u8 Num)
{
    if(Num <= 9)
    {
#if SEVSEG_TYPE == COMMON_CATHODE
        DIO_voidSetPortValue(SEVSEG_PORT, SevSeg_Numbers[Num]);
#elif SEVSEG_TYPE == COMMON_ANODE
        DIO_voidSetPortValue(SEVSEG_PORT, ~SevSeg_Numbers[Num]);
#endif
    }
}