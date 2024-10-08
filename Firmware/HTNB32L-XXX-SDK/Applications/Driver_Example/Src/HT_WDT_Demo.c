/**
 *
 * Copyright (c) 2023 HT Micron Semicondutores S.A.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * http://www.apache.org/licenses/LICENSE-2.0
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

/*
   This project demos the usage of WDT, in this example, we'll start to kick WDT for 5 times and then stop,
   the WDT is configured as WDT_InterruptResetMode and we won't clear WDT interrupt flag upon timeout,
   so a system reset shall follow a WDT interrupt, the time tick is achieved through TIMER's interrupt.
 */

#include "HT_WDT_Demo.h"

/*!******************************************************************
 * \fn static void HT_WDT_Init(void)
 * \brief Initialize WDT
 *
 * \param[in]  none
 * \param[out] none
 *
 * \retval none.
 *******************************************************************/
static void HT_WDT_Init(void);

/** \brief WDT interrupt count */
static volatile int wdtInterruptCount = 0;

/** \brief timer interupt count */
static volatile int timerInterruptCount = 0;

/** \brief Flag to control message print */
static volatile int printDone = 1;

void NMI_Handler(void) {
    wdtInterruptCount++;
}

/**
  \fn          void HT_Timer0_ISR(void)
  \brief       timer0 interrupt service routine
  \return
*/
static void HT_Timer0_ISR(void) {
    timerInterruptCount++;
    printDone = 0;
    if(timerInterruptCount <= WDT_KICK_TIMES)
        WDT_Kick();
}

static void HT_WDT_Init(void) {
    wdt_config_t wdtConfig;
    timer_config_t timerConfig;

    // Config WDT clock, source from 32.768KHz and divide by 5
    CLOCK_SetClockSrc(GPR_WDGFuncClk, GPR_WDGClkSel_32K);
    CLOCK_SetClockDiv(GPR_WDGFuncClk, 5);

    // WDT config, timeout is 5s
    wdtConfig.mode = WDT_InterruptResetMode;
    wdtConfig.timeoutValue = 0x8000;
    WDT_Init(&wdtConfig);

    // Config TIMER clock, source from 32.768KHz and divide by 1
    CLOCK_SetClockSrc(GPR_TIMER0FuncClk, GPR_TIMER0ClkSel_32K);
    CLOCK_SetClockDiv(GPR_TIMER0FuncClk, 1);

    TIMER_DriverInit();

    // Config timer period as 1s, match0 value is 32768 = 0x8000
    TIMER_GetDefaultConfig(&timerConfig);
    timerConfig.reloadOption = TIMER_ReloadOnMatch0;
    timerConfig.match0 = 0x8000;

    TIMER_Init(0, &timerConfig);

    // Note interrupt flag won't assert in TIMER_InterruptPulse mode
    TIMER_InterruptConfig(0, TIMER_Match0Select, TIMER_InterruptPulse);
    TIMER_InterruptConfig(0, TIMER_Match1Select, TIMER_InterruptDisabled);
    TIMER_InterruptConfig(0, TIMER_Match2Select, TIMER_InterruptDisabled);

    // Enable IRQ
    XIC_SetVector(PXIC_Timer0_IRQn, HT_Timer0_ISR);
    XIC_EnableIRQ(PXIC_Timer0_IRQn);
}

void HT_WDT_App(void) {
    ht_printf("HTNB32L-XXX WDT Example Start!\n");

    HT_WDT_Init();
    WDT_Start();
    TIMER_Start(0);

    while(1)
    {
        if (printDone == 0)
        {
            ht_printf("tick:%2d, wdt interrupt count: %d\n", timerInterruptCount, wdtInterruptCount);

            if (timerInterruptCount < WDT_KICK_TIMES){
                ht_printf("wdt kick: %d\n", timerInterruptCount);
            } else if (timerInterruptCount == WDT_KICK_TIMES){
                ht_printf("Last kick, wdt interrupt will occur in 5 ticks\n");
            } else if (timerInterruptCount == WDT_KICK_TIMES * 2){
                ht_printf("System will reset in 5 ticks\n");
            }

            printDone = 1;
        }
    }
}

/************************ HT Micron Semicondutores S.A *****END OF FILE****/
