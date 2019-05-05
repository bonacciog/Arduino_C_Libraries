/*
*					 Tesi di laurea
*			  			   in
*				Calcolatori Elettronici T
*
*	Sviluppo di progetti per fini didattici con Arduino
*
*
*					GIOVANNI BONACCIO
*/

#ifndef _COMMON_COMMANDS_H_
#define _COMMON_COMMANDS_H_


#include <avr/io.h> 
#include <util/delay.h> 
#include <avr/interrupt.h>

#define BYTE unsigned char												
#define interrupt_handler(vector) ISR(vector)




/*
*	Setta la direzione dei dati (INPUT/OUTPUT) 
*	relativa ai bit (uno per ogni pin) della porta X
*	
*	OUTPUT: Passare come parametro un BYTE formato
*			da tutti 0 tranne i bit relativi ai pin
*			da utilizzare come OUTPUT
*
*	INPUT:	Passare come parametro un BYTE formato
*			da tutti 1 tranne i bit relativi ai pin
*			da utilizzare come INPUT	
*/			
void port_setup_set_data_direction_output_bits_port_B(BYTE code);				

void port_setup_set_data_direction_output_bits_port_C(BYTE code);

void port_setup_set_data_direction_output_bits_port_D(BYTE code);

void port_setup_set_data_direction_input_bits_port_B(BYTE code);				

void port_setup_set_data_direction_input_bits_port_C(BYTE code);

void port_setup_set_data_direction_input_bits_port_D(BYTE code);




/*
*	Setta il valore dei bit (HIGH/LOW) 
*	della porta X
*	
*	HIGH: 	Passare come parametro un BYTE formato
*			da tutti 0 tranne i bit relativi ai pin
*			a cui si vuole assegnare il valore HIGH
*
*	LOW:	Passare come parametro un BYTE formato
*			da tutti 1 tranne i bit relativi ai pin
*			a cui si vuole assegnare il valore LOW	
*/

void port_set_high_bits_port_B(BYTE code);

void port_set_high_bits_port_C(BYTE code);

void port_set_high_bits_port_D(BYTE code);

void port_set_low_bits_port_B(BYTE code);

void port_set_low_bits_port_C(BYTE code);

void port_set_low_bits_port_D(BYTE code);




/*
*	Setta la direzione o il valore
*	di tutti i bit della porta X
*/

void port_set_all_bits_port_B(BYTE code);

void port_set_all_bits_port_C(BYTE code);

void port_set_all_bits_port_D(BYTE code);

void port_set_all_bits_data_direction_port_B(BYTE code);

void port_set_all_bits_data_direction_port_C(BYTE code);

void port_set_all_bits_data_direction_port_D(BYTE code);




/*
*	Restituisce un BYTE contenente 
*	il valore dei bit relativi alla
*	porta X 
*/
BYTE port_get_bits_port_B();

BYTE port_get_bits_port_C();

BYTE port_get_bits_port_D();


		//	SEZIONE INTERRUPT

/*
*	Abilita la gestione degli interrupt
*/
void interrupt_enable();




/*
*	Disabilita la gestione degli interrupt
*/
void interrupt_disable();




/*		
*	Permette di abilitare nel registro PCICR
*	il PCIE (bit 0,1 o 2) relativo a una 
*	delle tre maschere (0,1 o 2)
*/
void interrupt_pcicr_setup_set_interrupt_bits_pcie(BYTE code);




/*
*	Permette di attivare l'interrupt al bit
*	relativo al pin collegato attraverso
*	la maschera 0,1 o 2
*/
void interrupt_msk_setup_set_interrupt_0_7_bits_pcmsk_0(BYTE code);

void interrupt_msk_setup_set_interrupt_8_14_bits_pcmsk_1(BYTE code);

void interrupt_msk_setup_set_interrupt_16_23_bits_pcmsk_2(BYTE code);

#endif
