#ifndef F_CPU
#define F_CPU 1000000UL
#endif

#include <util/delay.h>
#include "STD_TYPES.h"
#include "DIO_int.h"
#include "LCD_Interface.h"
#include "KayPad_InterFace.h"

int main(void)
{
	u8 local_u8PressedKey;
	s32 local_s32Num1 = 0;
	s32 local_s32Num2 = 0;
	s32 local_s32Result = 0;
	u8 local_u8Operation = 0;
	u8 local_u8State = 0; 
	
	LCD_init();
	KPD_Init();

	while (1)
	{
		
		local_u8PressedKey = KPD_u8GetPressedKey();

		if (local_u8PressedKey != KPD_NO_PRESSED_KEY)
		{
			
			if (local_u8PressedKey == '?')
			{
				LCD_SendCommand(0x01);
				local_s32Num1 = 0;
				local_s32Num2 = 0;
				local_s32Result = 0;
				local_u8Operation = 0;
				local_u8State = 0;
			}
		
			else if (local_u8PressedKey >= '0' && local_u8PressedKey <= '9')
			{
				LCD_sendChar(local_u8PressedKey); 
				
				if (local_u8State == 0)
				{
					
					local_s32Num1 = (local_s32Num1 * 10) + (local_u8PressedKey - '0');
				}
				else
				{
					
					local_s32Num2 = (local_s32Num2 * 10) + (local_u8PressedKey - '0');
				}
			}
			
			else if (local_u8PressedKey == '+' || local_u8PressedKey == '-' || local_u8PressedKey == '*' || local_u8PressedKey == '/')
			{
				LCD_sendChar(local_u8PressedKey); 
				local_u8Operation = local_u8PressedKey;
				local_u8State = 1; 
			}
			
			else if (local_u8PressedKey == '=')
			{
				LCD_sendChar(local_u8PressedKey);
				
			
				switch (local_u8Operation)
				{
					case '+': local_s32Result = local_s32Num1 + local_s32Num2; break;
					case '-': local_s32Result = local_s32Num1 - local_s32Num2; break;
					case '*': local_s32Result = local_s32Num1 * local_s32Num2; break;
					case '/':
					if (local_s32Num2 != 0)
					{
						local_s32Result = local_s32Num1 / local_s32Num2;
					}
					else
					{
						LCD_SendCommand(0x01); 
						LCD_SendString((u8*)"Error Div by 0");
						local_u8State = 2; 
					}
					break;
				}

				
				if (local_u8State != 2)
				{		
							void LCD_voidWriteNumber(s32 num);
			}
		}
	}
	}

	return 0;
}