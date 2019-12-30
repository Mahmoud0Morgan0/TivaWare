/*
 * can.c
 *
 *  Created on: Feb 13, 2018
 *      Author: Morgan
 */

#include "can.h"


gCANError_t beginInitializingCAN(uint32 can)
{
    gCANError_t state = CAN_PASS;
    if(can==CAN0_MODULE||can==CAN1_MODULE)
    {
        HW_WRITE_BIT(can+CANCTL, 0, HIGH);
    }else
        state=CAN_MODULE_NOT_EXIST;
    return state;
}

gCANError_t endInitializingCAN(uint32 can)
{
    gCANError_t state = CAN_PASS;
    if(can==CAN0_MODULE||can==CAN1_MODULE)
    {
        HW_WRITE_BIT(can+CANCTL, 0, LOW);
    }else
        state=CAN_MODULE_NOT_EXIST;
    return state;
}
gCANError_t initAppropriateCANPins(sCAN_t can)
{
    gCANError_t state =CAN_PASS;
    if(can==CAN0_MOD)
    {
        //PB4,PB5
        clockGating(GPIOB);
        pinAlternateFunctionSel(BASE_B, 4, HIGH);
        pinAlternateFunctionSel(BASE_B, 5, HIGH);
        GPIOPinControl(BASE_B, 4, 8);
        GPIOPinControl(BASE_B, 5, 8);
        pinDigitalEnable(BASE_B, 4, HIGH);
        pinDigitalEnable(BASE_B, 5, HIGH);
    }else if(can==CAN1_MOD)
    {
        //PA0,PA1
        clockGating(GPIOA);
        pinAlternateFunctionSel(BASE_A, 0, HIGH);
        pinAlternateFunctionSel(BASE_A, 1, HIGH);
        GPIOPinControl(BASE_A, 0, 8);
        GPIOPinControl(BASE_A, 1, 8);
        pinDigitalEnable(BASE_A, 0, HIGH);
        pinDigitalEnable(BASE_A, 1, HIGH);
    }else
        state=CAN_MODULE_NOT_EXIST;
    return state;
}
gCANError_t transferMSGOBJinfoToInterface(uint32 can,uint8 value)
{
    gCANError_t state = CAN_PASS;
    if (can == CAN0_MODULE || can == CAN1_MODULE)
    {
        HW_WRITE_BIT(can + CANIF1CMSK, 6, HIGH);
        HW_WRITE_BIT(can + CANIF1CMSK, 5, HIGH);
        HW_WRITE_BIT(can + CANIF1CMSK, 4, HIGH);
        HW_WRITE_BIT(can + CANIF1CMSK, 2, HIGH);
        HW_WRITE_BIT(can + CANIF1CMSK, 1, HIGH);
    }
    else
        state = CAN_MODULE_NOT_EXIST;
    return state;

}
gCANError_t selectIdentifierTX(uint32 can , gCANidType idtype,uint16 idvalue)
{
    gCANError_t state = CAN_PASS;
    if (can == CAN0_MODULE || can == CAN1_MODULE)
    {
       if(idtype==STANDARD_ID)
       {
           HW_WRITE_BIT(can + CANIF1ARB2, 14, LOW);

       }else if(idtype==EXTENDED_ID)
       {

       }
    }
    else
        state = CAN_MODULE_NOT_EXIST;
    return state;
}
gCANError_t configTransmitMsgObj(uint32 can, gCANidType idtype,uint32 idvalue,uint8 dataSize,uint8 objno)
{
    gCANError_t state = CAN_PASS;
        if (can == CAN0_MODULE || can == CAN1_MODULE)
        {
            //configure command mask register
            HW_WRITE_BIT(can + CANIF1CMSK, 7, HIGH);// set WARND Bit
            HW_WRITE_BIT(can + CANIF1CMSK, 6, HIGH);//set MASK bit
            HW_WRITE_BIT(can + CANIF1CMSK, 5, HIGH);//set ARB bit
            HW_WRITE_BIT(can + CANIF1CMSK, 4, HIGH);//set CONTROL bit
            HW_WRITE_BIT(can + CANIF1CMSK, 2, HIGH);//set DATAA bit
            HW_WRITE_BIT(can + CANIF1CMSK, 1, HIGH);// set DATAB bit
            if (idtype == STANDARD_ID)
            {
                HW_WRITE_BIT(can + CANIF1ARB2, 14, LOW);
                HW_WRITE_MASKED_REG(can + CANIF1ARB2,idvalue,2,0x1FFC);
            }
            else if (idtype == EXTENDED_ID)
            {

            }else
                state=CAN_WRONG_ID;
            HW_WRITE_BIT(can + CANIF1ARB2, 13, HIGH);//select transfer direction to be transmit
            HW_WRITE_BIT(can + CANIF1MCTL, 7, HIGH);//select single message obj
            HW_WRITE_REG32_MASKED(can + CANIF1MCTL,dataSize,0xF);// select data size of message
            HW_WRITE_BIT(can + CANIF1ARB2, 15, HIGH);// set MSGVAL bit to inform message handler that message object is configured
            HW_WRITE_REG_32BIT(can + CANIF1CRQ,objno);

        }
        else
            state = CAN_MODULE_NOT_EXIST;
        return state ;
}
gCANError_t configRecieveMsgObj(uint32 can, gCANidType idtype,uint32 idvalue,uint8 dataSize,uint8 objno)
{
    gCANError_t state = CAN_PASS;
        if (can == CAN0_MODULE || can == CAN1_MODULE)
        {
            //configure command mask register
            HW_WRITE_BIT(can + CANIF2CMSK, 6, HIGH);//set MASK bit
            HW_WRITE_BIT(can + CANIF2CMSK, 5, HIGH);//set ARB bit
            HW_WRITE_BIT(can + CANIF2CMSK, 4, HIGH);//set CONTROL bit
            HW_WRITE_BIT(can + CANIF2CMSK, 2, HIGH);//set DATAA bit
            HW_WRITE_BIT(can + CANIF2CMSK, 1, HIGH);// set DATAB bit
            if (idtype == STANDARD_ID)
            {
                HW_WRITE_BIT(can + CANIF2ARB2, 14, LOW);
                HW_WRITE_MASKED_REG(can + CANIF2ARB2,idvalue,2,0x1FFC);
            }
            else if (idtype == EXTENDED_ID)
            {

            }else
                state=CAN_WRONG_ID;
            HW_WRITE_BIT(can + CANIF2ARB2, 13, LOW);//select transfer direction to be transmit
            HW_WRITE_BIT(can + CANIF2MCTL, 7, HIGH);//select single message obj
            HW_WRITE_BIT(can + CANIF2MCTL, 9, LOW);//clear RMTEN
            HW_WRITE_REG32_MASKED(can + CANIF2MCTL,dataSize,0xF);// select data size of message
            HW_WRITE_BIT(can + CANIF2ARB2, 15, HIGH);// set MSGVAL bit to inform message handler that message object is configured
            HW_WRITE_REG_32BIT(can + CANIF2CRQ,objno);

        }
        else
            state = CAN_MODULE_NOT_EXIST;
        return state ;
}
gCANError_t canTransmitData(uint32 can ,uint8 objno,uint8 data[8])
{
    gCANError_t state =CAN_PASS;
    if (can == CAN0_MODULE || can == CAN1_MODULE)
    {
        HW_WRITE_MASKED_REG(can+CANIF1DA1, data[0], 0, 0xFF);
        HW_WRITE_MASKED_REG(can+CANIF1DA1, data[1], 8, 0xFF00);
        HW_WRITE_MASKED_REG(can+CANIF1DA2, data[2], 0, 0xFF);
        HW_WRITE_MASKED_REG(can+CANIF1DA2, data[3], 8, 0xFF00);
        HW_WRITE_MASKED_REG(can+CANIF1DB1, data[4], 0, 0xFF);
        HW_WRITE_MASKED_REG(can+CANIF1DB1, data[5], 8, 0xFF00);
        HW_WRITE_MASKED_REG(can+CANIF1DB2, data[6], 0, 0xFF);
        HW_WRITE_MASKED_REG(can+CANIF1DB2, data[7], 8, 0xFF00);
        HW_WRITE_BIT(can + CANIF1CMSK, 2, HIGH);// set newDATA/TXRQST
        HW_WRITE_REG_32BIT(can + CANIF1CRQ,objno);
    }else
        state=CAN_MODULE_NOT_EXIST;
    return state;
}
gCANError_t canRecieveData(uint32 can ,uint8 objno,uint8 *data[8])
{
    gCANError_t state =CAN_PASS;
    if (can == CAN0_MODULE || can == CAN1_MODULE)
    {
        HW_WRITE_REG_32BIT(can + CANIF2CRQ,objno);
        if(HW_READ_BIT(can+CANIF2MCTL, 15))
        {
            data[0]=HW_READ_MASKED_BYTE_REG(can+CANIF2DA1, 0, 0xff);
            data[1]=HW_READ_MASKED_BYTE_REG(can+CANIF2DA1, 8, 0xff00);
            data[2]=HW_READ_MASKED_BYTE_REG(can+CANIF2DA2, 0, 0xff);
            data[3]=HW_READ_MASKED_BYTE_REG(can+CANIF2DA2, 8, 0xff00);
            data[4]=HW_READ_MASKED_BYTE_REG(can+CANIF2DB1, 0, 0xff);
            data[5]=HW_READ_MASKED_BYTE_REG(can+CANIF2DB1, 8, 0xff00);
            data[6]=HW_READ_MASKED_BYTE_REG(can+CANIF2DB2, 0, 0xff);
            data[7]=HW_READ_MASKED_BYTE_REG(can+CANIF2DB2, 8, 0xff00);
            HW_WRITE_BIT(can + CANIF2CMSK, 2, HIGH);//set NEWDATA BIT in CMSK to clear NEWDATA flag in MCTRL
        }
        HW_WRITE_REG_32BIT(can + CANIF2CRQ,objno);
    }else
        state=CAN_MODULE_NOT_EXIST;
    return state;
}










