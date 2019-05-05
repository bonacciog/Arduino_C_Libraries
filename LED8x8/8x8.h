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

#ifndef _8x8_H
#define _8x8_H
#include "common_commands.h"

	// CLK -> pin 12 (PB4), DIN -> pin 10 (PB2), CS -> pin 11 (PB3)

/*
*	Scrive i dati all'indirizzo passato come parametro
*
*/
void led_matrix_8x8_write_data_output(BYTE address, BYTE data);

/*
*
*	Setta impostazioni di default
*
*/
void led_matrix_8x8_set_default_setting();

#endif