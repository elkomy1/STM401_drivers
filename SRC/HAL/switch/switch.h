#ifndef _SWITCH_H_
#define _SWITCH_H_
#include "E:\ARM_DRIVERS\lib\STD_TYPES.h"
#include "E:\ARM_DRIVERS\includes\MCAL\GPIO\GPIO.h"





#define Switch_PinMode_InternalPullup    GPIO_PIN_INPUT_PULL_UP
#define Switch_PinMode_InternalPulldown  GPIO_PIN_INPUT_PULL_DOWN



#define switch_connection_type_INTPU    0x00000001

#define switch_connection_type_INTPD    0x00000000




#define Switch_Released  0x00000000
#define Switch_Pressed   0x00000001

typedef enum{

    switch_released,
    switch_pressed
}switch_staus;

typedef enum{

switch_Nok,
switch_Ok,

}Switch_ErrorState_t;


typedef struct{

    void *port;

    u32 switch_pin;
    u32 switch_pin_mode;
    u32 switch_connection_type;
    
}switch_stru_config_t;


void switch_init(void);

Switch_ErrorState_t switch_enuSetState(u32 switch ,u32 *switchstatus);
#endif