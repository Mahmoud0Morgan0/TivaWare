/*
 * uart.h
 *
 *  Created on: Feb 7, 2018
 *      Author: Morgan
 */

#ifndef HAL_UART_H_
#define HAL_UART_H_


#include "../RAL/hw_uart.h"
#include "../RAL/types.h"
#include "../RAL/hw_types.h"
#include "gpio.h"
#include "sysctrl.h"
typedef enum
{
    UART_PASS,UART_MODULE_NOT_EXIST,WRONG_PARITY_VALUE,WRONG_STOP_BITS,WRONG_WORD_LENGTH,WRONG_CLOCK_SOURCE
}gUARTError_t;

typedef enum
{
    EVEN_PARITY_BIT,ODD_PARITY_BIT
}gUARTParity_t;
typedef enum
{
    ONE_STOP_BIT,TWO_STOP_BITS
}gUARTStopBits_t;

typedef enum
{
    FIVE_BITS,SIX_BITS,SEVEN_BIT,EIGHT_BITS
}gUARTWordLength;
typedef enum
{
    SYSTEM_CLOCK,PIOSC
}gUARTClockSource;



/**
 *  \brief   Enable UART
 *
 *  \param   uart  The memory address of the UART instance being used.
 *  *        uart can have 8 values :
 *             -# UART0
 *             -# UART1
 *             -# UART2
 *             -# UART3
 *             -# UART4
 *             -# UART5
 *             -# UART6
 *             -# UART7
 *  \retval  returns a value specified in the enum
 *             -# gUARTError_t
 * */
gUARTError_t enableUART(uint32 uart);
//____________________________________________________________________________
/**
 *  \brief   Disable UART
 *
 *  \param   uart  The memory address of the UART instance being used.
 *  *        uart can have 8 values :
 *             -# UART0
 *             -# UART1
 *             -# UART2
 *             -# UART3
 *             -# UART4
 *             -# UART5
 *             -# UART6
 *             -# UART7
 *  \retval  returns a value specified in the enum
 *             -# gUARTError_t
 * */
gUARTError_t disableUART(uint32 uart);
//____________________________________________________________________________
/**
 *  \brief   Set baud rate for  UART
 *
 *  \param   uart  The memory address of the UART instance being used.
 *  *        uart can have 8 values :
 *             -# UART0
 *             -# UART1
 *             -# UART2
 *             -# UART3
 *             -# UART4
 *             -# UART5
 *             -# UART6
 *             -# UART7
 *  \param   integarDiv the integar part of baudrate divisor
 *  \param   fractionaldiv the fractional part of baudrate divisor
 *  \retval  returns a value specified in the enum
 *             -# gUARTError_t
 * */
gUARTError_t setBAUDRate(uint32 uart,uint16 integarDiv,uint8 fractionaldiv);
//____________________________________________________________________________
/**
 *  \brief   enable or disable parity bit
 *
 *  \param   uart  The memory address of the UART instance being used.
 *  *        uart can have 8 values :
 *             -# UART0
 *             -# UART1
 *             -# UART2
 *             -# UART3
 *             -# UART4
 *             -# UART5
 *             -# UART6
 *             -# UART7
 *  \param   val value is HIGH for enable LOW for disable
 *  \retval  returns a value specified in the enum
 *             -# gUARTError_t
 * */
gUARTError_t en_dis_ParityBit(uint32 uart,uint8 val);
//____________________________________________________________________________
/**
 *  \brief   Set parity bit to be oven or odd
 *
 *  \param   uart  The memory address of the UART instance being used.
 *  *        uart can have 8 values :
 *             -# UART0
 *             -# UART1
 *             -# UART2
 *             -# UART3
 *             -# UART4
 *             -# UART5
 *             -# UART6
 *             -# UART7
 *  \param   val value is EVEN_PARITY_BIT or ODD_PARITY_BIT
 *  \retval  returns a value specified in the enum
 *             -# gUARTError_t
 * */
