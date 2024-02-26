#ifndef HAL_LED_H_
#define HAL_LED_H_
#include "E:\ARM_DRIVERS\lib\BIT_MATH.h"
#include "E:\ARM_DRIVERS\lib\STD_TYPES.h"
#define led_connection_forward  0x00000000
#define led_connection_backward 0x00000001

#define led_state_on   0x00000001
#define led_state_off  0x00000000
typedef enum{

    LED_NOK,
    LED_OK
}LED_enuErrorState_t;

typedef struct{

    void *port;
    u32 pin_number;
    u32 connection_type;
    u32 led_state;
    
}led_cfg_t;



void LED_Init(void);



LED_enuErrorState_t led_set_state(u8 led,u32 led_state);



LED_enuErrorState_t led_toggle_state(u8 led);
#endif