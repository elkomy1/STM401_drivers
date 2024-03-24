#include "switch.h"
#include "switch_config.h"
#include "E:\ARM_DRIVERS\includes\MCAL\GPIO\GPIO.h"

extern const switch_stru_config_t arr_of_switches[num_of_switches];

typedef enum
{
	Switch_Pressed_InternalPU, 
	Switch_Released_InternalPU,
}Switch_stateInternalPU_t;




typedef enum
{
	Switch_Released_ExternalPD,
	Switch_Pressed_ExternalPD, 
}Switch_stateExternalPD_t;



void switch_init(void){


GPIO_PinConfig_t Switch;
Switch.pin_speed=MEDIUM_SPEED;
for(int i=0;i<num_of_switches;i++){

Switch.port=arr_of_switches[i].port;


Switch.pin_num=arr_of_switches[i].switch_pin;
Switch.pin_mode=arr_of_switches[i].switch_pin_mode;
GPIO_INIT(&Switch);

}



}



