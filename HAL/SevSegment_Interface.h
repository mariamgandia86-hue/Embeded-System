#ifndef SEVSEGMENT_INTERFACE_H_
#define SEVSEGMENT_INTERFACE_H_

#include "../../LIB/STD_TYPES.h"

#define COMMON_CATHODE   0
#define COMMON_ANODE     1

void SevSegment_voidInit(void);
void SevSegment_voidSetValue(u8 Num);

#endif