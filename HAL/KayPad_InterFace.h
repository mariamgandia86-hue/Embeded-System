#ifndef KEYPAD_INTERFACE_H_
#define KEYPAD_INTERFACE_H_
#define KPD_NO_PRESSED_KEY   0xFF
void KPD_Init(void);
u8 KPD_u8GetPressedKey(void);

#endif /* KEYPAD_INTERFACE_H_ */