/*
 * gpio.h
 *
 *  Created on: Jan 26, 2018
 *      Author: Morgan
 */

#ifndef HAL_GPIO_H_
#define HAL_GPIO_H_

#include "../RAL/types.h"
#include "../RAL/hw_types.h"
#include "../RAL/hw_gpio.h"


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

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif



/** \brief Max gpio port pins*/
#define MAX_PORT_PINS         8
/** \brief Hardware mask to access all the GPIO data register bits.*/
#define GPIO_DATA_HW_MASK     0x3FC
/** \brief Value used to unlock port to enable the Commit register.*/
#define GPIO_UNLOCK_PORT      0x4C4F434B
/** \brief Value used to lock port to disable the Commit register ;Any value other than 0x4C4F434B.*/
#define GPIO_LOCK_PORT        0xFFFFFFFF
/** \brief Max analog pins in analog mode select register. */
#define MAX_ANALOG_PINS       3
/** \brief Max value that can be hold by analog mode select register. */
#define MAX_ANALOG_REG_VAL    16
#define PORT_CONTROL_STEP     4
#define GPIO_PORTCONTROL_MASK 0xF



/** \brief Enumerate the types of errors in the gpio module.*/
typedef enum {
    PASS , INCORRECT_PORT , INCORRECT_PIN_NUM , DIRECTION_ERROR ,
    INCORRECT_MASK , INCORRECT_VALUE , INCORRECT_INTERRUPT_SENSE
}gGPIOError_t;

/** \brief Enumerate the types of resistors in the gpio module.*/
typedef enum{
    PULL_UP_RES , PULL_DOWN_RES ,OPEN_DRAIN
}gResType_t;

/** \brief Enumerate the types of current driven in the gpio module.*/
typedef enum{
     CURRENT_2MA, CURRENT_4MA, CURRENT_8MA
}gCurrentVal_t;

/** \brief Enumerate the types of interrupt sensitivity in the gpio module.*/
typedef enum
{
    FALING_EDGE, RAISNG_EDGE, BOTH_EDGES, LOW_LEVEL, HIGH_LEVEL
} gInterrSenseControl_t;

/** \brief structure holding pad configurations.*/
typedef struct configPad{
    gResType_t resType;
    /**< Select resistor type.*/
    gCurrentVal_t currentVal;
    /**< Select driven current.*/
    uint8 lockFlag;
    /**< Specify if the pad is locked or unlocked
     *    -# TRUE  :   locked.
     *    -# FALSE :   unlocked*/
}gConfigPad_t;





gGPIOError_t setPinDir(uint32 base , uint8 pin , uint8 dir);
gGPIOError_t writePin(uint32 base , uint8 pin , uint8 val);
gGPIOError_t readPin(uint32 base , uint8 pin , uint8 *data);
gGPIOError_t setPortDir(uint32 base , uint8 dirVal);
gGPIOError_t writePort(uint32 base , uint8 val);
gGPIOError_t readPort(uint32 base , uint8 *data);
gGPIOError_t writeHWMaskedPins(uint32 base , uint8 val, uint8 mask);
gGPIOError_t readHWMaskedPins(uint32 base , uint16 mask , uint8 *data);
gGPIOError_t pinAlternateFunctionSel(uint32 base , uint8 pin , uint8 val);
gGPIOError_t portAlternateFunctionSel(uint32 base , uint8 val);
gGPIOError_t pinSetPadConfig(uint32 base , uint8 pin , gConfigPad_t *obj);
gGPIOError_t portSetPadConfig(uint32 base , gConfigPad_t *obj);
gGPIOError_t portUnLock(uint32 base , uint8 val);
gGPIOError_t portCommit(uint32 base , uint8 val);
gGPIOError_t pinCommit(uint32 base , uint8 pin , uint8 val);
gGPIOError_t portDigitalEnable(uint32 base , uint8 val);
gGPIOError_t pinDigitalEnable(uint32 base , uint8 pin , uint8 val);
gGPIOError_t pinAnalogModeSelect(uint32 base , uint8 pin , uint8 val);
gGPIOError_t portAnalogModeSelect(uint32 base , uint8 val);
gGPIOError_t GPIOPinControl(uint32 base , uint8 pin ,uint32 val);
gGPIOError_t GPIOPortControlClear(uint32 base );




#endif /* HAL_GPIO_H_ */
