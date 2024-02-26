	#include "RCC.h"

	#include "E:\ARM_DRIVERS\lib\STD_TYPES.h"
	#include "E:\ARM_DRIVERS\lib\BIT_MATH.h"
	
	
	
				typedef struct 
				{

				volatile u32 CR;
				volatile u32 PLLCFGR;
				volatile u32 CFGR;
				volatile u32 CIR;
				volatile u32 AHB1RSTR;

				volatile u32 AHB2RSTR;
				volatile u32 Reserved1;
				volatile u32 Reserved2;
				volatile u32 APB1RSTR;
				volatile u32 APB2RSTR;
				volatile u32 Reserved3;
				volatile u32 Reserved4;
				volatile u32 AHB1ENR;
				volatile u32 AHB2ENR;
				volatile u32 Reserved5;
				volatile u32 Reserved6;
				volatile u32 APB1ENR;
				volatile u32 APB2ENR;
				volatile u32 Reserved7;
				volatile u32 Reserved8;
				volatile u32 AHB1LPENR;
				volatile u32 AHB2LPENR;
				volatile u32 Reserved9;
				volatile u32 Reserved10;
				volatile u32 APB1LPENR;
				volatile u32 APB2LPENR;
				volatile u32 Reserved11;
				volatile u32 Reserved12;

				volatile u32 BDCR;

				volatile u32 CSR;
				volatile u32 Reserved13;
				volatile u32 Reserved14;
				volatile u32 SSCGR;
				volatile u32 PLLI2SCFGR;
					volatile u32 Reserved15;
					volatile u32 DCKCFGR;

				}RCC_Registers;

				#define RCC_BASEADDRESS 0X40023800
				#define RCC ((RCC_Registers* )(RCC_BASEADDRESS))


				 RCC_ErrorStatus_t RCC_SelectClk(u8 clocksystem){

					 u32 reg_var;
					 u32 time_out=0;
					 RCC_ErrorStatus_t loc_error = Ok;
					 
					 switch(clocksystem){

						 case RCC_HSI:
						 if (((RCC->CR & HSI_on) == HSI_on) && ((RCC->CR & HSI_ready) == HSI_ready)) {
							 reg_var = RCC->CFGR;
							 reg_var &= ~MASK_SW;
							 reg_var |= (RCC_HSI << 0);
							 RCC->CFGR = reg_var;
							 
							 while (((RCC->CFGR & MASK_GET_SWS) != MASK_SWS_HSI) && (time_out < 600)) {
								 time_out++;
							 }
							 
							 if (time_out >= 600) {
								 loc_error = Nok;
							 }
							 } else {
							 loc_error = Nok;
						 }
						 break;

						 case RCC_HSE:
						 if (((RCC->CR & HSE_on) == HSE_on) && ((RCC->CR & HSE_ready) == HSE_ready)) {
							 reg_var = RCC->CFGR;
							 reg_var &= ~MASK_SW;
							 reg_var |= (RCC_HSE << 0);
							 RCC->CFGR = reg_var;
							 
							 while (((RCC->CFGR & MASK_GET_SWS) != MASK_SWS_HSE) && (time_out < 600)) {
								 time_out++;
							 }
							 
							 if (time_out >= 600) {
								 loc_error = Nok;
							 }
							 } else {
							 loc_error = Nok;
						 }
						 break;

						 case RCC_PLL:
						 if (((RCC->CR & PLL_on) == PLL_on) && ((RCC->CR & PLL_ready) == PLL_ready)) {
							 reg_var = RCC->CFGR;
							 reg_var &= ~MASK_SW;
							 reg_var |= (RCC_PLL << 0);
							 RCC->CFGR = reg_var;
							 
							 while (((RCC->CFGR & MASK_GET_SWS) != MASK_SWS_PLL) && (time_out < 600)) {
								 time_out++;
							 }
							 
							 if (time_out >= 600) {
								 loc_error = Nok;
							 }
							 } else {
							 loc_error = Nok;
						 }
						 break;

						 default:
						 loc_error = Nok;
						 break;
					 }
					 return loc_error;
				 }


				//////////////////////////////////////////*function to enable and disable the clocks*///////////////////////////////////////////////////////////////////////////////////////
				RCC_ErrorStatus_t RCC_ControlClk(u8 ClockSystem, u8 clock_status) {
					RCC_ErrorStatus_t loc_error = Ok;
					u32 time_out = 0;

					switch (ClockSystem) {
						///////////////////////////////////////*HSI*/////////////////////////////////////////
						case RCC_HSI:
						if (clock_status == off) {
							RCC->CR &= ~HSI_on;
							} else {
							RCC->CR |= HSI_on;
							while (((RCC->CR & HSI_ready) == 0) && (time_out < 600)) {
								time_out++;
							}
							if (time_out >= 600) {
								loc_error = Nok;
							}
						}
						break;

						///////////////////////////////////////*HSE*/////////////////////////////////////////
						case RCC_HSE:
						if (clock_status == off) {
							RCC->CR &= ~HSE_on;
							} else {
							RCC->CR |= HSE_on;
							while (((RCC->CR & HSE_ready) == 0) && (time_out < 600)) {
								time_out++;
							}
							if (time_out >= 600) {
								loc_error = Nok;
							}
						}
						break;

						///////////////////////////////////////*PLL*/////////////////////////////////////////
						case RCC_PLL:
						if (clock_status == off) {
							RCC->CR &= ~PLL_on;
							} else {
							RCC->CR |= PLL_on;
							while (((RCC->CR & PLL_ready) == 0) && (time_out < 600)) {
								time_out++;
							}
							if (time_out >= 600) {
								loc_error = Nok;
							}
						}
						break;

						default:
						loc_error = Nok;
						break;
					}
					return loc_error;
				}





				/*======================================================*/
				RCC_ErrorStatus_t  RCC_CheckReady(u8 ClockSystem, u8* ReadyStatus){
				RCC_ErrorStatus_t loc_error=Ok;
				switch(ClockSystem){
				case RCC_HSI:
				if((RCC->CR & HSI_ready)==HSI_ready){
					*ReadyStatus=RCC_Ready;
					
				}
				else{
					*ReadyStatus=RCC_NotReady;
				}
				break;


				case RCC_HSE:
				if((RCC->CR & HSE_ready)==HSE_ready){
					*ReadyStatus=RCC_Ready;
					
				}
				else{
					*ReadyStatus=RCC_NotReady;
				}
				break;



				case RCC_PLL:
				if((RCC->CR & PLL_ready)==PLL_ready){
					*ReadyStatus=RCC_Ready;
					
				}
				else{
					*ReadyStatus=RCC_NotReady;
				}
				break;

				default:
				loc_error=Nok;
				break;
				}
				return loc_error;

				}




				RCC_ErrorStatus_t RCC_PLL_SRC(u32 clc_src){


					RCC_ErrorStatus_t loc_error=Ok;
					u32 loc_var;
					switch(clc_src){

						case  PLL_SRC_HSE:
					   
						loc_var |= PLL_HSE;
						 loc_var=RCC->PLLCFGR;
						 break;
						 case     PLL_SRC_HSI:
						 loc_var &= PLL_HSI;
						 break;
						 default:
						 loc_error=Nok;

					}
					return loc_error;
				}

				RCC_ErrorStatus_t RCC_CONFIG_PLL(u32 PLL_M,u32 PLL_N,u32 PLL_P,u32 PLL_Q){


					RCC_ErrorStatus_t loc_error=Ok;
					u32 loc_var;

					if(PLL_M<2 || PLL_M>63){
						loc_error=Nok;
					}
					else if(PLL_N<192 || PLL_N>432){

						loc_error=Nok;
					}
					else if(PLL_Q<2 || PLL_Q>15){
						loc_error=Nok;
					}
					  else if((PLL_P != 2) && (PLL_P != 4) && (PLL_P != 6) && (PLL_P != 8)){
						loc_error=Nok;
					}
					else { 
						/*CONFIGURE PLL_M*/
						loc_var=RCC->PLLCFGR;
					loc_var &= ~set_PLL_M ;
					loc_var |= (PLL_M<<SHIFT_PLL_M);
					RCC->PLLCFGR=loc_var;

					 /*CONFIGURE PLL_N*/
						loc_var=RCC->PLLCFGR;
					loc_var &= ~set_PLL_N ;
					loc_var |= (PLL_N<<SHIFT_PLL_N);
					RCC->PLLCFGR=loc_var;

				 /*CONFIGURE PLL_P*/
						loc_var=RCC->PLLCFGR;
					loc_var &= ~set_PLL_P ;
					loc_var |= (PLL_P<<SHIFT_PLL_P);
					RCC->PLLCFGR=loc_var;

				 /*CONFIGURE PLL_Q*/
						loc_var=RCC->PLLCFGR;
					loc_var &= ~set_PLL_Q ;
					loc_var |= (PLL_Q<<SHIFT_PLL_Q);
					RCC->PLLCFGR=loc_var;


				 /*CONFIGURE PLL_SRC*/
				 /**
						loc_var=RCC->PLLCFGR;
					loc_var &= ~set_PLL_SRC ;
					loc_var |= (PLL_SRC<<SHIFT_PLL_SRC);
					RCC->PLLCFGR=loc_var;
				*/

					}
					return loc_error;
				}





				RCC_ErrorStatus_t  RCC_ControlPrescalerAHB(u32 AHBPrescaler){

				RCC_ErrorStatus_t loc_error=Ok;
				u32 loc_var;
				switch(AHBPrescaler){
				case AHB_0:
				loc_var=RCC->CFGR;
				loc_var &=(~PRE_AHB_ON);
				loc_var |= (AHB_0<<SHIFT_AHB);
				RCC->CFGR=loc_var;
				break;

				case AHB_2:
				loc_var=RCC->CFGR;
				loc_var &=(~PRE_AHB_ON);
				loc_var |= (AHB_2<<SHIFT_AHB);
				RCC->CFGR=loc_var;
				break;

				case AHB_4:
				loc_var=RCC->CFGR;
				loc_var &=(~PRE_AHB_ON);
				loc_var |= (AHB_4<<SHIFT_AHB);
				RCC->CFGR=loc_var;
				break;

				case AHB_8:
				loc_var=RCC->CFGR;
				loc_var &=(~PRE_AHB_ON);
				loc_var |= (AHB_8<<SHIFT_AHB);
				RCC->CFGR=loc_var;
				break;


				case AHB_16:
				loc_var=RCC->CFGR;
				loc_var &=(~PRE_AHB_ON);
				loc_var |= (AHB_16<<SHIFT_AHB);
				RCC->CFGR=loc_var;
				break;



				case AHB_64:
				loc_var=RCC->CFGR;
				loc_var &=(~PRE_AHB_ON);
				loc_var |= (AHB_64<<SHIFT_AHB);
				RCC->CFGR=loc_var;
				break;

				case AHB_128:
				loc_var=RCC->CFGR;
				loc_var &=(~PRE_AHB_ON);
				loc_var |= (AHB_128<<SHIFT_AHB);
				RCC->CFGR=loc_var;
				break;


				case AHB_256:
				loc_var=RCC->CFGR;
				loc_var &=(~PRE_AHB_ON);
				loc_var |= (AHB_256<<SHIFT_AHB);
				RCC->CFGR=loc_var;
				break;
				default:
				loc_error=Nok;
				break;
				}
				return loc_error;
				}


				RCC_ErrorStatus_t  RCC_ControlPrescalerAPB1 (u32 APB1Prescaler){

				RCC_ErrorStatus_t loc_error=Ok;
				u32 loc_var;
				switch(APB1Prescaler){

					case APB1_0:
					loc_var=RCC->CFGR;
					loc_var &=(~PRE_APB1_ON);
					loc_var |= (APB1_0<<SHIFT_APB1);
					loc_var=RCC->CFGR;
					break;


					 case APB1_2:
					loc_var=RCC->CFGR;
					loc_var &=(~PRE_APB1_ON);
					loc_var |= (APB1_2<<SHIFT_APB1);
					loc_var=RCC->CFGR;
					break;




					 case APB1_4:
					loc_var=RCC->CFGR;
					loc_var &=(~PRE_APB1_ON);
					loc_var |= (APB1_4<<SHIFT_APB1);
					loc_var=RCC->CFGR;
					break;

				 case APB1_8:
					loc_var=RCC->CFGR;
					loc_var &=(~PRE_APB1_ON);
					loc_var |= (APB1_8<<SHIFT_APB1);
					loc_var=RCC->CFGR;
					break;

					 case APB1_16:
					loc_var=RCC->CFGR;
					loc_var &=(~PRE_APB1_ON);
					loc_var |= (APB1_16<<SHIFT_APB1);
					loc_var=RCC->CFGR;
					break;


					default:
					loc_error=Nok;
				break;
				}
				return loc_error;

				}
				RCC_ErrorStatus_t  RCC_ControlPrescalerAPB2  (u32 APB2Prescaler){


				RCC_ErrorStatus_t loc_error=Ok;
				u32 loc_var;

				switch(APB2Prescaler){

				  case APB2_0:
					loc_var=RCC->CFGR;
					loc_var &=(~PRE_APB2_ON);
					loc_var |= (APB2_0<<SHIFT_APB2);
					loc_var=RCC->CFGR;
					break;

				case APB2_2:
					loc_var=RCC->CFGR;
					loc_var &=(~PRE_APB2_ON);
					loc_var |= (APB2_2<<SHIFT_APB2);
					loc_var=RCC->CFGR;
					break;


					case APB2_4:
					loc_var=RCC->CFGR;
					loc_var &=(~PRE_APB2_ON);
					loc_var |= (APB2_4<<SHIFT_APB2);
					loc_var=RCC->CFGR;
					break;



					case APB2_8:
					loc_var=RCC->CFGR;
					loc_var &=(~PRE_APB2_ON);
					loc_var |= (APB2_8<<SHIFT_APB2);
					loc_var=RCC->CFGR;
					break;



					case APB2_16:
					loc_var=RCC->CFGR;
					loc_var &=(~PRE_APB2_ON);
					loc_var |= (APB2_16<<SHIFT_APB2);
					loc_var=RCC->CFGR;
					break;
					
					default:
					loc_error=Nok;
				break;



				}

				return loc_error;
				}

				RCC_ErrorStatus_t  RCC_enuEnablePreipheral(u32 PeripheralBus, u32 Peripheral){

					RCC_ErrorStatus_t loc_error=Ok;
					
					switch(PeripheralBus){
						case AHB1_BUS:

						RCC->AHB1ENR |= (1<<Peripheral);

						break;

						case AHB2_BUS:
						RCC->AHB2ENR |= (1<<Peripheral);
						break;
						case  APB1_BUS:
						RCC->APB1ENR |= (1<<Peripheral);
						
						break;
						case APB2_BUS:
						RCC->APB2ENR |= (1<<Peripheral);
						default:
						loc_error=Nok;

					}
						return loc_error;
				}
				RCC_ErrorStatus_t  RCC_enuDisablePreipheral(u32 PeripheralBus, u32 Peripheral){

				  RCC_ErrorStatus_t loc_error=Ok;

					 switch(PeripheralBus){
						case AHB1_BUS:

						RCC->AHB1ENR &= (~(1<<Peripheral));

						break;

						case AHB2_BUS:
						RCC->AHB2ENR &= (~(1<<Peripheral));
						break;
						case  APB1_BUS:
						RCC->APB1ENR &= (~(1<<Peripheral));
						
						break;
						case APB2_BUS:
						RCC->APB2ENR &= (~(1<<Peripheral));
						default:
						loc_error=Nok;

					}
						return loc_error;



				}




				 