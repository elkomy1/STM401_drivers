    #ifndef RCC_H_
    #define RCC_H_
    #include "STD_TYPES.h"
    #include "BIT_MATH.h"
    typedef enum{
        RCC_Ok,
        RCC_Nok,
    }RCC_ErrorStatus_t;

    typedef enum
    {
        HSI_CLOCKSYS,
        HSE_CLOCKSYS,
        PLL_CLOCKSYS

    }RCC_clock_sys_t;
    /*used to enable and disable clock*/


    #define RCC_HSI    0
    #define RCC_HSE    1
    #define RCC_PLL    2


    #define off 0
    #define on  1

    #define RCC_NotReady 0
    #define RCC_Ready    1
    /////////////////////////////////////////masks/////////////////////////////

    ///////////////////////pll_configurations/////////////////////////
    #define set_PLL_M   0x0000003F
    #define set_PLL_N   0x00007FC0
    #define set_PLL_P   0x00030000
    #define set_PLL_Q   0x0F000000
    #define set_PLL_SRC 0x00400000



    #define SHIFT_PLL_M              0
    #define SHIFT_PLL_N              6
    #define SHIFT_PLL_P              16
    #define SHIFT_PLL_Q              24
    #define SHIFT_PLL_SRC            22
    ///////////////////////////////////////////
    #define HSI_on     0x00000001
    #define HSI_ready  0x00000002

    #define HSE_on     0x00010000
    #define HSE_ready  0x00020000

    #define PLL_on     0x01000000
    #define PLL_ready  0x02000000


    /*used to set pll_clock*/
    #define PLL_HSE    0x00400000   
    #define PLL_HSI    0xFFBFFFFF

    #define PLL_SRC_HSE 0
    #define PLL_SRC_HSI 1

    /*select system clock*/
    #define  MASK_SW                 0x00000003
    #define  MASK_GET_SWS            0x0000000C

    #define MASK_SWS_HSI 			 0x00000000
    #define MASK_SWS_HSE 			 0x00000004
    #define MASK_SWS_PLL 			 0x00000008

    ////////////////////////////*buses*////////////////////////////////
    #define SHIFT_AHB       4
    #define SHIFT_APB1      10
    #define SHIFT_APB2      13

    #define PRE_AHB_ON   0x000000F0
    #define PRE_APB1_ON  0x00001C00
    #define PRE_APB2_ON  0x0000E000

    /*=====================AHB PRESCALER=======================================*/
    #define AHB_0     0b0000
    #define AHB_2     0b1000
    #define AHB_4     0b1001
    #define AHB_8     0b1010
    #define AHB_16    0b1011
    #define AHB_64    0b1100 
    #define AHB_128   0b1101
    #define AHB_256   0b1110
    #define AHB_512   0b1111

    /*====================================APB1 PRESCALER================================*/

    #define APB1_0    0b000
    #define APB1_2    0b100
    #define APB1_4    0b101
    #define APB1_8    0b110
    #define APB1_16   0b111
    /*================APB2 PRESCALERS===================================================*/
    #define APB2_0    0b0000
    #define APB2_2    0b100
    #define APB2_4    0b101
    #define APB2_8    0b110
    #define APB2_16   0b111


    /*=============peripherals for AHB1======================================================*/
    #define GPIOA 0

    #define GPIOB 1
    #define GPIOC 2
    #define GPIOD 3
    #define GPIOE 4
    #define GPIOH 7
    #define CRC   12
    #define DMA1  21
    #define DMA2  22


    /*================peripherals for AHB2=====================================*/
    #define OTGFS 7

    /*=============================APB1===========================================*/
    #define TIM2    0
    #define TIM3    1
    #define TIM4    2
    #define TIM5    3

    #define WWDG    11
    #define SPI2    14
    #define SPI3    15
    #define USART2  17
    #define I2C1    21
    #define I2C2    22
    #define I2C3    23
    #define PWR     28


    /*======================APB2===================================================*/ 
    #define TIM1    0
    #define USART1  4
    #define USART6  5
    #define ADC1    8
    #define SDIO    11
    #define SPI1    12
    #define SPI4    13
    #define SYSCFG  14
    #define TIM9    16
    #define TIM10   17
    #define TIM11   18


    #define AHB1_BUS 0
    #define AHB2_BUS 1
    #define APB1_BUS 2
    #define APB2_BUS 3





    RCC_ErrorStatus_t RCC_SelectClk             (u8 clocksystem);
    RCC_ErrorStatus_t  RCC_ControlClk            (u8 ClockSystem,u8 clock_status);
    RCC_ErrorStatus_t  RCC_CheckReady            (u8 ClockSystem, u8* ReadyStatus);
    RCC_ErrorStatus_t RCC_PLL_SRC(u32 clc_src);
    RCC_ErrorStatus_t  RCC_ConfigPLL             (u32 PLL_M,u32 PLL_N,u32 PLL_P,u32 PLL_Q);
    RCC_ErrorStatus_t  RCC_ControlPrescalerAHB   (u32 AHBPrescaler);
    RCC_ErrorStatus_t  RCC_ControlPrescalerAPB1  (u32 APB1Prescaler);
    RCC_ErrorStatus_t  RCC_ControlPrescalerAPB2  (u32 APB2Prescaler);
    RCC_ErrorStatus_t  RCC_enuEnablePreipheral      (u32 PeripheralBus, u32 Peripheral);
    RCC_ErrorStatus_t  RCC_enuDisablePreipheral     (u32 PeripheralBus, u32 Peripheral);
    #endif
