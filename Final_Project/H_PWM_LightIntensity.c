/*
 * H_PWM_LightIntensity.c
 *
 *  Created on: Mar 17, 2019
 *      Author: Hanoon-PC
 */

#include "TYPES.h"
#include "MACROS.h"
#include "H_PWM_LightIntensity.h"

#include "D_Timer0.h"
//#include "D_Timer1.h"

void PWM_vidPWM_LightInit(void)
{
//	//Clear OC1A/OC1B on compare match when up-counting. Set OC1A/OC1B on compare match when downcounting
//	Timer1_vidCompareOutputMode(1,0);
//
//	// Fast PWM TOP ICR1
//	Timer1_vidTimer1Mode(1,1,1,0);
//
//	//1 0 0 clkI/O/256 (From prescaler)
//	Timer1_vidSetPrescaler(0,0,1);
//
//	Timer1_VidSetICR1(ICR1Set);
	Timer0_vidInint();
}

void PWM_vidChangeLightIntensity(u8 Percentage)
{
//	Timer1_VidSetOCR1A(Percentage);
	Timer0_vidSetOcr0((Percentage*255)/100);
}
