/**
 *  \file    sysctrl.c
 *
 *  \brief   This file contains the device abstraction layer APIs for System Control.
 *
 *  \date    Aug 8, 2017
 *  \author  Muhammad Ali
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include "sysctrl.h"


/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

sSysCtrlError_t clockGating(sSysCtrlModules_t obj){
	sSysCtrlError_t state = PASSED;
	/** GPIO Moduels */
	if(obj == GPIOA){
#ifdef GPIO_HIGH_SPEED_BUS
		/* Enable AHB bus*/
		HW_WRITE_BIT(BASE_SYSTEM_CONTROL+GPIO_HIGH_PERFORMANCE_BUS_CONTROL_OFFSET,0,HIGH);
#endif
		/* Enable GPIOA Clock. */
		HW_WRITE_BIT(BASE_SYSTEM_CONTROL+GPIO_RUN_MODE_CLOCK_GATING_CONTROL_OFFSET,0,HIGH);
	}else if(obj == GPIOB){
#ifdef GPIO_HIGH_SPEED_BUS
		/* Enable AHB bus*/
		HW_WRITE_BIT(BASE_SYSTEM_CONTROL+GPIO_HIGH_PERFORMANCE_BUS_CONTROL_OFFSET,1,HIGH);
#endif
		/* Enable GPIOB Clock. */
		HW_WRITE_BIT(BASE_SYSTEM_CONTROL+GPIO_RUN_MODE_CLOCK_GATING_CONTROL_OFFSET,1,HIGH);
	}else if(obj == GPIOC){
#ifdef GPIO_HIGH_SPEED_BUS
		/* Enable AHB bus*/
		HW_WRITE_BIT(BASE_SYSTEM_CONTROL+GPIO_HIGH_PERFORMANCE_BUS_CONTROL_OFFSET,2,HIGH);
#endif
		/* Enable GPIOC Clock. */
		HW_WRITE_BIT(BASE_SYSTEM_CONTROL+GPIO_RUN_MODE_CLOCK_GATING_CONTROL_OFFSET,2,HIGH);
	}else if(obj == GPIOD){
#ifdef GPIO_HIGH_SPEED_BUS
		/* Enable AHB bus*/
		HW_WRITE_BIT(BASE_SYSTEM_CONTROL+GPIO_HIGH_PERFORMANCE_BUS_CONTROL_OFFSET,3,HIGH);
#endif
		/* Enable GPIOD Clock. */
		HW_WRITE_BIT(BASE_SYSTEM_CONTROL+GPIO_RUN_MODE_CLOCK_GATING_CONTROL_OFFSET,3,HIGH);
	}else if(obj == GPIOE){
#ifdef GPIO_HIGH_SPEED_BUS
		/* Enable AHB bus*/
		HW_WRITE_BIT(BASE_SYSTEM_CONTROL+GPIO_HIGH_PERFORMANCE_BUS_CONTROL_OFFSET,4,HIGH);
#endif
		/* Enable GPIOE Clock. */
		HW_WRITE_BIT(BASE_SYSTEM_CONTROL+GPIO_RUN_MODE_CLOCK_GATING_CONTROL_OFFSET,4,HIGH);
	}else if(obj == GPIOF){
#ifdef GPIO_HIGH_SPEED_BUS
		/* Enable AHB bus*/
		HW_WRITE_BIT(BASE_SYSTEM_CONTROL+GPIO_HIGH_PERFORMANCE_BUS_CONTROL_OFFSET,5,HIGH);
#endif
		/* Enable GPIOF Clock. */
		HW_WRITE_BIT(BASE_SYSTEM_CONTROL+GPIO_RUN_MODE_CLOCK_GATING_CONTROL_OFFSET,5,HIGH);

	}else{
		state = MODULE_NOT_EXIST;
	}
