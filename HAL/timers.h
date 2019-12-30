/*
 * timers.h
 *
 *  Created on: Feb 3, 2018
 *      Author: Morgan
 */

#ifndef HAL_TIMERS_H_
#define HAL_TIMERS_H_

#include "../RAL/types.h"
#include "../RAl/hw_types.h"
#include "../RAL/hw_timers.h"


typedef enum
{
    T_PASS,TIMER_NOT_EXIST,WRONG_TIMER_WIDTH,WRONG_TIMER_MODE
}gTimersError_t;


typedef enum
{
    ONESHOT,PERIODIC ,CAPTURE
}gTimersMode_t;

typedef enum
{
    HALF,FULL
}gTimerWidth_t;
typedef enum
{
    COUNT_UP,COUNT_DOWN
}gCountType_t;
//****************************************************************




/**
 *  \brief   Enable Timer
 *
 *  \param   base  The memory address of the Timer instance being used.
 *  *        base can have 5 values :
 *             -# Timer0
 *             -# Timer1
 *             -# Timer2
 *             -# Timer3
 *             -# Timer4
 *             -# Timer5
 *  \retval  returns a value specified in the enum
 *             -# gTimersError_t
 * */
gTimersError_t enableTimer(uint32 timer);
//____________________________________________________________________________

/**
 *  \brief   Disable Timer
 *
 *  \param   base  The memory address of the Timer instance being used.
 *  *        base can have 5 values :
 *             -# Timer0
 *             -# Timer1
 *             -# Timer2
 *             -# Timer3
 *             -# Timer4
 *             -# Timer5
 *  \retval  returns a value specified in the enum
 *             -# gTimersError_t
 * */
gTimersError_t disableTimer(uint32 timer);
//____________________________________________________________________________
/**
 *  \brief   select the width of timer 16 or 32 __ 32 or 64
 *
 *  \param   base  The memory address of the Timer instance being used.
 *  *        base can have 5 values :
 *             -# Timer0
 *             -# Timer1
 *             -# Timer2
 *             -# Timer3
 *             -# Timer4
 *             -# Timer5
 *  \param width the width of timer
 *      *  width can have 2 values :
 *          -# HALF if the timer is 16/32 use 16 bit
 *          -# Full if the timer is 16/32 use 32 bit
 *
 *  \retval  returns a value specified in the enum
 *             -# gTimersError_t
 * */
gTimersError_t selectTimerWidth(uint32 timer,gTimerWidth_t width);
//____________________________________________________________________________
/**
 *  \brief   select the mode of timer A oneshot or periodic or capture
 *
 *  \param   base  The memory address of the Timer instance being used.
 *  *        base can have 5 values :
 *             -# Timer0
 *             -# Timer1
 *             -# Timer2
 *             -# Timer3
 *             -# Timer4
 *             -# Timer5
 *  \param mode the mode of timer
 *      *  width can have 2 values :
 *          -# ONESHOT
 *          -# PERIODIC
 *          -# CAPTURE
 *  \retval  returns a value specified in the enum
 *             -# gTimersError_t
 * */
gTimersError_t selectTimerAMode(uint32 timer,gTimersMode_t mode);
/**
 *  \brief   select the mode of timer B oneshot or periodic or capture
 *
 *  \param   base  The memory address of the Timer instance being used.
 *  *        base can have 5 values :
 *             -# Timer0
 *             -# Timer1
 *             -# Timer2
 *             -# Timer3
 *             -# Timer4
 *             -# Timer5
 *  \param mode the mode of timer
 *      *  width can have 2 values :
 *          -# ONESHOT
 *          -# PERIODIC
 *          -# CAPTURE
 *  \retval  returns a value specified in the enum
 *             -# gTimersError_t
 * */
gTimersError_t selectTimerBMode(uint32 timer,gTimersMode_t mode);
//____________________________________________________________________________
/**
 *  \brief   select the countType A of timer Up or down
 *
 *  \param   base  The memory address of the Timer instance being used.
 *  *        base can have 5 values :
 *             -# Timer0
 *             -# Timer1
 *             -# Timer2
 *             -# Timer3
 *             -# Timer4
 *             -# Timer5
 *  \param countType the countType of timer
 *      *  width can have 2 values :
 *          -# COUNT_UP
 *          -# COUNT_DOWN
 *  \retval  returns a value specified in the enum
 *             -# gTimersError_t
 * */
gTimersError_t selectCountTypeA(uint32 timer,gCountType_t countType);
//____________________________________________________________________________
/**
 *  \brief   select the countType B of timer Up or down
 *
 *  \param   base  The memory address of the Timer instance being used.
 *  *        base can have 5 values :
 *             -# Timer0
 *             -# Timer1
 *             -# Timer2
 *             -# Timer3
 *             -# Timer4
 *             -# Timer5
 *  \param countType the countType of timer
 *      *  width can have 2 values :
 *          -# COUNT_UP
 *          -# COUNT_DOWN
 *  \retval  returns a value specified in the enum
 *             -# gTimersError_t
 * */
gTimersError_t selectCountTypeB(uint32 timer,gCountType_t countType);
//___________________________________________________________________________
/**
 *  \brief   LOAD Timer A interval load
 *
 *  \param   base  The memory address of the Timer instance being used.
 *  *        base can have 5 values :
 *             -# Timer0
 *             -# Timer1
 *             -# Timer2
 *             -# Timer3
 *             -# Timer4
 *             -# Timer5
 *  \param load the value to be in the register should be HEX 0xXXXXXXX
 *
 *  \retval  returns a value specified in the enum
 *             -# gTimersError_t
 * */
gTimersError_t setTimerAIntervalLoad(uint32 timer,uint32 load);
//___________________________________________________________________________
/**
 *  \brief    LOAD Timer B interval load
 *
 *  \param   base  The memory address of the Timer instance being used.
 *  *        base can have 5 values :
 *             -# Timer0
 *             -# Timer1
 *             -# Timer2
 *             -# Timer3
 *             -# Timer4
 *             -# Timer5
 *  \param load the value to be in the register should be HEX 0xXXXXXXX
 *
 *  \retval  returns a value specified in the enum
 *             -# gTimersError_t
 * */
gTimersError_t setTimerBIntervalLoad(uint32 timer,uint32 load);
//___________________________________________________________________________

#endif /* HAL_TIMERS_H_ */
