/*
 * Lab5.c
 *
 * Created: 16/04/2024 18:32:29
 * Author : luisd
 */ 
#define F_CPU 16000000
//#include <xc.h>
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "PWM1/PWM1.h"
#include "PWM2/PWM2.h"
#include "ADC/ADC.h"
#include "Timer0/Timer0.h"
volatile uint8_t valorADC=0;
volatile uint8_t contador = 0;
volatile uint8_t PuertoADC=4;
volatile uint16_t top=0;
volatile uint8_t valor = 0;



void init_pines(void){
		// Configurar los pines PC4, PC5 y A6 como entradas y habilitar resistencias de pull-up
		DDRC &= ~(1 << DDC4) & ~(1 << DDC5) & ~(1 << DDC6);
		PORTC |= (1 << PORTC4) | (1 << PORTC5)| (1 << PORTC6);
		
		DDRD |= (1 << DDD6);
	
}

uint16_t reescalar(uint8_t valor, uint8_t max_origen, uint16_t max_destino) {
	// Escalar el valor al rango 0 - max_destino
	uint16_t valor_reescalado = (float)valor / max_origen * max_destino;
	//INICIAR TIMER0 (DUTY CYCLE)
	return valor_reescalado;
}

int main() {
	CLKPR = CLKPCE;
	CLKPR = CLKPS0;
	contador = 0;
	init_pines();
	//frecuencia del adc -> 16M/128 = 125kHz
	init_ADC(0,0,128);
	
	top = 155;
	int preescaler1=1024;
	
	int preescaler2 = 1024;
	
	init_PWM1A(0,6,preescaler1, top);
	init_PWM2(0, 3, preescaler2);
	init_Timer0(1,1024);
	OCR0A = 1;
	
	//sei();

	while (1) {
	contador++;
	
		/*if (PuertoADC==4)
		{
			valor = readADC(4);
			uint16_t valor_reescalado = reescalar(valor, 255, 40);
			duty_cycle1A(valor_reescalado);
			PuertoADC++;
		} else if (PuertoADC==5)
		{
			valor = readADC(5);
			uint8_t valor_reescalado2 = reescalar(valor, 255, 40);
			duty_cycle2(valor_reescalado2);
			PuertoADC++;
			} else{
			*/valor = readADC(6);
			//uint8_t valor_reescalado3 = reescalar(valor, 255, 200);
			if (contador == valor) {
				PORTD |= (1 << DDD6); // Encender el LED
				contador =0;
				} else {
				PORTD &= ~(1 << DDD6); // Apagar el LED
			}
			//INICIAR TIMER0 (DUTY CYCLE)
			//contador = valor;
			/*PuertoADC=4;
		}*/
	}
	return 0;
}

ISR(TIMER0_COMPA_vect) {
}
