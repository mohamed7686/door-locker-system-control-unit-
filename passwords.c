/*
 * passwords.c
 *
 *  Created on: Oct 10, 2019
 *      Author: The Master
 */

#include "passwords.h"



/////////////////////////////////////////function to catch pass in an array/////////////////////////////////////

static void catch_password(const uint16 address){
	uint8 i=0;
	uint8 t;
	do{
	  t =UART_recieveByte();
		EEPROM_writeByte(address+i,t);
		i++;

	}
	while(t !=42);

}

///////////////////////////// function that check that the pass the user entered right /////////////////////////

/*
 * the function return 1 if entered pass matches
 * and 0 if wrong pass
 */

uint8 pass_equality_check(){
	uint8 i=0;
	uint8 arr1[10];
	uint8 arr2[10];
	EEPROM_readByte(original_pass_loc,arr1);
	_delay_ms(10);
	EEPROM_readByte(repeated_pass_loc,arr2 );
	while(arr1[i] !=42 || arr2[i] != 42){
		if (arr1[i] == arr2[i]){

		}
		else {UART_sendByte(0);
			return 0; }
		i++;
		EEPROM_readByte(original_pass_loc+i,arr1);
		_delay_ms(10);
		EEPROM_readByte(repeated_pass_loc+i,arr2 );
	}
	UART_sendByte(1);
	return 1;
}

////////////////////// function to change pass ///////////////////////////////////////

void change_password(void){
	do{

	catch_password(original_pass_loc);
	_delay_ms(10);
	catch_password(repeated_pass_loc);
	}
	while(!(pass_equality_check()));
}

////////////////// function used to ask you enter a pass //////////////////////////////////////
/*
 * ask you for a pass if wrong it gives you a 3 trials
 * it returns the number of wrong trials
 */

uint8 entering_password(void){

	uint8 i;
			catch_password(repeated_pass_loc);
		for( i=0;i<2 && !(pass_equality_check());i++){
		catch_password(repeated_pass_loc);
		}
		return i ;

}
