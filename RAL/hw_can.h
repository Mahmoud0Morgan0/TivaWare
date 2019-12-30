/*
 * hw_can.h
 *
 *  Created on: Feb 13, 2018
 *      Author: Morgan
 */

#ifndef RAL_HW_CAN_H_
#define RAL_HW_CAN_H_


#define     CAN0_MODULE         0x40040000
#define     CAN1_MODULE         0x40041000



#define CANCTL      0x000
#define CANSTS      0x004
#define CANERR      0x008
#define CANBIT      0x00C
#define CANINT      0x010
#define CANTST      0x014
#define CANBRPE     0x018
#define CANIF1CRQ   0x020
#define CANIF1CMSK  0x024
#define CANIF1MSK1  0x028
#define CANIF1MSK2  0x02C
#define CANIF1ARB1  0x030
#define CANIF1ARB2  0x034
#define CANIF1MCTL  0x038
#define CANIF1DA1   0x03C
#define CANIF1DA2   0x040
#define CANIF1DB1   0x044
#define CANIF1DB2   0x048
#define CANIF2CRQ   0x080
#define CANIF2CMSK  0x084
#define CANIF2MSK1  0x088
#define CANIF2MSK2  0x08C
#define CANIF2ARB1  0x090
#define CANIF2ARB2  0x094
#define CANIF2MCTL  0x098
#define CANIF2DA1   0x09C
#define CANIF2DA2   0x0A0
#define CANIF2DB1   0x0A4
#define CANIF2DB2   0x0A8
#define CANTXRQ1    0x100
#define CANTXRQ2    0x104
#define CANNWDA1    0x120
#define CANNWDA2    0x124
#define CANMSG1INT 0x140
#define CANMSG2INT 0x144
#define CANMSG1VAL 0x160
#define CANMSG2VAL 0x164


#endif /* RAL_HW_CAN_H_ */
