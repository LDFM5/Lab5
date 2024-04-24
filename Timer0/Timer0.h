/*
 * Timer0.h
 *
 * Created: 22/04/2024 22:17:25
 *  Author: luisd
 */ 


#ifndef Timer0_H_
#define Timer0_H_

#include <stdint.h>
#include <avr/io.h>

void init_Timer0(int modo, int preescaler);
void CTC_Timer0A(uint8_t valor);
void CTC_Timer0B(uint8_t valor);





#endif /* Timer0_H_ */