return state;
}
sSysCtrlError_t clockGatingTimers(sTimers_t obj)
{
    sSysCtrlError_t state = PASSED;
    if(obj==TIMER0)
    {
        HW_WRITE_BIT(BASE_SYSTEM_CONTROL+GENERAL_PURPOSE_16_32_BIT_TIMER_RUN_MODE_CLOCK_GATING_CONTROL_OFFSET,0,HIGH);
    }else if(obj==TIMER1)
    {
        HW_WRITE_BIT(BASE_SYSTEM_CONTROL+GENERAL_PURPOSE_16_32_BIT_TIMER_RUN_MODE_CLOCK_GATING_CONTROL_OFFSET,1,HIGH);
    }else if(obj==TIMER2)
    {
        HW_WRITE_BIT(BASE_SYSTEM_CONTROL+GENERAL_PURPOSE_16_32_BIT_TIMER_RUN_MODE_CLOCK_GATING_CONTROL_OFFSET,2,HIGH);
    }else if(obj==TIMER3)
    {
        HW_WRITE_BIT(BASE_SYSTEM_CONTROL+GENERAL_PURPOSE_16_32_BIT_TIMER_RUN_MODE_CLOCK_GATING_CONTROL_OFFSET,3,HIGH);
    }else if(obj==TIMER4)
    {
        HW_WRITE_BIT(BASE_SYSTEM_CONTROL+GENERAL_PURPOSE_16_32_BIT_TIMER_RUN_MODE_CLOCK_GATING_CONTROL_OFFSET,4,HIGH);
    }else if(obj==TIMER5)
    {
        HW_WRITE_BIT(BASE_SYSTEM_CONTROL+GENERAL_PURPOSE_16_32_BIT_TIMER_RUN_MODE_CLOCK_GATING_CONTROL_OFFSET,5,HIGH);
    }else if(obj==TIMER0_WIDE)
    {
        HW_WRITE_BIT(BASE_SYSTEM_CONTROL+GENERAL_PURPOSE_32_64_BIT_TIMER_RUN_MODE_CLOCK_GATING_CONTROL_OFFSET,0,HIGH);
    }else if(obj==TIMER1_WIDE)
    {
        HW_WRITE_BIT(BASE_SYSTEM_CONTROL+GENERAL_PURPOSE_32_64_BIT_TIMER_RUN_MODE_CLOCK_GATING_CONTROL_OFFSET,1,HIGH);
    }else if(obj==TIMER2_WIDE)
    {
        HW_WRITE_BIT(BASE_SYSTEM_CONTROL+GENERAL_PURPOSE_32_64_BIT_TIMER_RUN_MODE_CLOCK_GATING_CONTROL_OFFSET,2,HIGH);
    }else if(obj==TIMER3_WIDE)
    {
        HW_WRITE_BIT(BASE_SYSTEM_CONTROL+GENERAL_PURPOSE_32_64_BIT_TIMER_RUN_MODE_CLOCK_GATING_CONTROL_OFFSET,3,HIGH);
    }else if(obj==TIMER4_WIDE)
    {
        HW_WRITE_BIT(BASE_SYSTEM_CONTROL+GENERAL_PURPOSE_32_64_BIT_TIMER_RUN_MODE_CLOCK_GATING_CONTROL_OFFSET,4,HIGH);
    }else if(obj==TIMER5_WIDE)
    {
        HW_WRITE_BIT(BASE_SYSTEM_CONTROL+GENERAL_PURPOSE_32_64_BIT_TIMER_RUN_MODE_CLOCK_GATING_CONTROL_OFFSET,5,HIGH);
    }else
        state = MODULE_NOT_EXIST;
    return state;
}

