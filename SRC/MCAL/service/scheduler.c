#include "scheduler.h"

#define TICK_TIME 10

extern const Runnable_t Runnable_list[task_num];
static volatile u32 pendingticks  ;
static void sched(void);
static void Tickcbf(void);





void sched_init(void){

STK_SetConfig( PROCESSOR_ClkSrc_TickInt);
STK_SetCallBack(Tickcbf);
STK_SetTimeMs(TICK_TIME);

}
void sched_start(void){


    STK_Start();
    while(1){
    if(pendingticks){

        pendingticks --;
        sched();
    }

}
}

static void sched(void){
u32 index;
static u32 timestamp=0;
for(index=0;index<task_num;index++){

if((Runnable_list[index].cbf)&&(timestamp % Runnable_list[index].periodicty==0)){

    Runnable_list[index].cbf();
}


}


timestamp=timestamp+TICK_TIME;


}



static void Tickcbf(void){

    pendingticks++;
}

