/*
 * timers.c
 *
 *  Created on: Feb 4, 2018
 *      Author: Morgan
 */
#include "timers.h"






gTimersError_t enableTimer(uint32 timer)
{
    gTimersError_t state = T_PASS;
    if(timer==Timer0_16_32)
    {
        HW_WRITE_BIT(Timer0_16_32+GPTMCTL,0,HIGH);
    }else if(timer==Timer1_16_32)
    {
        HW_WRITE_BIT(Timer1_16_32+GPTMCTL,0,HIGH);
    }else if(timer==Timer2_16_32)
    {
        HW_WRITE_BIT(Timer2_16_32+GPTMCTL,0,HIGH);
    }else if(timer==Timer3_16_32)
    {
        HW_WRITE_BIT(Timer3_16_32+GPTMCTL,0,HIGH);
    }else if(timer==Timer4_16_32)
    {
        HW_WRITE_BIT(Timer4_16_32+GPTMCTL,0,HIGH);
    }else if(timer==Timer5_16_32)
    {
        HW_WRITE_BIT(Timer5_16_32+GPTMCTL,0,HIGH);
    }else if(timer==Timer0_Wide_32_64)
    {
        HW_WRITE_BIT(Timer0_Wide_32_64+GPTMCTL,0,HIGH);
    }else if(timer==Timer1_Wide_32_64)
    {
        HW_WRITE_BIT(Timer1_Wide_32_64+GPTMCTL,0,HIGH);
    }else if(timer==Timer2_Wide_32_64)
    {
        HW_WRITE_BIT(Timer2_Wide_32_64+GPTMCTL,0,HIGH);
    }else if(timer==Timer3_Wide_32_64)
    {
        HW_WRITE_BIT(Timer3_Wide_32_64+GPTMCTL,0,HIGH);
    }else if(timer==Timer4_Wide_32_64)
    {
        HW_WRITE_BIT(Timer4_Wide_32_64+GPTMCTL,0,HIGH);
    }else if(timer==Timer5_Wide_32_64)
    {
        HW_WRITE_BIT(Timer5_Wide_32_64+GPTMCTL,0,HIGH);
    }else
        state= TIMER_NOT_EXIST;
    return state;
}


gTimersError_t disableTimer(uint32 timer)
{
    gTimersError_t state = T_PASS;
    if(timer==Timer0_16_32)
    {
        HW_WRITE_BIT(Timer0_16_32+GPTMCTL,0,LOW);
    }else if(timer==Timer1_16_32)
    {
        HW_WRITE_BIT(Timer1_16_32+GPTMCTL,0,LOW);
    }else if(timer==Timer2_16_32)
    {
        HW_WRITE_BIT(Timer2_16_32+GPTMCTL,0,LOW);
    }else if(timer==Timer3_16_32)
    {
        HW_WRITE_BIT(Timer3_16_32+GPTMCTL,0,LOW);
    }else if(timer==Timer4_16_32)
    {
        HW_WRITE_BIT(Timer4_16_32+GPTMCTL,0,LOW);
    }else if(timer==Timer5_16_32)
    {
        HW_WRITE_BIT(Timer5_16_32+GPTMCTL,0,LOW);
    }else if(timer==Timer0_Wide_32_64)
    {
        HW_WRITE_BIT(Timer0_Wide_32_64+GPTMCTL,0,LOW);
    }else if(timer==Timer1_Wide_32_64)
    {
        HW_WRITE_BIT(Timer1_Wide_32_64+GPTMCTL,0,LOW);
    }else if(timer==Timer2_Wide_32_64)
    {
        HW_WRITE_BIT(Timer2_Wide_32_64+GPTMCTL,0,LOW);
    }else if(timer==Timer3_Wide_32_64)
    {
        HW_WRITE_BIT(Timer3_Wide_32_64+GPTMCTL,0,LOW);
    }else if(timer==Timer4_Wide_32_64)
    {
        HW_WRITE_BIT(Timer4_Wide_32_64+GPTMCTL,0,LOW);
    }else if(timer==Timer5_Wide_32_64)
    {
        HW_WRITE_BIT(Timer5_Wide_32_64+GPTMCTL,0,LOW);
    }else
        state= TIMER_NOT_EXIST;
    return state;
}

