/*
 * can.h
 *
 *  Created on: Feb 13, 2018
 *      Author: Morgan
 */

#ifndef HAL_CAN_H_
#define HAL_CAN_H_

#include "../RAL/types.h"
#include "../RAL/hw_types.h"
#include "../RAL/hw_can.h"
#include "gpio.h"
#include "sysctrl.h"
typedef enum
{
    CAN_PASS,CAN_MODULE_NOT_EXIST,CAN_WRONG_ID
}gCANError_t;

typedef enum
{
    EXTENDED_ID,STANDARD_ID
}gCANidType;
/**
 *  \brief   initialize TX and RX pins
 *
 *  \param   can  The memory address of the CAN instance being used.
 *  *        can can have 8 values :
 *             -# CAN0_MOD
 *             -# CAN1_MOD
 *  \retval  returns a value specified in the enum
 *             -# gCANError_t
 * */
gCANError_t initAppropriateCANPins(sCAN_t can);
//_______________________________________________________________________________________
/*
**
 *  \brief   set bit INIT to start initializing
 *
 *  \param   can  The memory address of the CAN instance being used.
 *  *        can can have 8 values :
 *             -# CAN0_MODULE
 *             -# CAN1_MODULE
 *  \retval  returns a value specified in the enum
 *             -# gCANError_t
 * */
gCANError_t beginInitializingCAN(uint32 can);
 //________________________________________________________________________________________
 /*
 **
  *  \brief   clear bit INIT to end initializing
  *
  *  \param   can  The memory address of the CAN instance being used.
  *  *        can can have 8 values :
  *             -# CAN0_MODULE
  *             -# CAN1_MODULE
  *  \retval  returns a value specified in the enum
  *             -# gCANError_t
  * */
 gCANError_t endInitializingCAN(uint32 can);
  //________________________________________________________________________________________
 gCANError_t transferMSGOBJinfoToInterface(uint32 can,uint8 value);
 gCANError_t configTransmitMsgObj(uint32 can, gCANidType idtype,uint32 idvalue,uint8 dataSize,uint8 objno);
 gCANError_t configRecieveMsgObj(uint32 can, gCANidType idtype,uint32 idvalue,uint8 dataSize,uint8 objno);
 gCANError_t selectIdentifierTX(uint32 can , gCANidType idtype,uint16 idvalue);
 gCANError_t canTransmitData(uint32 can ,uint8 objno,uint8 data[8]);

#endif /* HAL_CAN_H_ */
