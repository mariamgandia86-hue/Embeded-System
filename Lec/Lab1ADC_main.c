#include "STD_TYPES.h"     
#include "DIO_int.h"        
#include "ADC.h"        


#define LED_PORT        PORTC       
#define RED_LED_PIN     PIN0        
#define YELLOW_LED_PIN  PIN1       
#define GREEN_LED_PIN   PIN2        

#define SWITCH_PORT     PORTD
#define SWITCH_PIN      PIN0        

#define POT_CHANNEL     0          

int main(void)
{
	u16 Local_u16ADCValue = 0;
	u32 Local_u32Voltage_mV = 0;
	u8 Local_u8SwitchState = 0;

	
	ADC_Init(); 

	
	DIO_SetPinDirection(LED_PORT, RED_LED_PIN, 1);
	DIO_SetPinDirection(LED_PORT, YELLOW_LED_PIN, 1);
	DIO_SetPinDirection(LED_PORT, GREEN_LED_PIN, 1);

	
	DIO_SetPinDirection(SWITCH_PORT, SWITCH_PIN, 0);

	while(1)
	{
		Local_u8SwitchState = DIO_GetPinValue(SWITCH_PORT, SWITCH_PIN);

		
		if (Local_u8SwitchState == 1)
		{
			
			Local_u16ADCValue = ADC_Read(POT_CHANNEL);
			Local_u32Voltage_mV = ((u32)Local_u16ADCValue * 5000) / 1024;

			
			if (Local_u32Voltage_mV > 0 && Local_u32Voltage_mV < 1500)
			{
				DIO_SetPinValue(LED_PORT, RED_LED_PIN, 1);     
				DIO_SetPinValue(LED_PORT, YELLOW_LED_PIN, 0);  
				DIO_SetPinValue(LED_PORT, GREEN_LED_PIN, 0);
			}
			else if (Local_u32Voltage_mV >= 1500 && Local_u32Voltage_mV <= 3000)
			{
				DIO_SetPinValue(LED_PORT, RED_LED_PIN, 0);
				DIO_SetPinValue(LED_PORT, YELLOW_LED_PIN, 1);
				DIO_SetPinValue(LED_PORT, GREEN_LED_PIN, 0);
			}
			else if (Local_u32Voltage_mV > 3000)
			{
				DIO_SetPinValue(LED_PORT, RED_LED_PIN, 0);
				DIO_SetPinValue(LED_PORT, YELLOW_LED_PIN, 0);
				DIO_SetPinValue(LED_PORT, GREEN_LED_PIN, 1);
			}
			else
			{
				DIO_SetPinValue(LED_PORT, RED_LED_PIN, 0);
				DIO_SetPinValue(LED_PORT, YELLOW_LED_PIN, 0);
				DIO_SetPinValue(LED_PORT, GREEN_LED_PIN, 0);
			}
		}
		
		else
		{
			DIO_SetPinValue(LED_PORT, RED_LED_PIN, 0);
			DIO_SetPinValue(LED_PORT, YELLOW_LED_PIN, 0);
			DIO_SetPinValue(LED_PORT, GREEN_LED_PIN, 0);
		}
	}

	return 0;
}