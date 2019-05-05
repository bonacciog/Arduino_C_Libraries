/*
*          Tesi di laurea
*                in
*       Calcolatori Elettronici T
*
* Sviluppo di progetti per fini didattici con Arduino
*
*
*         GIOVANNI BONACCIO
*/

#ifndef _7SEGMENTS_H_
#define _7SEGMENTS_H_

#include "common_commands.h"

    //  Output: CLK a pin 12 (PB4) e DIO a pin 11 (PB3)


#define CONTROLLER_IO_COMMAND1    		0b01000000
#define CONTROLLER_IO_COMMAND2    		0b11000000
#define CONTROLLER_IO_COMMAND3    		0b10000000
#define	CONTROLLER_SET_DISPLAY_OFF		0b00000000 
#define	CONTROLLER_SET_DISPLAY_ON     0b00001000 

#define DISPLAY_3_ADDR 3
#define DISPLAY_2_ADDR 2
#define DISPLAY_1_ADDR 1
#define DISPLAY_0_ADDR 0

static BYTE default_brightness = 7;

static BYTE digitToSegment[] = {

  0b00111111,    // 0
  0b00000110,    // 1
  0b01011011,    // 2
  0b01001111,    // 3
  0b01100110,    // 4
  0b01101101,    // 5
  0b01111101,    // 6
  0b00000111,    // 7
  0b01111111,    // 8
  0b01101111,    // 9
  0b01110111,    // A
  0b01111100,    // b
  0b00111001,    // C
  0b01011110,    // d
  0b01111001,    // E
  0b01110001     // F
};

/*
*	Accende i segmenti sul display
*	passati come parametro a partire 
*	dalla posizione iniziale
*/
void display_7segments_set_segments(BYTE segments[], BYTE lenght, BYTE starter_position);

/*
*	Accende i segmenti di una sola cifra 
*	sul displaypassati come parametro 
*	a partire dalla posizione iniziale
*/
void display_7segments_set_segment(BYTE segment, BYTE position);

#endif