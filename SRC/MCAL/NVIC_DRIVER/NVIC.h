#ifndef NVIC_H_
#define NVIC_H_

#define PRIGROUP1  0X05FA0300  /* 4 bits    Preempt group and none subgroup */
#define PRIGROUP2  0X05FA0400  /* 3 bits    preempt group and 1 bits for subgroup */
#define PRIGROUP3  0X05FA0500  /* 2 bits    preempt group and 2 bits for subgroup */
#define PRIGROUP4  0X05FA0600  /* 1 bits    preempt group and 3 bits for subgroup */
#define PRIGROUP5  0X05FA0700  /* none bits preempt group and 4 bits for subgroup*/



typedef enum{

NVIC_OK,
NVIC_NOK,


}Nvic_ErrorState_t;


Nvic_ErrorState_t NVIC_EnableIRQ(IRQn_t IRQn);

Nvic_ErrorState_t NVIC_DisableIRQ(IRQn_t IRQn);


Nvic_ErrorState_t NVIC_SetPendingIRQ(IRQn_t IRQn);
Nvic_ErrorState_t NVIC_ClearPendingIRQ((IRQn_t IRQn);
Nvic_ErrorState_t  NVIC_GetActivestate (IRQn_t IRQn,u32 *copy_status);
Nvic_ErrorState_t NVIC_generate_SWInterrupt (IRQn_t IRQn);
#endif