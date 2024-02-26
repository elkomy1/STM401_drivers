
#include "GPIO.h"



#define mode_shift          0
#define type_shift          8
#define pullup_down_shift   16


#define shift_factor   0x00000002


#define GPIO_CLEAR_MODE_BITS        0x00000003 
#define GPIO_CLEAR_TYPE_BIT         0x00000001
#define GPIO_CLEAR_PUPD_BITS        0x00000003
#define GPIO_CLEAR_SPEED_BITS       0x00000003

#define GPIO_GET_MODE_BITS_VALUE    0x00000003
#define GPIO_GET_TYPE_BIT_VALUE     0x00000100
#define GPIO_GET_PUPD_BITS_VALUE    0x00030000



#define BSRR_OFFSET   16
#define BSRR_BIT_VALUE 1
typedef struct{

u32 volatile GPIO_MODER;
u32 volatile GPIO_OTYPER;
u32 volatile GPIO_OSPEEDR;
u32 volatile GPIO_PUPDR;
u32 volatile GPIO_IDR;
u32 volatile GPIO_ODR;
u32 volatile GPIO_BSRR;
u32 volatile GPIO_LCKR;
u32 volatile GPIO_AFRL;
u32 volatile GPIO_AFRH;


}GPIO_PortRegisters;


#define GPIO_A							((volatile GPIO_PortRegisters*)(GPIOA_BASE_ADDRESS))
#define GPIO_B							((volatile GPIO_PortRegisters*)(GPIOB_BASE_ADDRESS))
#define GPIO_C							((volatile GPIO_PortRegisters*)(GPIOC_BASE_ADDRESS))


GPIO_ErrorStatus_t GPIO_INIT(GPIO_PinConfig_t *PtrToPinConfig)
{
    GPIO_ErrorStatus_t ERROR_STATE=Nok;
    if(PtrToPinConfig->pin_num > GPIO_PIN15)
    {
        ERROR_STATE=Nok;
    
    }
    else if(PtrToPinConfig->port != GPIOA_BASE_ADDRESS && PtrToPinConfig->port != GPIOB_BASE_ADDRESS && PtrToPinConfig->port != GPIOC_BASE_ADDRESS ){


        ERROR_STATE=Nok;
    }
else{

u32 Local_MODER=0;
u32 Local_OTYPER=0;
u32 Local_OSPEEDR=0;
u32 Local_PUPDR=0;
u32 local_modevalue=0x00000000;
u32 local_typevalue=0x00000000;
u32 local_pupdvalue=0x00000000;
 //copy the mode, type and pullup/down configurations to local variables at least siginifcant byte
local_modevalue=(PtrToPinConfig->pin_mode & GPIO_GET_MODE_BITS_VALUE)>>mode_shift;
local_typevalue=(PtrToPinConfig->pin_mode & GPIO_GET_TYPE_BIT_VALUE)>>type_shift;
local_pupdvalue=(PtrToPinConfig->pin_mode & GPIO_GET_PUPD_BITS_VALUE)>>pullup_down_shift;
 //COPY the configurations from the registers to the local variables
Local_MODER=((GPIO_PortRegisters *)PtrToPinConfig->port)->GPIO_MODER;
Local_OTYPER=((GPIO_PortRegisters *)PtrToPinConfig->port)->GPIO_OTYPER;
Local_OSPEEDR=((GPIO_PortRegisters *)PtrToPinConfig->port)->GPIO_OSPEEDR;
Local_PUPDR=((GPIO_PortRegisters *)PtrToPinConfig->port)->GPIO_PUPDR;

//clear the configurations bits

Local_MODER   &=~(GPIO_CLEAR_MODE_BITS<<(PtrToPinConfig->pin_num*shift_factor));
Local_OSPEEDR &=~(GPIO_CLEAR_SPEED_BITS<<(PtrToPinConfig->pin_num*shift_factor));
Local_PUPDR   &=~(GPIO_CLEAR_PUPD_BITS<<(PtrToPinConfig->pin_num*shift_factor));
Local_OTYPER  &=~(GPIO_CLEAR_TYPE_BIT<<(PtrToPinConfig->pin_num));


//assign the configurations values to the registers local variables
 Local_MODER   |= local_modevalue<<(PtrToPinConfig->pin_num*shift_factor);
 Local_OTYPER  |= local_typevalue<<(PtrToPinConfig->pin_num);
 Local_PUPDR   |= local_pupdvalue<<(PtrToPinConfig->pin_num*shift_factor);
 Local_OSPEEDR |=(PtrToPinConfig->pin_speed)<<(PtrToPinConfig->pin_num*shift_factor);



        //copy the value of the local variables to the GPIO Registers
        ((GPIO_PortRegisters *)PtrToPinConfig->port)->GPIO_MODER=Local_MODER;
        ((GPIO_PortRegisters *)PtrToPinConfig->port)->GPIO_OTYPER=Local_OTYPER;
        ((GPIO_PortRegisters *)PtrToPinConfig->port)->GPIO_PUPDR=Local_PUPDR;
        ((GPIO_PortRegisters *)PtrToPinConfig->port)->GPIO_OSPEEDR=Local_OSPEEDR;
}
return ERROR_STATE=Ok;


}



GPIO_ErrorStatus_t GPIO_Set_PinValue(void *PtrToGPIOPort,u32 GPIO_PINnum, u32 GPIO_PIN_STATUS){


GPIO_ErrorStatus_t Error_state;

if(PtrToGPIOPort>GPIOC_BASE_ADDRESS){
    Error_state=Nok;

}


else{


if(GPIO_PIN_STATUS==GPIO_PIN_HIGH){

    ((GPIO_PortRegisters*)PtrToGPIOPort)->GPIO_BSRR |= BSRR_BIT_VALUE<<GPIO_PINnum;
}
else{

    

    ((GPIO_PortRegisters*)PtrToGPIOPort)->GPIO_BSRR |= (BSRR_BIT_VALUE<<(GPIO_PINnum+16));
}
  Error_state=Ok;
}
return Error_state;
}

GPIO_ErrorStatus_t GPIO_Get_PinValue(void *PtrToGPIOPort,u32 GPIO_PINnum, u8 *PtrToPinstatus){



GPIO_ErrorStatus_t Error_state;
if(PtrToGPIOPort>GPIOC_BASE_ADDRESS){
    Error_state=NOk;

}
else if(PtrToGPIOPort==NULL){
    Error_state=Nok;
}

else{

    *PtrToPinstatus=(((GPIO_PortRegisters*)PtrToGPIOPort)->GPIO_IDR>>GPIO_PINnum)&1;
    Error_state=Ok;

}
return Error_state;

}
