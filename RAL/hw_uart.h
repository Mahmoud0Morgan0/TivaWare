/*
 * hw_uart.h
 *
 *  Created on: Feb 7, 2018
 *      Author: Morgan
 */

#ifndef RAL_HW_UART_H_
#define RAL_HW_UART_H_

#define UART0_MODULE           0x4000C000
#define UART1_MODULE           0x4000D000
#define UART2_MODULE           0x4000E000
#define UART3_MODULE           0x4000F000
#define UART4_MODULE           0x40010000
#define UART5_MODULE           0x40011000
#define UART6_MODULE           0x40012000
#define UART7_MODULE           0x40013000




#define UARTDR                   0x000
#define UARTRSR_UARTECR          0x004
#define UARTFR                   0x018
#define UARTILPR                 0x020
#define UARTIBRD                 0x024
#define UARTFBRD                 0x028
#define UARTLCRH                 0x02C
#define UARTCTL                  0x030
#define UARTIFLS                 0x034
#define UARTIM                   0x038
#define UARTRIS                  0x03C
#define UARTMIS                  0x040
#define UARTICR                  0x044
#define UARTDMACTL               0x048
#define UART9BITADDR             0x0A4
#define UART9BITAMASK            0x0A8
#define UARTPP                   0xFC0
#define UARTCC                   0xFC8
#define UARTPeriphID4            0xFD0
#define UARTPeriphID5            0xFD4
#define UARTPeriphID6            0xFD8
#define UARTPeriphID7            0xFDC
#define UARTPeriphID0            0xFE0
#define UARTPeriphID1            0xFE4
#define UARTPeriphID2            0xFE8
#define UARTPeriphID3            0xFEC
#define UARTPCellID0             0xFF0
#define UARTPCellID1             0xFF4
#define UARTPCellID2             0xFF8
#define UARTPCellID3             0xFFC





#endif /* RAL_HW_UART_H_ */
