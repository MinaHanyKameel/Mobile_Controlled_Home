/*
 * ADC.h
 *
 *  Created on: Feb 9, 2019
 *      Author: Hanoon-PC
 */

#ifndef D_ADC_H_
#define D_ADC_H_

#define ADMUX *((volatile u8*)0x27)

#define ADCSRA *((volatile u8*)0x26)

#define ADCRegister *((volatile u16*)0x24)

#define ADCH *((volatile u8*)0x25)

#define ADCL *((volatile u8*)0x24)

#define SFIOR *((volatile u8*)0x50)

/*
 * ADMUX PINS
 * 				*/
/*Analog Channel and Gain Selection Bits*/
#define MUX0 PIN0
#define MUX1 PIN1
#define MUX2 PIN2
#define MUX3 PIN3
#define MUX4 PIN4
/*ADC Left Adjust Result*/
#define ADLAR PIN5
/*Reference Selection Bits*/
#define REFS0 PIN6
#define REFS1 PIN7

/*
 * ADCSRA
 * 				*/
/*ADC Prescaler Select Bits*/
#define ADPS0 PIN0
#define ADPS1 PIN1
#define ADPS2 PIN2
/*ADC Interrupt Enable*/
#define ADIE PIN3
/*ADC Interrupt Flag*/
#define ADIF PIN4
/*ADC Auto Trigger Enable*/
#define ADATE PIN5
/*ADC Start Conversion*/
#define ADSC PIN6
/*ADC Enable*/
#define ADEN PIN7

/*
 * SFIOR
 * 					*/
/*ADC Auto Trigger Source Selections*/
#define ADTS0 PIN5
#define ADTS1 PIN6
#define ADTS2 PIN7

/*
 * Functions Prototypes
 * 						*/

void ADC_vidInit(void);

u16 ADC_vidReturnResult(void);


#endif /* D_ADC_H_ */
