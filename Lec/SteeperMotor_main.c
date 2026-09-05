#include "STD_TYPES.h"
#include "DIO_int.h"
#include "SteeperMotor_Interface.h"

int main(void)
{
	
	STEPMOTOR_init();
	
	while(1)
	{
		
		FULL_STEP(1);
	}
	
	return 0;
}