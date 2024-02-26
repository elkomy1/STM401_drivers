#include "E:\ARM_DRIVERS\MCAL\GPIO_DRIVER\GPIO.h"

#include "LED.h"
#include "LED_CONFIG.h"

const led_cfg_t leds[num_of_leds]={

[led1]={
.port=GPIOA_BASE_ADDRESS,
.pin_number=GPIO_PIN0,
.connection_type=led_connection_forward,
.led_state= GPIO_PIN_HIGH 


},
[led2]={
.port=GPIOA_BASE_ADDRESS,
.pin_number=GPIO_PIN3,
.connection_type=led_connection_backward,
.led_state= GPIO_PIN_LOW ,


}


};
