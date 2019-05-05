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
#include "common_commands.h"

void port_setup_set_data_direction_output_bits_port_B(BYTE code)
{
	DDRB = DDRB | code;
}				

void port_setup_set_data_direction_output_bits_port_C(BYTE code)
{
	DDRC = DDRC | code;
}

void port_setup_set_data_direction_output_bits_port_D(BYTE code)
{
	DDRD = DDRD | code;
}	

void port_setup_set_data_direction_input_bits_port_B(BYTE code)
{
	DDRB = DDRB & code;
}				

void port_setup_set_data_direction_input_bits_port_C(BYTE code)
{
	DDRC = DDRC & code;
}

void port_setup_set_data_direction_input_bits_port_D(BYTE code)
{
	DDRD = DDRD & code;
}

void port_set_high_bits_port_B(BYTE code)
{
	PORTB = PORTB | code;
}

void port_set_high_bits_port_C(BYTE code)
{
	PORTC = PORTC | code;
}

void port_set_high_bits_port_D(BYTE code)
{
	PORTD = PORTD | code;
}

void port_set_low_bits_port_B(BYTE code)
{
	PORTB = PORTB & code;
}

void port_set_low_bits_port_C(BYTE code)
{
	PORTC = PORTC & code;
}

void port_set_low_bits_port_D(BYTE code)
{
	PORTD = PORTD & code;
}

void port_set_all_bits_port_B(BYTE code)
{
	PORTB = code;
}

void port_set_all_bits_port_C(BYTE code)
{
	PORTC = code;
}

void port_set_all_bits_port_D(BYTE code)
{
	PORTD = code;
}

void port_set_all_bits_data_direction_port_B(BYTE code)
{
	DDRB = code;
}

void port_set_all_bits_data_direction_port_C(BYTE code)
{
	DDRC = code;
}

void port_set_all_bits_data_direction_port_D(BYTE code)
{
	DDRD = code;
}

BYTE port_get_bits_port_B()
{
	return PORTB;
}

BYTE port_get_bits_port_C()
{
	return PORTC;
}

BYTE port_get_bits_port_D()
{
	return PORTD;
}

void interrupt_msk_setup_set_interrupt_0_7_bits_pcmsk_0(BYTE code)
{
	PCMSK0 = PCMSK0 | code;
}

void interrupt_msk_setup_set_interrupt_8_14_bits_pcmsk_1(BYTE code)
{
	PCMSK1 = PCMSK1 | code;
}

void interrupt_msk_setup_set_interrupt_16_23_bits_pcmsk_2(BYTE code)
{
	PCMSK2 = PCMSK2 | code;
}

void interrupt_pcicr_setup_set_interrupt_bits_pcie(BYTE code)
{
	PCICR = PCICR | code;
}

void interrupt_enable()
{
	sei();
}

void interrupt_disable()
{
	cli();
}