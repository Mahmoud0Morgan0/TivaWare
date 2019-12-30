/*
 * uart.c
 *
 *  Created on: Feb 7, 2018
 *      Author: Morgan
 */

#include "uart.h"



gUARTError_t enableUART(uint32 uart)
{
    gUARTError_t state = UART_PASS;
    if(uart==UART0_MODULE)
    {
        HW_WRITE_BIT(UART0_MODULE+UARTCTL,0,HIGH);
    }else if(uart==UART1_MODULE)
    {
        HW_WRITE_BIT(UART1_MODULE+UARTCTL,0,HIGH);
    }else if(uart==UART2_MODULE)
    {
        HW_WRITE_BIT(UART2_MODULE+UARTCTL,0,HIGH);
    }else if(uart==UART3_MODULE)
    {
        HW_WRITE_BIT(UART3_MODULE+UARTCTL,0,HIGH);
    }else if(uart==UART4_MODULE)
    {
        HW_WRITE_BIT(UART4_MODULE+UARTCTL,0,HIGH);
    }else if(uart==UART5_MODULE)
    {
        HW_WRITE_BIT(UART5_MODULE+UARTCTL,0,HIGH);
    }else if(uart==UART6_MODULE)
    {
        HW_WRITE_BIT(UART6_MODULE+UARTCTL,0,HIGH);
    }else if(uart==UART7_MODULE)
    {
        HW_WRITE_BIT(UART7_MODULE+UARTCTL,0,HIGH);
    }else
        state=UART_MODULE_NOT_EXIST;
    return state;
}

