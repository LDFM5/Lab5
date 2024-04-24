/*
 * Timer0.c
 *
 * Created: 22/04/2024 22:17:43
 *  Author: luisd
 */ 
#include "Timer0.h"

void init_Timer0(int modo, int preescaler){
	TCCR0A=0;
	TCCR0B=0;
	TIMSK0=0;
	
	if (modo==0){
		//Habilitar interrupciones por overflow
		TIMSK0 |= (1<<TOIE0);
	}
	if (modo==1){
		//MODO CTC
		TCCR0A |= (1<<WGM01);
		//Habilitar interrupciones por comparación
		TIMSK0 |= (1<<OCIE0A);
	}
	
	//Definimos el preescaler
	switch(preescaler){
		case 1:
		TCCR0B |= (1<<CS00);
		break;
		case 8:
		TCCR0B |= (1<<CS01);
		break;
		case 64:
		TCCR0B |= (1<<CS01)|(1<<CS00);
		break;
		case 256:
		TCCR0B |= (1<<CS02);
		break;
		case 1024:
		TCCR0B |= (1<<CS02)|(1<<CS00);
		break;
	}
}

void CTC_Timer0A(uint8_t valor){
	OCR0A = valor;
}