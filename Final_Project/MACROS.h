/*
 * MACROS.h
 *
 *  Created on: Jan 12, 2019
 *      Author: Hanoon-PC
 */

#ifndef MACROS_H_
#define MACROS_H_


#define SetBit(value,bit) value|=(1<<bit)

#define ClrBit(value,bit) value&=~(1<<bit)

#define ToggleBit(value,bit) value^=(1<<bit)

#define GetBit(value,bit) ((value>>bit)&1)

#define PORT_A 0
#define PORT_B 1
#define PORT_C 2
#define PORT_D 3

#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN5 5
#define PIN6 6
#define PIN7 7

#endif /* MACROS_H_ */
