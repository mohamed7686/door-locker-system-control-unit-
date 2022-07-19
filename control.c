/*
 * interfacing.c
 *
 *  Created on: Oct 6, 2019
 *      Author: The Master
 */







#include "passwords.h"
uint8 flag2;

int main (void){
uint8 t;

DDRC |=(1<<buzz);
DDRD |=(1<<motor_r)|(1<<motor_l);
SREG |=(1<<7);
UART_init();

change_password();

while(1){

do{
	t=UART_recieveByte();
}
while(t !=1 && t!=2);

if(t==1){
	if(entering_password()==2){
		CLEAR_BIT(PORTC,motor_r);
		CLEAR_BIT(PORTC,motor_l);
		SET_BIT(PORTC,buzz);
	    flag2=1;
		timer1_init_CTC_mode();
		while(flag2==1){}
	}
	else{SET_BIT(PORTC,motor_r);
	CLEAR_BIT(PORTC,motor_l);
	timer1_init_CTC_mode();
	}
}
else {
	if(entering_password()==2){
		CLEAR_BIT(PORTC,motor_r);
				CLEAR_BIT(PORTC,motor_l);
				SET_BIT(PORTC,buzz);
			    flag2=1;
				timer1_init_CTC_mode();
				while(flag2==1){}
	     continue;}
	else{
		change_password();
	}

}
}

}

