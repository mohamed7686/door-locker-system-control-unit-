/*
 * passwords.h
 *
 *  Created on: Oct 10, 2019
 *      Author: The Master
 */

#ifndef PASSWORDS_H_
#define PASSWORDS_H_

#include "timer.h"
#include "lcd.h"
#include "usart.h"
#include "external_eeprom.h"
#include "i2c.h"



#define original_pass_loc   0x0311
#define repeated_pass_loc   0x0411


uint8 entering_password(void);
void change_password(void);
uint8 pass_equality_check(void);
//static void catch_password(uint8 *arr);

#endif /* PASSWORDS_H_ */
