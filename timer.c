/*
 * timer.c
 *
 *  Created on: Oct 11, 2019
 *      Author: The Master
 */
#include "timer.h"
 uint8 flag=0;
 extern uint8 flag2=0;

ISR(TIMER1_COMPA_vect)
{
	flag++;
	if(flag==15 && flag2==0){
		SET_BIT(PORTC,motor_l);
		CLEAR_BIT(PORTC,motor_r);
		UART_sendByte(1);
	}
	if(flag==30 && flag2==0){
		CLEAR_BIT(PORTC,motor_r);
		CLEAR_BIT(PORTC,motor_l);
		UART_sendByte(1);
		timer1_deinit_CTC_mode();
		flag=0;
	}
	if(flag==60 && flag2==1){
		flag2=0;
		flag=0;
		CLEAR_BIT(PORTC,buzz);
		UART_sendByte(1);
		timer1_deinit_CTC_mode();
	}
}

void timer1_init_CTC_mode(void)
{
	TCNT1 = 0; //timer initial value
	OCR1A  = 900; //compare value
	TIMSK |= (1<<OCIE1A); //enable compare interrupt for channel A
	/* Configure timer1 control registers
	 * 1. Non PWM mode FOC1A=1 and FOC1B=1
	 * 2. No need for OC1A & OC1B in this example so COM1A0=0 & COM1A1=0 & COM1B0=0 & COM1B1=0
	 * 3. CTC Mode and compare value in OCR1A WGM10=0 & WGM11=0 & WGM12=1 & WGM13=0
	 */
	TCCR1A = (1<<FOC1A) | (1<<FOC1B);
	/*
	 * 4. Clock = F_CPU/1024 CS10=1 CS11=0 CS12=1
	 */
	TCCR1B = (1<<WGM12) | (1<<CS10) | (1<<CS12);
}


void timer1_deinit_CTC_mode(void)
{

	TIMSK &= ~(1<<OCIE1A); //enable compare interrupt for channel A

}
