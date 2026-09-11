#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_int.h"
#include "SPI_interface.h"


#define SPCR    *((volatile u8*)0x2D)
#define SPSR    *((volatile u8*)0x2E)
#define SPDR    *((volatile u8*)0x2F)


#define SPE     6   
#define DORD    5   
#define MSTR    4  
#define CPOL    3   
#define CPHA    2   
#define SPR1    1   
#define SPR0    0   


#define SPIF    7   

void SPI_voidInitMaster(void)
{
	
	DIO_SetPinDirection(PORTB, PIN5, OUTPUT); 
	DIO_SetPinDirection(PORTB, PIN6, INPUT);  
	DIO_SetPinDirection(PORTB, PIN7, OUTPUT); 
	DIO_SetPinDirection(PORTB, PIN4, OUTPUT); 
	
	
	DIO_SetPinValue(PORTB, PIN4, HIGH);

	
	SET_BIT(SPCR, MSTR); 
	CLR_BIT(SPCR, DORD); 
	SET_BIT(SPCR, SPR0); 
	CLR_BIT(SPCR, SPR1);
	SET_BIT(SPCR, SPE);  
}

void SPI_voidInitSlave(void)
{
	
	DIO_SetPinDirection(PORTB, PIN5, INPUT); 
	DIO_SetPinDirection(PORTB, PIN6, OUTPUT); 
	DIO_SetPinDirection(PORTB, PIN7, INPUT); 
	DIO_SetPinDirection(PORTB, PIN4, INPUT); 

	CLR_BIT(SPCR, MSTR); 
	SET_BIT(SPCR, SPE);  
}

u8 SPI_u8Tranceive(u8 Copy_u8Data)
{
	
	SPDR = Copy_u8Data;

	
	while(GET_BIT(SPSR, SPIF) == 0);

	return SPDR;
}