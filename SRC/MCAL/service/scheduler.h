#ifndef scheduler_H_
#define scheduler_H_
#include "E:\ARM_DRIVERS\lib\STD_TYPES.h"

#include "E:\ARM_DRIVERS\SRC\MCAL\systick_driver\systick.h"
#include "runnable_cfg.h"



typedef void (*Runnablecbf_t)(void);

typedef struct{

    char *name;
    u32 periodicty;
    Runnablecbf_t  cbf;

}Runnable_t;


void sched_init(void);
void sched_start(void);

#endif