gTimersError_t selectTimerWidth(uint32 timer,gTimerWidth_t width)
{
    gTimersError_t state = T_PASS;
    if(timer==Timer0_16_32 || timer==Timer1_16_32|| timer==Timer2_16_32||
       timer==Timer3_16_32 || timer==Timer4_16_32|| timer==Timer5_16_32||
       timer==Timer0_Wide_32_64|| timer==Timer1_Wide_32_64||timer==Timer2_Wide_32_64||
       timer==Timer3_Wide_32_64|| timer==Timer4_Wide_32_64||timer==Timer5_Wide_32_64)
    {
        if (width == HALF)
        {
            HW_WRITE_BIT(timer + GPTMCFG, 0, LOW);
            HW_WRITE_BIT(timer + GPTMCFG, 1, LOW);
            HW_WRITE_BIT(timer + GPTMCFG, 2, HIGH);
        }
        else if (width == FULL)
        {
            HW_WRITE_BIT(timer + GPTMCFG, 0, LOW);
            HW_WRITE_BIT(timer + GPTMCFG, 1, LOW);
            HW_WRITE_BIT(timer + GPTMCFG, 2, LOW);
        }
        else
            state = WRONG_TIMER_WIDTH;
    }else
        state= TIMER_NOT_EXIST;
    return state ;
}
gTimersError_t selectTimerAMode(uint32 timer,gTimersMode_t mode)
{
    gTimersError_t state = T_PASS;
    if (timer==Timer0_16_32 || timer==Timer1_16_32|| timer==Timer2_16_32||
    timer==Timer3_16_32 || timer==Timer4_16_32|| timer==Timer5_16_32||
    timer==Timer0_Wide_32_64|| timer==Timer1_Wide_32_64||timer==Timer2_Wide_32_64||
    timer==Timer3_Wide_32_64|| timer==Timer4_Wide_32_64||timer==Timer5_Wide_32_64)
    {
        if (mode == ONESHOT)
        {
            HW_WRITE_BIT(timer + GPTMTAMR, 0, HIGH);
            HW_WRITE_BIT(timer + GPTMTAMR, 1, LOW);
        }
        else if (mode == PERIODIC)
        {
            HW_WRITE_BIT(timer + GPTMTAMR, 0, LOW);
            HW_WRITE_BIT(timer + GPTMTAMR, 1, HIGH);
        }
        else if (mode == CAPTURE)
        {
            HW_WRITE_BIT(timer + GPTMTAMR, 0, HIGH);
            HW_WRITE_BIT(timer + GPTMTAMR, 1, HIGH);
        }
        else
            state = WRONG_TIMER_MODE;
    }
    else
        state = TIMER_NOT_EXIST;
    return state;
}