sSysCtrlError_t clockGatingUART(sUART_t obj)
{
    sSysCtrlError_t state = PASSED;
    if(obj==UART0_MOD)
    {
        HW_WRITE_BIT(BASE_SYSTEM_CONTROL+UART_RUN_MODE_CLOCK_GATING_CONTROL_OFFSET,0,HIGH);
    }else if(obj==UART1_MOD)
    {
        HW_WRITE_BIT(BASE_SYSTEM_CONTROL+UART_RUN_MODE_CLOCK_GATING_CONTROL_OFFSET,1,HIGH);
    }else if(obj==UART1_MOD)
    {
        HW_WRITE_BIT(BASE_SYSTEM_CONTROL+UART_RUN_MODE_CLOCK_GATING_CONTROL_OFFSET,2,HIGH);
    }else if(obj==UART1_MOD)
    {
        HW_WRITE_BIT(BASE_SYSTEM_CONTROL+UART_RUN_MODE_CLOCK_GATING_CONTROL_OFFSET,3,HIGH);
    }else if(obj==UART1_MOD)
    {
        HW_WRITE_BIT(BASE_SYSTEM_CONTROL+UART_RUN_MODE_CLOCK_GATING_CONTROL_OFFSET,4,HIGH);
    }else if(obj==UART1_MOD)
    {
        HW_WRITE_BIT(BASE_SYSTEM_CONTROL+UART_RUN_MODE_CLOCK_GATING_CONTROL_OFFSET,5,HIGH);
    }else if(obj==UART1_MOD)
    {
        HW_WRITE_BIT(BASE_SYSTEM_CONTROL+UART_RUN_MODE_CLOCK_GATING_CONTROL_OFFSET,6,HIGH);
    }else if(obj==UART1_MOD)
    {
        HW_WRITE_BIT(BASE_SYSTEM_CONTROL+UART_RUN_MODE_CLOCK_GATING_CONTROL_OFFSET,7,HIGH);
    }else
        state = MODULE_NOT_EXIST;
    return state;
}
sSysCtrlError_t clockGatingCAN(sCAN_t obj)
{
    sSysCtrlError_t state = PASSED;
    if(obj==CAN0_MOD)
    {
        HW_WRITE_BIT(BASE_SYSTEM_CONTROL+CAN_RUN_MODE_CLOCK_GATING_CONTROL_OFFSET,0,HIGH);
    }else if(obj==CAN1_MOD)
    {
        HW_WRITE_BIT(BASE_SYSTEM_CONTROL+CAN_RUN_MODE_CLOCK_GATING_CONTROL_OFFSET,1,HIGH);
    }else
        state=MODULE_NOT_EXIST;
    return state;

}
sSysCtrlError_t NVICInterruptEnable(g_ISRVirIdx_t index,uint8 priority,uint8 pending){
    sSysCtrlError_t state = PASSED;
    if(index == GPIOA_IRQ){
    	/* enable interrupt*/
        HW_WRITE_BIT(INTERRUPT_0_31_SET_ENABLE,GPIOA_INT_NUMBER,HIGH);
        /* assign priority to PRI0 register*/
        HW_WRITE_REG32_MASKED(INTERRUPT_0_3_PRIORITY,priority<<5,0XF <<5);
        /* set interrupt pending*/
        HW_WRITE_BIT(INTERRUPT_0_31_SET_PENDING,GPIOA_INT_NUMBER,pending);
    }else if(index == GPIOB_IRQ){
    	/* enable interrupt*/
        HW_WRITE_BIT(INTERRUPT_0_31_SET_ENABLE,GPIOB_INT_NUMBER,HIGH);
        /* assign priority to PRI0 register*/
        HW_WRITE_REG32_MASKED(INTERRUPT_0_3_PRIORITY,priority<<13,0XF <<13);
        /* set interrupt pending*/
        HW_WRITE_BIT(INTERRUPT_0_31_SET_PENDING,GPIOB_INT_NUMBER,pending);
    }else if(index == GPIOC_IRQ){
    	/* enable interrupt*/
    	HW_WRITE_BIT(INTERRUPT_0_31_SET_ENABLE,GPIOC_INT_NUMBER,HIGH);
    	 /* assign priority to PRI0 register*/
    	HW_WRITE_REG32_MASKED(INTERRUPT_0_3_PRIORITY,priority<<21,0XF <<21);
    	/* set interrupt pending*/
    	HW_WRITE_BIT(INTERRUPT_0_31_SET_PENDING,GPIOC_INT_NUMBER,pending);
    }else if(index == GPIOD_IRQ){
    	/* enable interrupt*/
        HW_WRITE_BIT(INTERRUPT_0_31_SET_ENABLE,GPIOD_INT_NUMBER,HIGH);
        /* assign priority to PRI0 register*/
        HW_WRITE_REG32_MASKED(INTERRUPT_0_3_PRIORITY,priority<<29,0XF <<29);
        /* set interrupt pending*/
        HW_WRITE_BIT(INTERRUPT_0_31_SET_PENDING,GPIOD_INT_NUMBER,pending);
    }else if(index == GPIOE_IRQ){
    	/* enable interrupt*/
    	HW_WRITE_BIT(INTERRUPT_0_31_SET_ENABLE,GPIOE_INT_NUMBER,HIGH);
    	 /* assign priority to PRI1 register*/
    	HW_WRITE_REG32_MASKED(INTERRUPT_4_7_PRIORITY,priority<<5,0XF <<5);
    	/* set interrupt pending*/
    	HW_WRITE_BIT(INTERRUPT_0_31_SET_PENDING,GPIOE_INT_NUMBER,pending);
    }else if(index == GPIOF_IRQ){
    	/* enable interrupt*/
        HW_WRITE_BIT(INTERRUPT_0_31_SET_ENABLE,GPIOF_INT_NUMBER,HIGH);
        /* assign priority to PRI7 register*/
        HW_WRITE_REG32_MASKED(INTERRUPT_28_31_PRIORITY,priority<<21,0XF <<21);
        /* set interrupt pending*/
        HW_WRITE_BIT(INTERRUPT_0_31_SET_PENDING,GPIOF_INT_NUMBER,pending);
    }else{
    	state =  IRQ_NOT_EXIST;
    }
    return state;
}


