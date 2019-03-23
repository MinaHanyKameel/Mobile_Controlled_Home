/*
 * ALogin.h
 *
 *  Created on: Mar 13, 2019
 *      Author: Hanoon-PC
 */

#ifndef A_LOGIN_H_
#define A_LOGIN_H_

#define User1 1
#define User2 2
#define User3 3
#define NOTVALID 4
#define VALID 5

u8 Login_u8CheckUserNameAndPW(void);
//u8 Login_u8CheckUserNameAndPWinternalEEPROM(void);
u8 Login_u8LoginOperation(void);


#endif /* A_LOGIN_H_ */
