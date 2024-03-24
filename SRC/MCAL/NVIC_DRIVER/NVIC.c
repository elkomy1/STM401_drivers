#include "stm32f401.h"
#include "NVIC.h"


#define NVIC_BASE_ADDRESS 0xE000E100
#define SCB_BASE_ADDRESS  0xE000E008
#define NVIC_INTERRUPTS 84



typedef struct
{
	volatile u32 ISER[8];
	volatile u32 RESERVED1[24];
	volatile u32 ICER[8];
	volatile u32 RESERVED2[24];
	volatile u32 ISPR[8];
	volatile u32 RESERVED3[24];
	volatile u32 ICPR[8];
	volatile u32 RESERVED4[24];
	volatile u32 IABR[8];
	volatile u32 RESERVED5[56];
	volatile u32 IPR[60];
	volatile u32 Reserved6[580];
	volatile u32 STIR;
} NVIC_t;


typedef struct{

	volatile u32 CPUID;
	volatile u32 ICSR;
	volatile u32 VTOR;
	volatile u32 AIRCR;
	volatile u32 SCR;
	volatile u32 CCR;
	volatile u32 SHPR1;
	volatile u32 SHPR2;
	volatile u32 SHPR3;
	volatile u32 SHCSR;
	volatile u32 CFSR;
	volatile u32 HFSR;
	volatile u32 RESERVED;
	volatile u32 MMAR;
	volatile u32 BFAR;
	volatile u32 AFSR;

}SCB_t;


volatile NVIC_t *const NVIC =(NVIC_t*)NVIC_BASE_ADDRESS ;
volatile SCB_t *const SCB =(SCB_t*)SCB_BASE_ADDRESS ;



/*===========function to enable interrupt=====================*/
Nvic_ErrorState_t NVIC_EnableIRQ(IRQn_t IRQn){
Nvic_ErrorState_t loc_error_state;
u32 index;
if(IRQn>NVIC_INTERRUPTS){
loc_error_state=NVIC_NOK;

}else{
loc_error_state=NVIC_OK;
index=IRQn/32;
NVIC->ISER[index]=(1<<(IRQn%32));

}
return loc_error_state;


}

/*===========function to disable interrupt=====================*/



Nvic_ErrorState_t NVIC_DisableIRQ(IRQn_t IRQn){
    Nvic_ErrorState_t loc_error_state;
u32 index;
if(IRQn>NVIC_INTERRUPTS){
loc_error_state=NVIC_NOK;

}else{
loc_error_state=NVIC_OK;
index=IRQn/32;
NVIC->ICER[index]=(1<<(IRQn%32));

}
return loc_error_state;
}



Nvic_ErrorState_t NVIC_SetPendingIRQ(IRQn_t IRQn){


      Nvic_ErrorState_t loc_error_state;
u32 index;
if(IRQn>NVIC_INTERRUPTS){
loc_error_state=NVIC_NOK;

}else{
loc_error_state=NVIC_OK;
index=IRQn/32;
NVIC->ISPR[index]=(1<<(IRQn%32));

}
return loc_error_state;
}

Nvic_ErrorState_t NVIC_ClearPendingIRQ((IRQn_t IRQn){



      Nvic_ErrorState_t loc_error_state;
u32 index;
if(IRQn>NVIC_INTERRUPTS){
loc_error_state=NVIC_NOK;

}
else{
loc_error_state=NVIC_OK;
index=IRQn/32;
NVIC->ICPR[index]=(1<<(IRQn%32));

}
return loc_error_state;

}

Nvic_ErrorState_t  NVIC_GetActivestate (IRQn_t IRQn,u32 *copy_status){



      Nvic_ErrorState_t loc_error_state;
u32 index;

if(IRQn>NVIC_INTERRUPTS){
loc_error_state=NVIC_NOK;

}
else if(copy_status==NULL){
    loc_error_state=NVIC_NOK;


}


else{
loc_error_state=NVIC_OK;

index=IRQn/32;
*copy_status=(NVIC->[index] >> (IRQn&32)) & 1;

}

return loc_error_state;
}

Nvic_ErrorState_t NVIC_generate_SWInterrupt (IRQn_t IRQn){


    Nvic_ErrorState_t loc_error_state;
 if(IRQn>NVIC_INTERRUPTS){
loc_error_state=NVIC_NOK;

}

else{
    loc_error_state=NVIC_OK;
    NVIC->STIR= IRQn ;

}
return loc_error_state;
}

