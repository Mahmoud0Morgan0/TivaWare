/*
 * hw_timers.h
 *
 *  Created on: Feb 3, 2018
 *      Author: Morgan
 */

#ifndef RAL_HW_TIMERS_H_
#define RAL_HW_TIMERS_H_

#define Timer0_16_32            0x40030000
#define Timer1_16_32            0x40031000
#define Timer2_16_32            0x40032000
#define Timer3_16_32            0x40033000
#define Timer4_16_32            0x40034000
#define Timer5_16_32            0x40035000
#define Timer0_Wide_32_64       0x40036000
#define Timer1_Wide_32_64       0x40037000
#define Timer2_Wide_32_64       0x4003C000
#define Timer3_Wide_32_64       0x4003D000
#define Timer4_Wide_32_64       0x4003E000
#define Timer5_Wide_32_64       0x4003F000


#define GPTMCFG                   0x000
#define GPTMTAMR                  0x004
#define GPTMTBMR                  0x008
#define GPTMCTL                   0x00C
#define GPTMSYNC                  0x010
#define GPTMIMR                   0x018
#define GPTMRIS                   0x01C
#define GPTMMIS                   0x020
#define GPTMICR                   0x024
#define GPTMTAILR                 0x028
#define GPTMTBILR                 0x02C
#define GPTMTAMATCHR              0x030
#define GPTMTBMATCHR              0x034
#define GPTMTAPR                  0x038
#define GPTMTBPR                  0x03C
#define GPTMTAPMR                 0x040
#define GPTMTBPMR                 0x044
#define GPTMTAR                   0x048
#define GPTMTBR                   0x04C
#define GPTMTAV                   0x050
#define GPTMTBV                   0x054
#define GPTMRTCPD                 0x058
#define GPTMTAPS                  0x05C
#define GPTMTBPS                  0x060
#define GPTMTAPV                  0x064
#define GPTMTBPV                  0x068
#define GPTMPP                    0xFC0



#endif /* RAL_HW_TIMERS_H_ */
