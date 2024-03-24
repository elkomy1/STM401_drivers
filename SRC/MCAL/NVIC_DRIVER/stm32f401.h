#ifndef STM32F401_H_
#define STM32F401_H_


typedef enum
{
    NVIC_WATCHDOG_TIMER             = 0,
    NVIC_EXTERNAL_LINE16            = 1,
    NVIC_EXTERNAL_LINE21            = 2,
    NVIC_EXTERNAL_LINE22            = 3,
    NVIC_FLASH_INTERRUPT            = 4,
    NVIC_RCC_INTERRUPT              = 5,
    NVIC_EXT0_INTERRUPT             = 6,
    NVIC_EXT1_INTERRUPT             = 7,
    NVIC_EXT2_INTERRUPT             = 8,
    NVIC_EXT3_INTERRUPT             = 9,
    NVIC_EXT4_INTERRUPT             = 10,
    NVIC_DMA1_STREAM0_INTERRUPT     = 11,
    NVIC_DMA1_STREAM1_INTERRUPT     = 12,
    NVIC_DMA1_STREAM2_INTERRUPT     = 13,
    NVIC_DMA1_STREAM3_INTERRUPT     = 14,
    NVIC_DMA1_STREAM4_INTERRUPT     = 15,
    NVIC_DMA1_STREAM5_INTERRUPT     = 16,
    NVIC_DMA1_STREAM6_INTERRUPT     = 17,
    NVIC_ADC_INTERRUPT              = 18,
    NVIC_EXT9_INTERRUPT             = 23,
    NVIC_TIM1_BRK_INTERRUPT         = 24,
    NVIC_TIM1_UP_INTERRUPT          = 25,
    NVIC_TIM1_TRG_INTERRUPT         = 26,
    NVIC_TIM1_CC_INTERRUPT          = 27,
    NVIC_TIM2_INTERRUPT             = 28,
    NVIC_TIM3_INTERRUPT             = 29,
    NVIC_TIM4_INTERRUPT             = 30,
    NVIC_I2C1_EV_INTERRUPT          = 31,
    NVIC_I2C1_ER_INTERRUPT          = 32,
    NVIC_I2C2_EV_INTERRUPT          = 33,
    NVIC_I2C2_ER_INTERRUPT          = 34,
    NVIC_SPI1_INTERRUPT             = 35,
    NVIC_SPI2_INTERRUPT             = 36,
    NVIC_USART1_INTERRUPT           = 37,
    NVIC_USART2_INTERRUPT           = 38,
    NVIC_EXTI15_10_INTERRUPT        = 40,
    NVIC_EXTI17_INTERRUPT           = 41,
    NVIC_EXTI18_INTERRUPT           = 42,
	NVIC_DMA1_STREAM7_INTERRUPT     = 47,
    NVIC_SDIO_INTERRUPT             = 49,
    NVIC_TIM5_INTERRUPT             = 50,
    NVIC_SPI3_INTERRUPT             = 51,
    NVIC_DMA2_STREAM0_INTERRUPT     = 56,
    NVIC_DMA2_STREAM1_INTERRUPT     = 57,
    NVIC_DMA2_STREAM2_INTERRUPT     = 58,
    NVIC_DMA2_STREAM3_INTERRUPT     = 59,
    NVIC_DMA2_STREAM4_INTERRUPT     = 60,
    NVIC_OTG_FS_INTERRUPT           = 67,
    NVIC_DMA2_STREAM5_INTERRUPT     = 68,
    NVIC_DMA2_STREAM6_INTERRUPT     = 69,
    NVIC_DMA2_STREAM7_INTERRUPT     = 70,
    NVIC_USART6_INTERRUPT           = 71,
    NVIC_I2C3_EV_INTERRUPT          = 72,
    NVIC_I2C3_ER_INTERRUPT          = 73,
    NVIC_FPU_INTERRUPT              = 81,
    NVIC_SPI4_INTERRUPT             = 84,
	_NVIC_NUM                       = 85
} IRQn_t;


#endif