#ifndef KPD_CONFIG_H_
#define KPD_CONFIG_H_
#define KPD_PORT       PORTC
#define KPD_ROW_INIT   PIN0
#define KPD_ROW_END    PIN3
#define KPD_COL_INIT   PIN4
#define KPD_COL_END    PIN7

#define KPD_R0         PIN0
#define KPD_R1         PIN1
#define KPD_R2         PIN2
#define KPD_R3         PIN3

#define KPD_C0         PIN4
#define KPD_C1         PIN5
#define KPD_C2         PIN6
#define KPD_C3         PIN7

#define KPD_KEYS_MATRIX { \
    {'7', '8', '9', '/'}, \
    {'4', '5', '6', '*'}, \
    {'1', '2', '3', '-'}, \
    {'?', '0', '=', '+'}  \
}

#endif /* KPD_CONFIG_H_ */