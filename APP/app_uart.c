/*
 * app_uart.c
 *
 *  Created on: Feb 8, 2018
 *      Author: Morgan
 */

#include"app_uart.h"



gUARTError_t initUART(gUARTCFG_t *obj)
{
    gUARTError_t state=UART_PASS;
    if(obj->uart==UART0_MODULE)
    {
        clockGatingUART(UART0_MOD);
        initAppropriatePins(UART0_MOD);
    }else if(obj->uart==UART1_MODULE)
    {
        clockGatingUART(UART1_MOD);
        initAppropriatePins(UART1_MOD);
    }else if(obj->uart==UART2_MODULE)
    {
        clockGatingUART(UART2_MOD);
        initAppropriatePins(UART2_MOD);
    }else if(obj->uart==UART3_MODULE)
    {
        clockGatingUART(UART3_MOD);
        initAppropriatePins(UART3_MOD);
    }else if(obj->uart==UART4_MODULE)
    {
        clockGatingUART(UART4_MOD);
        initAppropriatePins(UART4_MOD);
    }else if(obj->uart==UART5_MODULE)
    {
        clockGatingUART(UART5_MOD);
        initAppropriatePins(UART5_MOD);
    }else if(obj->uart==UART6_MODULE)
    {
        clockGatingUART(UART6_MOD);
        initAppropriatePins(UART6_MOD);
    }else if(obj->uart==UART7_MODULE)
    {
        clockGatingUART(UART7_MOD);
        initAppropriatePins(UART7_MOD);
    }
    disableUART(obj->uart);
    setBAUDRate(obj->uart, obj->integarDiv, obj->fractionaldiv);
    en_dis_ParityBit(obj->uart, obj->parityEnable);
    en_dis_FIFOs(obj->uart, obj->FIFOsEnable);
    setEvenOddParityBit(obj->uart, obj->parity);
    selectStopBits(obj->uart, obj->stopBits);
    setWordLength(obj->uart, obj->wordLength);
    setClockSource(obj->uart, obj->clockSource);
    en_dis_Transmission(obj->uart, HIGH);
    en_dis_Recieveing(obj->uart, HIGH);
    enableUART(obj->uart);
    return state;
}

gUARTError_t sendChar(uint32 uart , uint8 data)
{
    gUARTError_t state=UART_PASS;
    while(HW_READ_BIT(uart+UARTFR, 5)!=0);
    HW_WRITE_REG_32BIT(uart+UARTDR,data);
    return state;
}
gUARTError_t getChar(uint32 uart , uint8 *data)
{
    gUARTError_t state=UART_PASS;
    while(HW_READ_BIT(uart+UARTFR, 4)!=0);
    *data=HW_READ_REG_32BIT(uart+UARTDR);
    return state;
}


