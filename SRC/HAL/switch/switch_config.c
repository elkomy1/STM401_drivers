#include "switch.h"
#include "switch_config.h"
switch_stru_config_t arr_of_switches[num_of_switches]{

[switch1]={

    .port=GPIOC_BASE_ADDRESS,
    .switch_pin=GPIO_PIN10,
    .switch_pin_mode=Switch_PinMode_InternalPullup,
     .switch_connection_type=switch_connection_type_INTPU 

},
[switch2]={

   .port=GPIOC_BASE_ADDRESS,
    .switch_pin=GPIO_PIN12,
    .switch_pin_mode=Switch_PinMode_InternalPullup,
     .switch_connection_type=switch_connection_type_INTPU 





}




};