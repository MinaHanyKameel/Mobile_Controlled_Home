/*
 * HBluetooth_UART.h
 *
 *  Created on: Mar 13, 2019
 *      Author: Hanoon-PC
 */

#ifndef H_BLUETOOTH_UART_H_
#define H_BLUETOOTH_UART_H_

void Bluetooth_vidSendString(u8* Data);
void Bluetooth_vidInit(void);
u8 Bluetooth_u8Receive(void);
void Bluetooth_vidSend(u8 Data);
extern void Bluetooth_vidWriteNumber(u32 Number);


#endif /* H_BLUETOOTH_UART_H_ */
