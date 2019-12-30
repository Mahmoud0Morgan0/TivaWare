

/**
 * main.c
 */
#include <stdbool.h>
#include <stdint.h>
#include "driverlib\sysctl.h"
#include"App/app_gpio.h"
#include"HAL/timers.h"
#include"APP/app_uart.h"
#include"HAL/can.h"
int main(void)
{
    initAppropriateCANPins(CAN0_MOD);
    HW_WRITE_MASKED_REG(BASE_B+GPIO_DIGITAL_EN_OFFSET,13,10,0x3C00);
    int clockspeed=0;
    //setSysClock(MAIN_OSC, c16MHZ);
    clockspeed=SysCtlClockGet();
    gGPIOObj_t inPin ;
    gUARTCFG_t UARTobj;
    UARTobj.FIFOsEnable=FALSE;
    UARTobj.clockSource=SYSTEM_CLOCK;
    UARTobj.parityEnable=FALSE;
    UARTobj.stopBits=ONE_STOP_BIT;
    UARTobj.wordLength=EIGHT_BITS;
    UARTobj.integarDiv=104;
    UARTobj.fractionaldiv=11;
    UARTobj.uart=UART0_MODULE;
    inPin.base=BASE_F;
    inPin.dir=INPUT;
    inPin.pin_num=0;
    inPin.configPadObj.resType=PULL_UP_RES;
    inPin.configPadObj.lockFlag=FALSE;
    inPin.configPadObj.currentVal=CURRENT_2MA;
    initPort(&inPin,0b11101110);
    //Timer init
    clockGatingTimers(TIMER0);
    disableTimer(Timer0_16_32);
    selectTimerWidth(Timer0_16_32, FULL);
    selectTimerAMode(Timer0_16_32, PERIODIC);
    selectCountTypeA(Timer0_16_32, COUNT_UP);
    setTimerAIntervalLoad(Timer0_16_32, 0x04c4b400);
    enableTimer(Timer0_16_32);
    uint8 data ;
    //uint8 counter=0;
   // uint32 i,j;
    initUART(&UARTobj);
    sendChar(UART0_MODULE, 'm') ;
    while(1)
    {
        getChar(UART0_MODULE, &data);
        // sendChar(UART0_MODULE, 'm') ;
        if (data == 'r')
        {
            digitalPortWrite(&inPin, RGB_RED);
        }
        else if (data == 'b')
        {
            digitalPortWrite(&inPin, RGB_BLUE);
        }
        else if (data == 'y')
        {
            digitalPortWrite(&inPin, RGB_YELLOW);
        }
        else if (data == 'g')
        {
            digitalPortWrite(&inPin, RGB_GREEN);
        }
        else if (data == 's')
        {
            digitalPortWrite(&inPin, RGB_SKYBLUE);
        }
        else if (data == 'p')
        {
            digitalPortWrite(&inPin, RGB_PINk);
        }
        else if (data == 'w')
        {
            digitalPortWrite(&inPin, RGB_WHITE);
        }else
            digitalPortWrite(&inPin, 0);

        /*digitalPortWrite(&inPin, counter);
         if(HW_READ_BIT(Timer0_16_32+GPTMRIS,0)==1)
         {
         counter+=2;
         HW_WRITE_BIT(Timer0_16_32+GPTMICR,0,1);
         }*/

    }
	return 0;
}
