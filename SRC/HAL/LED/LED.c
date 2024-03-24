#include "LED.h"
#include "GPIO.h"

#include "LED_CONFIG.h"


   const led_cfg_t leds[num_of_leds];
void LED_Init(void){


   GPIO_PinConfig_t led;

   led.pin_mode= GPIO_PIN_OUTPUT_PUSHPULL_NPP  ;

   led.pin_speed= MEDIUM_SPEED;

   for(int i=0;i<num_of_leds;i++){

        led.port=leds[i].port;
        led.pin_num=leds[i].pin_number;

                GPIO_INIT(&led);
                GPIO_Set_PinValue(leds[i].port,leds[i].pin_number,leds[i].default_state);

   }







}




LED_enuErrorState_t led_set_state(u8 led,u32 led_state){

        LED_enuErrorState_t error_state;

        if(led>num_of_leds){
            error_state=LED_NOK;
        }
        else{

                u32 pin_state=0;

                pin_state=leds[led].connection_type^led_state;
                GPIO_Set_PinValue(leds[led].port,leds[led].pin_number,pin_state);

                error_state=LED_OK;


        }


return error_state;

}
LED_enuErrorState_t led_toggle(u8 led) {
    LED_enuErrorState_t error_state;

    if (led > num_of_leds) {
        error_state = LED_NOK;
    } else {
        // Toggle the LED state
        u32 pin_state = GPIO_Get_PinValue(leds[led].port, leds[led].pin_number);
        pin_state ^= 1; // Toggle the state by XOR with 1 (assuming 1 corresponds to the GPIO pin high state)
        GPIO_Set_PinValue(leds[led].port, leds[led].pin_number, pin_state);

        error_state = LED_OK;
    }

    return error_state;
}



