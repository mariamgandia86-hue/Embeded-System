#define SET_BIT(REG,BIT) (REG) |=  (1 << (BIT))
#define CLR_BIT(REG,BIT) (REG) &= ~(1 << (BIT))
#define TOG_BIT(REG,BIT) (REG) ^=  (1 << (BIT))
#define GET_BIT(REG,BIT) (((REG) >> (BIT)) & 0x01)

#define Bit_Is_Set(REG,BIT)   (REG & (1<<BIT))
#define Bit_Is_Clear(REG,BIT) (!(REG & (1<<BIT)))