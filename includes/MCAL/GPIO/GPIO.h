
#ifndef GPIO_H_
#define GPIO_H_

#include "E:\ARM_DRIVERS\lib\STD_TYPES.h"
#include "E:\ARM_DRIVERS\lib\BIT_MATH.h"


   typedef enum{
        Ok,
        Nok
    }GPIO_ErrorStatus_t;

/*================================ base addresses=========================================*/
                #define GPIOA_BASE_ADDRESS				(void *)0x40020000
                #define GPIOB_BASE_ADDRESS				(void *)0x40020400
                #define GPIOC_BASE_ADDRESS				(void *)0x40020800

/*==========================PINS==================================*/

                    #define GPIO_PIN0   0x00000000
                    #define GPIO_PIN1   0x00000001
                    #define GPIO_PIN2   0x00000002
                    #define GPIO_PIN3   0x00000003
                    #define GPIO_PIN4   0x00000004
                    #define GPIO_PIN5   0x00000005
                    #define GPIO_PIN6   0x00000006
                    #define GPIO_PIN7   0x00000007
                    #define GPIO_PIN8   0x00000008
                    #define GPIO_PIN9   0x00000009
                    #define GPIO_PIN10  0X0000000A
                    #define GPIO_PIN11  0X0000000B
                    #define GPIO_PIN12  0X0000000C
                    #define GPIO_PIN13  0X0000000D
                    #define GPIO_PIN14  0X0000000E
                    #define GPIO_PIN15  0X0000000F



/*===============================GPIO_PIN_MODES========================================*/

/*========================================INPUT_MODE====================================*/
#define GPIO_PIN_INPUT_FLOAT         0x00000000
#define GPIO_PIN_INPUT_PULL_UP       0x00010000 
#define GPIO_PIN_INPUT_PULL_DOWN     0x00020000


/*========================================OUTPUT_MODE===================================*/
#define GPIO_PIN_OUTPUT_PUSHPULL_NPP          0x00000001
#define GPIO_PIN_OUTPUT_PUSHPULL_PU           0x00010001
#define GPIO_PIN_OUTPUT_PUSHPULL_PD           0X00020001

#define GPIO_PIN_OUTPUT_OPENDRAIN_NPP         0X00000101
#define GPIO_PIN_OUTPUT_OPENDRAIN_PU          0X00010101
#define GPIO_PIN_OUTPUT_OPENDRAIN_PD          0X00020101

/*============================================ALTERNATE FUNCTION=========================*/
#define GPIO_PIN_ALTFUN_PUSHPULL_NPP          0x00000002
#define GPIO_PIN_ALTFUN_PUSHPULL_PU           0x00010002
#define GPIO_PIN_ALTFUN_PUSHPULL_PD           0x00020002


#define GPIO_PIN_ALTFUN_OPENDRAIN_NP	         0x00000102
#define GPIO_PIN_ALTFUN_OPENDRAIN_PU	         0x00010102
#define GPIO_PIN_ALTFUN_OPENDRAIN_PD	         0x00020102


/*===============================Output Speed================================================*/
#define LOW_SPEED				0x00000000
#define MEDIUM_SPEED			0x00000001
#define HIGH_SPEED				0x00000002
#define VERY_HIGH_SPEED		    0x00000003


/*===============================Lock Configurations flag===============================================*/
#define LOCK			0x01
#define UNLOCK		    0x00


/*=====================================PIN STATUS========================================================*/


#define GPIO_PIN_HIGH      0x00000001


#define GPIO_PIN_LOW      0x00000000


typedef struct 
{

    u32 pin_num;
    void *port;
    u32 pin_mode;
    u32 pin_speed;
    u8 pin_lock_config;
    
}GPIO_PinConfig_t;


/**
 * @brief function used to configure GPIO Pin
 * 
 * @param PtrToPinConfig 
 * @return GPIO_ErrorStatus_t
 * @warning GPIO Port clock must be enabled before initialization 
 */

GPIO_ErrorStatus_t GPIO_INIT(GPIO_PinConfig_t *PtrToPinConfig);
/**
 * @brief 
 * 
 * @param PtrToGPIOPort 
 * @param GPIO_PINnum 
 * @param GPIO_PIN_STATUS 
 * @return GPIO_ErrorStatus_t
 * @warning GPIO Pin must be initialized first using GPIO_Init_Pin()  
 */
GPIO_ErrorStatus_t GPIO_Set_PinValue(void *PtrToGPIOPort,u32 GPIO_PINnum, u32 GPIO_PIN_STATUS);
/**
 * @brief 
 * 
 * @param PtrToGPIOPort 
 * @param GPIO_PINnum 
 * @param PtrToPinstatus 
 * @return Sys_enuErrorStates_t
 * @warning  
 */

GPIO_ErrorStatus_t GPIO_Get_PinValue(void *PtrToGPIOPort,u32 GPIO_PINnum, u8 *PtrToPinstatus);

#endif