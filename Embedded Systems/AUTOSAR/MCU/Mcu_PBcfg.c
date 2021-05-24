
#include "Mcu.h"
#include "MemMap.h"
#include "Mcu_Cbk.h"

/*
 * Module Version 1.0.0
 */
#define MCU_PBCFG_SW_MAJOR_VERSION              (1U)
#define MCU_PBCFG_SW_MINOR_VERSION              (0U)
#define MCU_PBCFG_SW_PATCH_VERSION              (0U)

/*
 * AUTOSAR Version 4.0.3
 */
#define MCU_PBCFG_AR_RELEASE_MAJOR_VERSION     (4U)
#define MCU_PBCFG_AR_RELEASE_MINOR_VERSION     (0U)
#define MCU_PBCFG_AR_RELEASE_PATCH_VERSION     (3U)

/* AUTOSAR Version checking between Dio_PBcfg.c and Dio.h files */
#if ((MCU_PBCFG_AR_RELEASE_MAJOR_VERSION != MCU_AR_RELEASE_MAJOR_VERSION)\
 ||  (MCU_PBCFG_AR_RELEASE_MINOR_VERSION != MCU_AR_RELEASE_MINOR_VERSION)\
 ||  (MCU_PBCFG_AR_RELEASE_PATCH_VERSION != MCU_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of PBcfg.c does not match the expected version"
#endif

/* Software Version checking between Dio_PBcfg.c and Dio.h files */
#if ((MCU_PBCFG_SW_MAJOR_VERSION != MCU_SW_MAJOR_VERSION)\
 ||  (MCU_PBCFG_SW_MINOR_VERSION != MCU_SW_MINOR_VERSION)\
 ||  (MCU_PBCFG_SW_PATCH_VERSION != MCU_SW_PATCH_VERSION))
  #error "The SW version of PBcfg.c does not match the expected version"
#endif

/* PB structure used with Mcu_Init API */
const Mcu_ConfigType Mcu_Configuration =
		 {
			.Peripherals = {STD_ON,STD_OFF,STD_ON,STD_OFF,STD_OFF,STD_OFF,STD_OFF,STD_OFF,STD_OFF,STD_OFF,STD_OFF},
			.ClockConfigurations[CLOCK_CONFIG_0] = {CLK_SRC_HSE,SYSCLK_FREQ_8MHZ},
			.ClockConfigurations[CLOCK_CONFIG_1] = {CLK_SRC_HSI,SYSCLK_FREQ_8MHZ},
			.Mcu_Mode_Settings = MCU_MODE_SLEEP_NOW,
			.Reset_Settings = MCU_RESET_SW
		 };