gTimersError_t selectTimerBMode(uint32 timer,gTimersMode_t mode)
{
    gTimersError_t state = T_PASS;
    if (timer==Timer0_16_32 || timer==Timer1_16_32|| timer==Timer2_16_32||
    timer==Timer3_16_32 || timer==Timer4_16_32|| timer==Timer5_16_32||
    timer==Timer0_Wide_32_64|| timer==Timer1_Wide_32_64||timer==Timer2_Wide_32_64||
    timer==Timer3_Wide_32_64|| timer==Timer4_Wide_32_64||timer==Timer5_Wide_32_64)
    {
        if (mode == ONESHOT)
        {
            HW_WRITE_BIT(timer + GPTMTBMR, 0, HIGH);
            HW_WRITE_BIT(timer + GPTMTBMR, 1, LOW);
        }
        else if (mode == PERIODIC)
        {
            HW_WRITE_BIT(timer + GPTMTBMR, 0, LOW);
            HW_WRITE_BIT(timer + GPTMTBMR, 1, HIGH);
        }
        else if (mode == CAPTURE)
        {
            HW_WRITE_BIT(timer + GPTMTBMR, 0, HIGH);
            HW_WRITE_BIT(timer + GPTMTBMR, 1, HIGH);
        }
        else
            state = WRONG_TIMER_MODE;
    }
    else
        state = TIMER_NOT_EXIST;
    return state;
}
gTimersError_t selectCountTypeB(uint32 timer,gCountType_t countType)
{
    gTimersError_t state = T_PASS ;
    if (timer==Timer0_16_32 || timer==Timer1_16_32|| timer==Timer2_16_32||
        timer==Timer3_16_32 || timer==Timer4_16_32|| timer==Timer5_16_32||
        timer==Timer0_Wide_32_64|| timer==Timer1_Wide_32_64||timer==Timer2_Wide_32_64||
        timer==Timer3_Wide_32_64|| timer==Timer4_Wide_32_64||timer==Timer5_Wide_32_64)
        {
            if (countType == COUNT_UP)
            {
                HW_WRITE_BIT(timer + GPTMTBMR, 4, HIGH);
            }
            else if (countType == COUNT_DOWN)
            {
                HW_WRITE_BIT(timer + GPTMTBMR, 4, LOW);
            }
            else
                state = WRONG_TIMER_MODE;
        }
        else
            state = TIMER_NOT_EXIST;
        return state;
}


gTimersError_t selectCountTypeA(uint32 timer,gCountType_t countType)
{
    gTimersError_t state = T_PASS ;
    if (timer==Timer0_16_32 || timer==Timer1_16_32|| timer==Timer2_16_32||
        timer==Timer3_16_32 || timer==Timer4_16_32|| timer==Timer5_16_32||
        timer==Timer0_Wide_32_64|| timer==Timer1_Wide_32_64||timer==Timer2_Wide_32_64||
        timer==Timer3_Wide_32_64|| timer==Timer4_Wide_32_64||timer==Timer5_Wide_32_64)
        {
            if (countType == COUNT_UP)
            {
                HW_WRITE_BIT(timer + GPTMTAMR, 4, HIGH);
            }
            else if (countType == COUNT_DOWN)
            {
                HW_WRITE_BIT(timer + GPTMTAMR, 4, LOW);
            }
            else
                state = WRONG_TIMER_MODE;
        }
        else
            state = TIMER_NOT_EXIST;
        return state;
}

gTimersError_t setTimerAIntervalLoad(uint32 timer,uint32 load)
{
    gTimersError_t state = T_PASS ;
    if (timer==Timer0_16_32 || timer==Timer1_16_32|| timer==Timer2_16_32||
        timer==Timer3_16_32 || timer==Timer4_16_32|| timer==Timer5_16_32||
        timer==Timer0_Wide_32_64|| timer==Timer1_Wide_32_64||timer==Timer2_Wide_32_64||
        timer==Timer3_Wide_32_64|| timer==Timer4_Wide_32_64||timer==Timer5_Wide_32_64)
        {
           HW_WRITE_REG_32BIT(timer+GPTMTAILR,load);
        }
        else
            state = TIMER_NOT_EXIST;
        return state;
}
gTimersError_t setTimerBIntervalLoad(uint32 timer,uint32 load)
{
    gTimersError_t state = T_PASS ;
    if (timer==Timer0_16_32 || timer==Timer1_16_32|| timer==Timer2_16_32||
        timer==Timer3_16_32 || timer==Timer4_16_32|| timer==Timer5_16_32||
        timer==Timer0_Wide_32_64|| timer==Timer1_Wide_32_64||timer==Timer2_Wide_32_64||
        timer==Timer3_Wide_32_64|| timer==Timer4_Wide_32_64||timer==Timer5_Wide_32_64)
        {
           HW_WRITE_REG_32BIT(timer+GPTMTBILR,load);
        }
        else
            state = TIMER_NOT_EXIST;
        return state;
}
