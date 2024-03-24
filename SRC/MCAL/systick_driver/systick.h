#ifndef SYS_H_
#define SYS_H_
#include "E:\ARM_DRIVERS\lib\STD_TYPES.h"


#define AHB8_ClkSrc              0x00000000
#define PROCESSOR_ClkSrc         0x00000004
#define AHB8_ClkSrc_TickInt      0x00000002
#define PROCESSOR_ClkSrc_TickInt 0x00000006

typedef void (*STK_CBF_t)(void);
typedef enum{


    SYST_NOK,
SYST_OK,
}SYSTK_ErrorState_t;


typedef void (*STK_CBF_t)(void);


SYSTK_ErrorState_t STK_Start(void);
 SYSTK_ErrorState_t STK_Stop(void);
  SYSTK_ErrorState_t  STK_SetConfig(u32 mode);
 SYSTK_ErrorState_t STK_SetCallBack(STK_CBF_t Copy_CallBack);

  SYSTK_ErrorState_t STK_SetTimeMs(u32 TimeMs);

#endif