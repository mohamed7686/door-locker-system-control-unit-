/*
 * timer.h
 *
 *  Created on: Oct 11, 2019
 *      Author: The Master
 */

#ifndef TIMER_H_
#define TIMER_H_

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "std_types.h"
#include "common_macros.h"

#define  motor_r   PD2
#define  motor_l   PD3
#define  buzz      PC2

void timer1_init_CTC_mode(void);
void timer1_deinit_CTC_mode(void);

#endif /* TIMER_H_ */
