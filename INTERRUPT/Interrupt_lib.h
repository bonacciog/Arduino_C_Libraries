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

#ifndef _LCD_H_
#define _LCD_H_

#include "common_commands.h"

/*
*
*	Handler di gestione interrupt.
*	Scatta quando l'interrupt passato
*	come parametro subisce un fronte
*	di salita (se pull down) o discesa 
*	(se pull-up)
*	
*/
interrupt_handler(PCINT0_vect);

#endif