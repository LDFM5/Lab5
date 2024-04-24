/*
 * PWM2.h
 *
 * Created: 17/04/2024 16:53:56
 *  Author: luisd
 */ 

#ifndef PWM1_H_
#define PWM1_H_
#include <stdint.h>
#include <avr/io.h>

void init_PWM2(int orientacion,int modo, int preescaler);
//void init_PWM1B(int orientacion);
void duty_cycle2(uint8_t duty);
//void duty_cycle1B(uint16_t duty);


#endif /* PWM1_H_ */