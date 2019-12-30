/*
 * app_uart.h
 *
 *  Created on: Feb 8, 2018
 *      Author: Morgan
 */

#ifndef APP_APP_UART_H_
#define APP_APP_UART_H_

#include "../HAL/uart.h"

typedef struct
{
    uint32 uart;
    uint16 integarDiv;
    uint8 fractionaldiv;
    uint8 parityEnable;
    gUARTParity_t parity;
    gUARTStopBits_t stopBits;
    uint8 FIFOsEnable;
    gUARTWordLength wordLength;
    gUARTClockSource clockSource;

}gUARTCFG_t;



gUARTError_t initUART(gUARTCFG_t *obj);
gUARTError_t sendChar(uint32 uart , uint8 data);
gUARTError_t getChar(uint32 uart , uint8 *data);





#endif /* APP_APP_UART_H_ */