gUARTError_t setEvenOddParityBit(uint32 uart,gUARTParity_t val);
//____________________________________________________________________________
/**
 *  \brief   select the stop bits of frame
 *
 *  \param   uart  The memory address of the UART instance being used.
 *  *        uart can have 8 values :
 *             -# UART0
 *             -# UART1
 *             -# UART2
 *             -# UART3
 *             -# UART4
 *             -# UART5
 *             -# UART6
 *             -# UART7
 *  \param   val value is ONE_STOP_BIT or TWO_STOP_BITS
 *  \retval  returns a value specified in the enum
 *             -# gUARTError_t
 * */
gUARTError_t selectStopBits(uint32 uart,gUARTStopBits_t val);
//____________________________________________________________________________
/**
 *  \brief   enable or disable FIFO mode
 *
 *  \param   uart  The memory address of the UART instance being used.
 *  *        uart can have 8 values :
 *             -# UART0
 *             -# UART1
 *             -# UART2
 *             -# UART3
 *             -# UART4
 *             -# UART5
 *             -# UART6
 *             -# UART7
 *  \param   val value is HIGH for enable LOW for disable
 *  \retval  returns a value specified in the enum
 *             -# gUARTError_t
 * */
gUARTError_t en_dis_FIFOs(uint32 uart,uint8 val);
//____________________________________________________________________________
/**
 *  \brief   set the length of word being sent
 *
 *  \param   uart  The memory address of the UART instance being used.
 *  *        uart can have 8 values :
 *             -# UART0
 *             -# UART1
 *             -# UART2
 *             -# UART3
 *             -# UART4
 *             -# UART5
 *             -# UART6
 *             -# UART7
 *  \param   length value could be
 *             -# FIVE_BITS,
 *             -#SIX_BITS,SEVEN_BIT,
 *             -#EIGHT_BITS
 *  \retval  returns a value specified in the enum
 *             -# gUARTError_t
 * */
gUARTError_t setWordLength(uint32 uart,gUARTWordLength length);
//____________________________________________________________________________
/**
 *  \brief   select clock source for UART
 *
 *  \param   uart  The memory address of the UART instance being used.
 *  *        uart can have 8 values :
 *             -# UART0
 *             -# UART1
 *             -# UART2
 *             -# UART3
 *             -# UART4
 *             -# UART5
 *             -# UART6
 *             -# UART7
 *  \param   clocksource value could be
 *             -# SYSTEM_CLOCK,
 *             -# PIOSC
 *  \retval  returns a value specified in the enum
 *             -# gUARTError_t
 * */
gUARTError_t setClockSource(uint32 uart,gUARTClockSource clocksource);
//____________________________________________________________________________
/**
 *  \brief   enable TX
 *
 *  \param   uart  The memory address of the UART instance being used.
 *  *        uart can have 8 values :
 *             -# UART0
 *             -# UART1
 *             -# UART2
 *             -# UART3
 *             -# UART4
 *             -# UART5
 *             -# UART6
 *             -# UART7
 *  \param   val value is HIGH for enable LOW for disable
 *  \retval  returns a value specified in the enum
 *             -# gUARTError_t
 * */
gUARTError_t en_dis_Transmission(uint32 uart,uint8 val);
//____________________________________________________________________________
/**
 *  \brief   Enable RX
 *
 *  \param   uart  The memory address of the UART instance being used.
 *  *        uart can have 8 values :
 *             -# UART0
 *             -# UART1
 *             -# UART2
 *             -# UART3
 *             -# UART4
 *             -# UART5
 *             -# UART6
 *             -# UART7
 *  \param   val value is HIGH for enable LOW for disable
 *  \retval  returns a value specified in the enum
 *             -# gUARTError_t
 * */
gUARTError_t en_dis_Recieveing(uint32 uart,uint8 val);
//____________________________________________________________________________
/**
 *  \brief   initialize TX and RX pins
 *
 *  \param   uart  The memory address of the UART instance being used.
 *  *        uart can have 8 values :
 *             -# UART0
 *             -# UART1
 *             -# UART2
 *             -# UART3
 *             -# UART4
 *             -# UART5
 *             -# UART6
 *             -# UART7
 *  \retval  returns a value specified in the enum
 *             -# gUARTError_t
 * */
gUARTError_t initAppropriatePins(sUART_t uart);
//____________________________________________________________________________
#endif /* HAL_UART_H_ */
