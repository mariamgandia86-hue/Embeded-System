#include "STD_TYPES.h"      
#include "DIO_int.h"  
#include "ADC.h"           
#define OUTPUT_PORT      PORTC
#define GREEN_LED_PIN    PIN0        
#define YELLOW_LED_PIN   PIN1        
#define RED_LED_PIN      PIN2        
#define BUZZER_PIN       PIN3        

#define LM35_CHANNEL     0           

int main(void)
{
	u16 Local_u16ADCValue = 0;
	u32 Local_u32Voltage_mV = 0;
	u8 Local_u8Temperature = 0;
	ADC_Init();
	DIO_SetPinDirection(OUTPUT_PORT, GREEN_LED_PIN, 1);
	DIO_SetPinDirection(OUTPUT_PORT, YELLOW_LED_PIN, 1);
	DIO_SetPinDirection(OUTPUT_PORT, RED_LED_PIN, 1);
	DIO_SetPinDirection(OUTPUT_PORT, BUZZER_PIN, 1);

	while(1)
	{
		
		Local_u16ADCValue = ADC_Read(LM35_CHANNEL);
		Local_u32Voltage_mV = ((u32)Local_u16ADCValue * 5000) / 1024;
		Local_u8Temperature = Local_u32Voltage_mV / 10;

		if (Local_u8Temperature < 20)
		{
			DIO_SetPinValue(OUTPUT_PORT, GREEN_LED_PIN, 1);
			DIO_SetPinValue(OUTPUT_PORT, YELLOW_LED_PIN, 0);
			DIO_SetPinValue(OUTPUT_PORT, RED_LED_PIN, 0);
			DIO_SetPinValue(OUTPUT_PORT, BUZZER_PIN, 0);
		}
		else if (Local_u8Temperature >= 20 && Local_u8Temperature <= 40)
		{
			DIO_SetPinValue(OUTPUT_PORT, GREEN_LED_PIN, 0);
			DIO_SetPinValue(OUTPUT_PORT, YELLOW_LED_PIN, 1);
			DIO_SetPinValue(OUTPUT_PORT, RED_LED_PIN, 0);
			DIO_SetPinValue(OUTPUT_PORT, BUZZER_PIN, 0);
		}
		else if (Local_u8Temperature > 40)
		{
			DIO_SetPinValue(OUTPUT_PORT, GREEN_LED_PIN, 0);
			DIO_SetPinValue(OUTPUT_PORT, YELLOW_LED_PIN, 0);
			DIO_SetPinValue(OUTPUT_PORT, RED_LED_PIN, 1);
			DIO_SetPinValue(OUTPUT_PORT, BUZZER_PIN, 1);
		}
	}

	return 0;
}