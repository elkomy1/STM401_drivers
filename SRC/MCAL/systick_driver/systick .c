        #include "systick.h"

        #define STK_BASE_ADDRESS  0xE000E010
        #define STK_START_MASK    0x00000001
        #define STK_STOP_MASK     0x00000000


        #define STK_SRC         0x00000004
        #define STK_ClearMode   0xFFFFFFF9
        #define LOW_RELOAD      0x00000001
        #define HIGH_RELOAD     0x00FFFFFF

        #define CLK_FREQUENCY_MHZ 16000000





        typedef struct
        {
            u32 STK_CTRL;
            u32 STK_LOAD;
            u32 STK_VAL;
            u32 STK_CALIB;
        } STK_PERI_t;


        volatile STK_PERI_t *const STK = (volatile STK_PERI_t *)STK_BASE_ADDRESS;

        static STK_CBF_t APP_CBF = NULL;

        SYSTK_ErrorState_t STK_Start(void){


                                    SYSTK_ErrorState_t loc_error_state=SYST_OK;
                                    u32 loc_temp=STK->STK_CTRL;
                                    loc_temp |= STK_START_MASK;
                                    STK->STK_CTRL=loc_temp;

                                    return loc_error_state;
                                        }

        SYSTK_ErrorState_t STK_Stop(void){


                            SYSTK_ErrorState_t loc_error_state=SYST_OK;
                            u32 loc_temp=STK->STK_CTRL;
                            loc_temp |= STK_STOP_MASK;
                            STK->STK_CTRL=loc_temp;

                            return loc_error_state;

                                        }

        SYSTK_ErrorState_t STK_SetTimeMs(u32 TimeMs){

                                                        SYSTK_ErrorState_t loc_error_state=SYST_OK;
                                                        u32 loc_mp_freq=((STK->STK_CTRL)&(STK_SRC)) ? CLK_FREQUENCY_MHZ : CLK_FREQUENCY_MHZ/8;
                                                        u32 reload_value=(TimeMs *loc_mp_freq/1000)-1;
                                                        if((TimeMs<LOW_RELOAD) || (TimeMs>HIGH_RELOAD)){
                                                                                                            loc_error_state=SYST_NOK;
                                                                                                            }
                                                        else{   

                                                                STK->STK_LOAD=reload_value;
                                                                    STK->STK_VAL=0;
                                                                }
                                                        return loc_error_state;

                                                        }









          SYSTK_ErrorState_t  STK_SetConfig(u32 mode){
                                                    SYSTK_ErrorState_t loc_error_estate;
                                                        u32 loc_var=STK->STK_CTRL;
                                                    if(mode !=AHB8_ClkSrc && mode!=PROCESSOR_ClkSrc && mode !=AHB8_ClkSrc_TickInt  && mode != PROCESSOR_ClkSrc_TickInt){

                                                        loc_error_estate=SYST_NOK;


                                                    }

                                                    else{


                                                        loc_var &= STK_ClearMode;
                                                        loc_var |= mode;
                                                        STK->STK_CTRL=loc_var;
                                                    }
                                              return loc_error_estate;

                                            }


                                 SYSTK_ErrorState_t STK_SetCallBack(STK_CBF_t CBF) {
                                    SYSTK_ErrorState_t loc_error_state=SYST_OK;
                                    if(CBF != NULL){

                                        APP_CBF=CBF;
                                    }
                                    else{
                                        loc_error_state=SYST_NOK;
                                    }

                                    return loc_error_state;

                                 }           