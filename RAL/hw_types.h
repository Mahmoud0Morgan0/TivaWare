/*
 * hw_types.h
 *
 *  Created on: Jan 26, 2018
 *      Author: Morgan
 */

#ifndef RAL_HW_TYPES_H_
#define RAL_HW_TYPES_H_
#include"types.h"


#ifndef INPUT
#define INPUT 0
#endif

#ifndef OUTPUT
#define OUTPUT 1
#endif

#ifndef LOW
#define LOW 0
#endif

#ifndef HIGH
#define HIGH 1
#endif

#define HW_READ_REG_32BIT(address) (*(volatile uint32*)(address))


#define HW_WRITE_REG_32BIT(address,value) ((*(volatile uint32*)(address)) = value )

#define HW_SET_BIT(addr,bit) \
    (HW_READ_REG_32BIT(addr) |=(1<<bit))

#define HW_RESET_BIT(addr,bit) \
    (HW_READ_REG_32BIT(addr) &=~(1<<bit))

#define HW_WRITE_REG32_MASKED(add , value , mask) HW_WRITE_REG_32BIT(add,\
                                                               (HW_READ_REG_32BIT(add) & ~mask)|(value & mask))


static inline void HW_WRITE_BIT(uint32 reg, uint8 pin , uint8 val);

static inline uint8 HW_READ_BIT(uint32 reg,uint8 pin);

static inline void HW_WRITE_MASKED_REG(uint32 reg, uint32 value , uint8 startingBit,uint32 mask);
static inline void HW_READ_MASKED_REG(uint32 reg , uint8 startingBit,uint32 mask);
static inline void HW_WRITE_BIT(uint32 reg, uint8 pin , uint8 val){
    if(val == HIGH){
    HW_READ_REG_32BIT(reg) |= (1<<pin);
    }else if(val == LOW){
        HW_READ_REG_32BIT(reg) &= ~(1<<pin);
    }
}

static inline uint8 HW_READ_BIT(uint32 reg,uint8 pin){

    return ((HW_READ_REG_32BIT(reg)&(1<<pin))>>pin);
}
static inline void HW_WRITE_MASKED_REG(uint32 reg, uint32 value , uint8 startingBit,uint32 mask)
{
    uint32 temp;
    value = value << startingBit;
    temp = HW_READ_REG_32BIT(reg) & ~mask;
    value=value|temp;
    HW_WRITE_REG_32BIT(reg,value);

}
static inline uint8 HW_READ_MASKED_BYTE_REG(uint32 reg , uint8 startingBit,uint32 mask)
{
    uint8 val =0;
    uint32 temp = HW_READ_REG_32BIT(reg) & mask;
    temp=temp>>startingBit;
    val=temp;
    return val;
}


#endif /* RAL_HW_TYPES_H_ */