sSysCtrlError_t NVICInterruptDisable(g_ISRVirIdx_t index){
    sSysCtrlError_t state = PASSED;
    if(index == GPIOA_IRQ || index == GPIOB_IRQ || index == GPIOC_IRQ ||
       index == GPIOD_IRQ || index == GPIOE_IRQ || index == GPIOF_IRQ){
    	HW_WRITE_BIT(INTERRUPT_0_31_CLEAR_ENABLE,index,HIGH);
    }else{
    	state =  IRQ_NOT_EXIST;
    }
    return state;
}

sSysCtrlError_t NVICInterruptClearPending(g_ISRVirIdx_t index){
    sSysCtrlError_t state = PASSED;
    if(index == GPIOA_IRQ || index == GPIOB_IRQ || index == GPIOC_IRQ ||
       index == GPIOD_IRQ || index == GPIOE_IRQ || index == GPIOF_IRQ){
    	HW_WRITE_BIT(INTERRUPT_0_31_CLEAR_PENDING,index,HIGH);
    }else{
    	state =  IRQ_NOT_EXIST;
    }
    return state;
}

sSysCtrlError_t NVICInterruptActive(g_ISRVirIdx_t *index){
    sSysCtrlError_t state = PASSED;
    if(HW_READ_BIT(INTERRUPT_0_31_ACTIVE_BIT,GPIOA_IRQ)==HIGH){
    	*index = GPIOA_IRQ;
    }else if(HW_READ_BIT(INTERRUPT_0_31_ACTIVE_BIT,GPIOB_IRQ)==HIGH){
    	*index = GPIOB_IRQ;
    }else if(HW_READ_BIT(INTERRUPT_0_31_ACTIVE_BIT,GPIOC_IRQ)==HIGH){
    	*index = GPIOC_IRQ;
    }else if(HW_READ_BIT(INTERRUPT_0_31_ACTIVE_BIT,GPIOD_IRQ)==HIGH){
    	*index = GPIOD_IRQ;
    }else if(HW_READ_BIT(INTERRUPT_0_31_ACTIVE_BIT,GPIOE_IRQ)==HIGH){
    	*index = GPIOE_IRQ;
    }else if(HW_READ_BIT(INTERRUPT_0_31_ACTIVE_BIT,GPIOF_IRQ)==HIGH){
    	*index = GPIOF_IRQ;
    }else{
    	state =  IRQ_NOT_EXIST;
    }
    return state;
}
sSysCtrlError_t setSysClock(sClockSRC_t clockSource, sClockValue_t clockValue)
{
    sSysCtrlError_t state = PASSED;
    HW_WRITE_BIT(BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                 31, 1);
    if (clockValue == c1MHZ)
    {
        HW_WRITE_BIT(
                BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET, 11,
                1);
        if (clockSource == MAIN_OSC)
        {

            //clock source
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    4, 1); //change here
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    5, 0);
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    6, 0);
            //deactive pll
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    13, 1);
            //usesdiv
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    22, 1);
            HW_WRITE_BIT(
                               BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_OFFSET,
                               22, 1);
            //Sys division /5  --> 4+1
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    23, 1);
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    24, 1);
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    25, 1);
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    26, 1);
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    27, 0);
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    28, 0);

        }
        else if (clockSource == INTERNAL_16M)
        {

            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    4, 1); //change here
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    5, 0);
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    6, 0);
            //deactive pll
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    13, 1);
            //usesdiv
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    22, 1);
            HW_WRITE_BIT(
                               BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_OFFSET,
                               22, 1);
            //Sys division /5  --> 4+1
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    23, 1);
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    24, 1);
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    25, 1);
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    26, 1);
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    27, 0);
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    28, 0);

        }

    }
    else if (clockValue == c2MHZ)
    {
        HW_WRITE_BIT(
                BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET, 11,
                1);
        if (clockSource == MAIN_OSC)
        {

            //clock source
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    4, 1); //change here
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    5, 0);
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    6, 0);
            //deactive pll
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    13, 1);
            HW_WRITE_BIT(
                               BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_OFFSET,
                               22, 1);
            //usesdiv
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    22, 1);
            HW_WRITE_BIT(
                               BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_OFFSET,
                               22, 1);
            //Sys division /5  --> 4+1
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    23, 1);
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    24, 1);
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    25, 1);
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    26, 0);
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    27, 0);
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    28, 0);

        }
        else if (clockSource == INTERNAL_16M)
        {

            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    4, 1); //change here
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    5, 0);
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    6, 0);
            //deactive pll
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    13, 1);
            //usesdiv
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    22, 1);
            HW_WRITE_BIT(
                               BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_OFFSET,
                               22, 1);
            //Sys division /5  --> 4+1
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    23, 1);
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    24, 1);
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    25, 1);
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    26, 0);
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    27, 0);
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    28, 0);

        }

    }
    else if (clockValue == c4MHZ)
    {
        HW_WRITE_BIT(
                BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET, 11,
                1);
        if (clockSource == MAIN_OSC)
        {

            //clock source
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    4, 1); //change here
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    5, 0);
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    6, 0);
            //deactive pll
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    13, 1);
            //usesdiv
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    22, 1);
            HW_WRITE_BIT(
                               BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_OFFSET,
                               22, 1);
            //Sys division /5  --> 4+1
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    23, 1);
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    24, 1);
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    25,0 );
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    26, 0);
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    27, 0);
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    28, 0);

        }
        else if (clockSource == INTERNAL_16M)
        {

            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    4, 1); //change here
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    5, 0);
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    6, 0);
            //deactive pll
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    13, 1);
            //usesdiv
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    22, 1);
            HW_WRITE_BIT(
                               BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_OFFSET,
                               22, 1);
            //Sys division /5  --> 4+1
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    23, 1);
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    24, 1);
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    25, 0);
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    26, 0);
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    27, 0);
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    28, 0);

        }

    }
    else if (clockValue == c8MHZ)
    {
        HW_WRITE_BIT(
                BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET, 11,
                1);
        if (clockSource == MAIN_OSC)
        {

            //clock source
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    4, 1); //change here
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    5, 0);
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    6, 0);
            //deactive pll
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    13, 1);
            //usesdiv
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    22, 1);
            HW_WRITE_BIT(
                               BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_OFFSET,
                               22, 1);
            //Sys division /5  --> 4+1
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    23, 1);
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    24, 0);
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    25, 0);
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    26, 0);
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    27, 0);
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    28, 0);

        }
        else if (clockSource == INTERNAL_16M)
        {

            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    4, 1); //change here
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    5, 0);
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    6, 0);
            //deactive pll
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    13, 1);
            //usesdiv
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    22, 1);
            HW_WRITE_BIT(
                               BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_OFFSET,
                               22, 1);
            //Sys division /5  --> 4+1
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    23, 1);
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    24, 0);
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    25, 0);
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    26, 0);
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    27, 0);
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    28, 0);

        }

    }
    else if (clockValue == c16MHZ)
    {
        HW_WRITE_BIT(
                BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET, 11,
                1);
       if (clockSource == MAIN_OSC)
        {

            //clock source
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    4, 1); //change here
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    5, 0);
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    6, 0);
            //deactive pll
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    13, 1);
            //usesdiv
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_OFFSET,
                    22, 1);
            //Sys division /5  --> 4+1
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    23, 0);
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    24, 0);
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    25, 0);
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    26, 0);
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    27, 0);
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    28, 0);

        }
        else if (clockSource == INTERNAL_16M)
        {

            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    4, 1); //change here
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    5, 0);
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    6, 0);
            //deactive pll
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    13, 1);
            //usesdiv
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    22, 0);
            //Sys division /5  --> 4+1
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    23, 1);
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    24, 0);
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    25, 0);
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    26, 1);
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    27, 0);
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    28, 0);

        }

    }
    else if (clockValue == c20MHZ)
    {
        HW_WRITE_BIT(
                BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET, 11,
                1);
        if (clockSource == MAIN_OSC)
        {
            //HW_WRITE_REG32_MASKED(BASE_SYSTEM_CONTROL+RUN_MODE_CLOCK_CONFIGURATION_OFFSET,15,0x000007c0);
            //XTal value
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_OFFSET,
                    6, 1);
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_OFFSET,
                    7, 0);
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_OFFSET,
                    8, 1);
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_OFFSET,
                    9, 0);
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_OFFSET,
                    10, 1);
            //clock source
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    4, 0);                    //change here
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    5, 0);
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    6, 0);
            //activate pll
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    13, 0);
            //Div400
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    30, 0);
            //Sys division /5  --> 4+1
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    22, 1);
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    23, 1);
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    24, 0);
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    25, 0);
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    26, 1);
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    27, 0);
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    28, 0);
            while (HW_READ_BIT(
                    BASE_SYSTEM_CONTROL + RAW_INTERRUPT_STATUS_OFFSET, 6))
            {
            };
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    11, 0);

        }
        else if (clockSource == INTERNAL_16M)
        {
            //XTal value
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_OFFSET,
                    6, 1);
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_OFFSET,
                    7, 0);
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_OFFSET,
                    8, 1);
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_OFFSET,
                    9, 0);
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_OFFSET,
                    10, 1);
            //clock source
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    4, 1);                    //change here
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    5, 0);
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    6, 0);
            //activate pll
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    13, 0);
            //Div400
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    30, 0);
            //Sys division /4
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    22, 1);
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    23, 1);
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    24, 0);
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    25, 0);
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    26, 1);
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    27, 0);
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    28, 0);
            while (HW_READ_BIT(
                    BASE_SYSTEM_CONTROL + RAW_INTERRUPT_STATUS_OFFSET, 6))
            {
            };
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    11, 0);

        }

    }
    else if (clockValue == c40MHZ)
    {
        //bypass
        HW_WRITE_BIT(
                BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET, 11,
                1);
        if (clockSource == MAIN_OSC)
        {
            //HW_WRITE_REG32_MASKED(BASE_SYSTEM_CONTROL+RUN_MODE_CLOCK_CONFIGURATION_OFFSET,15,0x000007c0);
            //XTal value
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_OFFSET,
                    6, 1);
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_OFFSET,
                    7, 0);
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_OFFSET,
                    8, 1);
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_OFFSET,
                    9, 0);
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_OFFSET,
                    10, 1);
            //clock source
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    4, 0);        //change here
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    5, 0);
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    6, 0);
            //activate pll
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    13, 0);
            //Div400
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    30, 1);
            //Sys division /5  --> 4+1
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    22, 1);
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    23, 0);
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    24, 0);
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    25, 1);
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    26, 0);
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    27, 0);
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    28, 0);
            while (HW_READ_BIT(
                    BASE_SYSTEM_CONTROL + RAW_INTERRUPT_STATUS_OFFSET, 6))
            {
            };
            //bypass
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    11, 0);

        }
        else if (clockSource == INTERNAL_16M)
        {
            //XTal value
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_OFFSET,
                    6, 1);
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_OFFSET,
                    7, 0);
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_OFFSET,
                    8, 1);
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_OFFSET,
                    9, 0);
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_OFFSET,
                    10, 1);
            //clock source
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    4, 1);        //change here
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    5, 0);
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    6, 0);
            //activate pll
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    13, 0);
            //Div400
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    30, 1);
            //Sys division /4
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    22, 1);

            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    23, 0);
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    24, 0);
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    25, 1);
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    26, 0);
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    27, 0);
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    28, 0);
            while (HW_READ_BIT(
                    BASE_SYSTEM_CONTROL + RAW_INTERRUPT_STATUS_OFFSET, 6))
            {
            };
            //bypass
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    11, 0);
        }
    }
    else if (clockValue == c80MHZ)
    {
        HW_WRITE_BIT(
                BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET, 11,
                1);
        if (clockSource == MAIN_OSC)
        {
            //HW_WRITE_REG32_MASKED(BASE_SYSTEM_CONTROL+RUN_MODE_CLOCK_CONFIGURATION_OFFSET,15,0x000007c0);
            //XTal value
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_OFFSET,
                    6, 1);
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_OFFSET,
                    7, 0);
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_OFFSET,
                    8, 1);
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_OFFSET,
                    9, 0);
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_OFFSET,
                    10, 1);
            //clock source
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    4, 0);            //change here
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    5, 0);
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    6, 0);
            //activate pll
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    13, 0);
            //Div400
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    30, 1);
            //Sys division /5  --> 4+1
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    22, 0);
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    23, 0);
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    24, 1);
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    25, 0);
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    26, 0);
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    27, 0);
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    28, 0);
            while (HW_READ_BIT(
                    BASE_SYSTEM_CONTROL + RAW_INTERRUPT_STATUS_OFFSET, 6))
            {
            };
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    11, 0);

        }
        else if (clockSource == INTERNAL_16M)
        {
            //XTal value
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_OFFSET,
                    6, 1);
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_OFFSET,
                    7, 0);
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_OFFSET,
                    8, 1);
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_OFFSET,
                    9, 0);
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_OFFSET,
                    10, 1);
            //clock source
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    4, 1);            //change here
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    5, 0);
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    6, 0);
            //activate pll
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    13, 0);
            //Div400
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    30, 1);
            //Sys division /4
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    22, 0);
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    23, 0);
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    24, 1);
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    25, 0);
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    26, 0);
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    27, 0);
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    28, 0);
            while (HW_READ_BIT(
                    BASE_SYSTEM_CONTROL + RAW_INTERRUPT_STATUS_OFFSET, 6))
            {
            };
            HW_WRITE_BIT(
                    BASE_SYSTEM_CONTROL + RUN_MODE_CLOCK_CONFIGURATION_2_OFFSET,
                    11, 0);

        }

    }

    return state;

}