gUARTError_t disableUART(uint32 uart)
{
    gUARTError_t state = UART_PASS;
    if(uart==UART0_MODULE)
    {
        HW_WRITE_BIT(UART0_MODULE+UARTCTL,0,LOW);
    }else if(uart==UART1_MODULE)
    {
        HW_WRITE_BIT(UART1_MODULE+UARTCTL,0,LOW);
    }else if(uart==UART2_MODULE)
    {
        HW_WRITE_BIT(UART2_MODULE+UARTCTL,0,LOW);
    }else if(uart==UART3_MODULE)
    {
        HW_WRITE_BIT(UART3_MODULE+UARTCTL,0,LOW);
    }else if(uart==UART4_MODULE)
    {
        HW_WRITE_BIT(UART4_MODULE+UARTCTL,0,LOW);
    }else if(uart==UART5_MODULE)
    {
        HW_WRITE_BIT(UART5_MODULE+UARTCTL,0,LOW);
    }else if(uart==UART6_MODULE)
    {
        HW_WRITE_BIT(UART6_MODULE+UARTCTL,0,LOW);
    }else if(uart==UART7_MODULE)
    {
        HW_WRITE_BIT(UART7_MODULE+UARTCTL,0,LOW);
    }else
        state=UART_MODULE_NOT_EXIST;
    return state;
}
gUARTError_t setBAUDRate(uint32 uart,uint16 integarDiv,uint8 fractionaldiv)
{
    gUARTError_t state = UART_PASS;
    if (uart == UART0_MODULE || uart == UART0_MODULE || uart == UART0_MODULE
            || uart == UART0_MODULE || uart == UART0_MODULE
            || uart == UART0_MODULE || uart == UART0_MODULE
            || uart == UART0_MODULE)
    {
        HW_WRITE_REG_32BIT(uart+UARTIBRD,integarDiv);
        HW_WRITE_REG_32BIT(uart+UARTFBRD,fractionaldiv);
    }else
        state =UART_MODULE_NOT_EXIST;
    return state;

}
gUARTError_t en_dis_ParityBit(uint32 uart,uint8 val)
{
    gUARTError_t state = UART_PASS;
    if (uart == UART0_MODULE || uart == UART0_MODULE || uart == UART0_MODULE
               || uart == UART0_MODULE || uart == UART0_MODULE
               || uart == UART0_MODULE || uart == UART0_MODULE
               || uart == UART0_MODULE)
    {
        HW_WRITE_BIT(uart+UARTLCRH,1,val);
    }else
        state=UART_MODULE_NOT_EXIST;
    return state;
}
gUARTError_t en_dis_FIFOs(uint32 uart,uint8 val)
{
    gUARTError_t state = UART_PASS;
        if (uart == UART0_MODULE || uart == UART0_MODULE || uart == UART0_MODULE
                   || uart == UART0_MODULE || uart == UART0_MODULE
                   || uart == UART0_MODULE || uart == UART0_MODULE
                   || uart == UART0_MODULE)
        {
            HW_WRITE_BIT(uart+UARTLCRH,4,val);
        }else
            state=UART_MODULE_NOT_EXIST;
        return state;
}
gUARTError_t setEvenOddParityBit(uint32 uart,gUARTParity_t val)
{
    gUARTError_t state = UART_PASS;
    if (uart == UART0_MODULE || uart == UART0_MODULE || uart == UART0_MODULE
                   || uart == UART0_MODULE || uart == UART0_MODULE
                   || uart == UART0_MODULE || uart == UART0_MODULE
                   || uart == UART0_MODULE)
    {
        if(val==EVEN_PARITY_BIT)
        {
            HW_WRITE_BIT(uart+UARTLCRH,2,HIGH);
        }else if(val==ODD_PARITY_BIT)
        {
            HW_WRITE_BIT(uart+UARTLCRH,2,LOW);
        }else
            state=WRONG_PARITY_VALUE;
    }else
        state=UART_MODULE_NOT_EXIST;
    return state;
}
gUARTError_t selectStopBits(uint32 uart,gUARTStopBits_t val)
{
    gUARTError_t state = UART_PASS;
    if (uart == UART0_MODULE || uart == UART0_MODULE || uart == UART0_MODULE
                       || uart == UART0_MODULE || uart == UART0_MODULE
                       || uart == UART0_MODULE || uart == UART0_MODULE
                       || uart == UART0_MODULE)
    {
        if(val==ONE_STOP_BIT)
        {
            HW_WRITE_BIT(uart+UARTLCRH,3,LOW);
        }else if(val==TWO_STOP_BITS)
        {
            HW_WRITE_BIT(uart+UARTLCRH,3,HIGH);
        }else
            state=WRONG_STOP_BITS;
    }else
        state=UART_MODULE_NOT_EXIST;
    return state;
}
gUARTError_t setWordLength(uint32 uart,gUARTWordLength length)
{
    gUARTError_t state=UART_PASS;
    if (uart == UART0_MODULE || uart == UART0_MODULE || uart == UART0_MODULE
                           || uart == UART0_MODULE || uart == UART0_MODULE
                           || uart == UART0_MODULE || uart == UART0_MODULE
                           || uart == UART0_MODULE)
    {
        if(length==FIVE_BITS)
        {
            HW_WRITE_BIT(uart+UARTLCRH,5,LOW);
            HW_WRITE_BIT(uart+UARTLCRH,6,LOW);
        }else if(length==SIX_BITS)
        {
            HW_WRITE_BIT(uart+UARTLCRH,5,HIGH);
            HW_WRITE_BIT(uart+UARTLCRH,6,LOW);
        }else if(length==SEVEN_BIT)
        {
            HW_WRITE_BIT(uart+UARTLCRH,5,LOW);
            HW_WRITE_BIT(uart+UARTLCRH,6,HIGH);
        }else if(length==EIGHT_BITS)
        {
            HW_WRITE_BIT(uart+UARTLCRH,5,HIGH);
            HW_WRITE_BIT(uart+UARTLCRH,6,HIGH);
        }else
            state=WRONG_WORD_LENGTH;
    }else
        state=UART_MODULE_NOT_EXIST;
    return state;
}
gUARTError_t setClockSource(uint32 uart,gUARTClockSource clocksource)
{
    gUARTError_t state =UART_PASS;
    if (uart == UART0_MODULE || uart == UART0_MODULE || uart == UART0_MODULE
                               || uart == UART0_MODULE || uart == UART0_MODULE
                               || uart == UART0_MODULE || uart == UART0_MODULE
                               || uart == UART0_MODULE)
    {
        if(clocksource==SYSTEM_CLOCK)
        {
            HW_WRITE_BIT(uart+UARTCC,0,LOW);
            HW_WRITE_BIT(uart+UARTCC,1,LOW);
            HW_WRITE_BIT(uart+UARTCC,2,LOW);
            HW_WRITE_BIT(uart+UARTCC,3,LOW);
        }else if(clocksource==PIOSC)
        {
            HW_WRITE_BIT(uart+UARTCC,0,HIGH);
            HW_WRITE_BIT(uart+UARTCC,1,LOW);
            HW_WRITE_BIT(uart+UARTCC,2,HIGH);
            HW_WRITE_BIT(uart+UARTCC,3,LOW);
        }else
            state=WRONG_CLOCK_SOURCE;
    }else
        state=UART_MODULE_NOT_EXIST;
    return state;
}
gUARTError_t en_dis_Transmission(uint32 uart,uint8 val)
{
    gUARTError_t state = UART_PASS;
    if (uart == UART0_MODULE || uart == UART0_MODULE || uart == UART0_MODULE
            || uart == UART0_MODULE || uart == UART0_MODULE
            || uart == UART0_MODULE || uart == UART0_MODULE
            || uart == UART0_MODULE)
    {
        HW_WRITE_BIT(UART0_MODULE+UARTCTL,8,val);
    }
    else
        state = UART_MODULE_NOT_EXIST;
    return state;
}
gUARTError_t en_dis_Recieveing(uint32 uart,uint8 val)
{
    gUARTError_t state = UART_PASS;
    if (uart == UART0_MODULE || uart == UART0_MODULE || uart == UART0_MODULE
            || uart == UART0_MODULE || uart == UART0_MODULE
            || uart == UART0_MODULE || uart == UART0_MODULE
            || uart == UART0_MODULE)
    {
        HW_WRITE_BIT(UART0_MODULE+UARTCTL,9,val);
    }
    else
        state = UART_MODULE_NOT_EXIST;
    return state;
}
gUARTError_t initAppropriatePins(sUART_t uart)
{
    gUARTError_t state = UART_PASS;
    if(uart==UART0_MOD)
    {
        //PA0,PA1
        clockGating(GPIOA);
        pinAlternateFunctionSel(BASE_A , 0 , HIGH);
        pinAlternateFunctionSel(BASE_A , 1 , HIGH);
        GPIOPinControl(BASE_A, 0, 1);
        GPIOPinControl(BASE_A, 1, 1);
        pinDigitalEnable(BASE_A, 0, HIGH);
        pinDigitalEnable(BASE_A, 1, HIGH);
    }else if(uart==UART1_MOD)
    {
        //PB0,PB1
        clockGating(GPIOB);
        pinAlternateFunctionSel(BASE_B, 0, HIGH);
        pinAlternateFunctionSel(BASE_B, 1, HIGH);
        GPIOPinControl(BASE_B, 0, 1);
        GPIOPinControl(BASE_B, 1, 1);
        pinDigitalEnable(BASE_B, 0, HIGH);
        pinDigitalEnable(BASE_B, 1, HIGH);
    }else if(uart==UART2_MOD)
    {
        //PD6,PD7
        clockGating(GPIOD);
        pinAlternateFunctionSel(BASE_D, 6, HIGH);
        pinAlternateFunctionSel(BASE_D, 7, HIGH);
        GPIOPinControl(BASE_D, 6, 1);
        GPIOPinControl(BASE_D, 7, 1);
        pinDigitalEnable(BASE_D, 6, HIGH);
        pinDigitalEnable(BASE_D, 7, HIGH);
    }else if(uart==UART3_MOD)
    {
        //PC6,PC7
        clockGating(GPIOC);
        pinAlternateFunctionSel(BASE_C, 6, HIGH);
        pinAlternateFunctionSel(BASE_C, 7, HIGH);
        GPIOPinControl(BASE_C, 6, 1);
        GPIOPinControl(BASE_C, 7, 1);
        pinDigitalEnable(BASE_C, 6, HIGH);
        pinDigitalEnable(BASE_C, 7, HIGH);
    }else if(uart==UART4_MOD)
    {
        //PC4,PC5
        clockGating(GPIOC);
        pinAlternateFunctionSel(BASE_C, 4, HIGH);
        pinAlternateFunctionSel(BASE_C, 5, HIGH);
        GPIOPinControl(BASE_C, 4, 1);
        GPIOPinControl(BASE_C, 5, 1);
        pinDigitalEnable(BASE_C, 4, HIGH);
        pinDigitalEnable(BASE_C, 5, HIGH);
    }else if(uart==UART5_MOD)
    {
        //PE4,PE5
        clockGating(GPIOE);
        pinAlternateFunctionSel(BASE_E, 4, HIGH);
        pinAlternateFunctionSel(BASE_E, 5, HIGH);
        GPIOPinControl(BASE_E, 4, 1);
        GPIOPinControl(BASE_E, 5, 1);
        pinDigitalEnable(BASE_E, 4, HIGH);
        pinDigitalEnable(BASE_E, 5, HIGH);
    }else if(uart==UART6_MOD)
    {
        //PD4,PD5
        clockGating(GPIOD);
        pinAlternateFunctionSel(BASE_D, 4, HIGH);
        pinAlternateFunctionSel(BASE_D, 5, HIGH);
        GPIOPinControl(BASE_D, 4, 1);
        GPIOPinControl(BASE_D, 5, 1);
        pinDigitalEnable(BASE_D, 4, HIGH);
        pinDigitalEnable(BASE_D, 5, HIGH);
    }else if(uart==UART7_MOD)
    {
        //PE0,PE1
        clockGating(GPIOE);
        pinAlternateFunctionSel(BASE_E, 0, HIGH);
        pinAlternateFunctionSel(BASE_E, 1, HIGH);
        GPIOPinControl(BASE_E, 0, 1);
        GPIOPinControl(BASE_E, 1, 1);
        pinDigitalEnable(BASE_E, 0, HIGH);
        pinDigitalEnable(BASE_E, 1, HIGH);
    }else
        state=UART_MODULE_NOT_EXIST;
    return state;
}









