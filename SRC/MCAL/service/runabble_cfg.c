#include"runnable_cfg.h"

#include "scheduler.h"


const Runnable_t Runnable_list[task_num]={


[task1]={.name="toggleled1", .periodicty=10, .cbf=Runnable_toggled_led1},
[task2]={.name="toggleled2", .periodicty=20, .cbf=Runnable_toggled_led2}


};