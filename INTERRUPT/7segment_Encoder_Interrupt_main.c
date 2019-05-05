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
#include "Interrupt_lib.h"
#include "7segments.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h> 

        //  Contatore Interrupt Ricevute
char counter[] = { '0', '0', '0', '0'};

int main(void)
{
        //  Input        : interrupt PCINT2 Bit 2 della porta B (pin 10)
        //  Output       : CLK a pin 12 (PB4) e DIO a pin 11 (PB3)       
  interrupt_disable();
        
    //  DIO -> OUTPUT
    //  CLK -> OUTPUT
  port_setup_set_data_direction_output_bits_port_B(0b00011000);
    //  CLK -> LOW
  port_set_low_bits_port_B(0b11101111);
    //  DIO -> LOW
  port_set_low_bits_port_B(0b11110111);

    //  setup del pin 10 come input 
  port_setup_set_data_direction_input_bits_port_B(0b11111011);
    //  Abilito pull-down                                
  port_set_high_bits_port_B(0b11111011);                                                    
    //  Abilito il Bit relativo a PCINT4 nella maschera PCMSK0
  interrupt_msk_setup_set_interrupt_0_7_bits_pcmsk_0(0b00000100);  
    //  Abilito la maschera 0 nel registro PCICR                                            
  interrupt_pcicr_setup_set_interrupt_bits_pcie(0b00000001);
  
    //  setup interrupt
  interrupt_enable(); 

    //  Inizializzo i display tutti a 0
  BYTE initial_segments[] = { 0b00111111, 0b00111111, 0b00111111, 0b00111111 };
  display_7segments_set_segments(initial_segments, 4, 0);
  while(1)
  { 
    _delay_ms(500);                                                                             
  }
}

        //  la funzione interrupt handler non ha un valore di ritorno perchè la funzione sorgente (ISR, vedi commands.h) è stata definita senza valore di ritorno in avr/interrupt.h
interrupt_handler(PCINT0_vect)
{
    //  Algoritmo contatore
  int counter_temp = atoi(counter);
  counter_temp++;
  if(counter_temp<=9)
    sprintf(counter, "000%d", counter_temp);
  else if(counter_temp>9 && counter_temp<=99)
    sprintf(counter, "00%d", counter_temp);
  else if(counter_temp>99 && counter_temp<=999)
    sprintf(counter, "0%d", counter_temp);
  else if(counter_temp>999 && counter_temp<=9999)
    sprintf(counter, "%d", counter_temp);
  else
    strcpy(counter, "0000");

    //  Scrittura del numero attuale
  display_7segments_set_segment(digitToSegment[(int) counter[DISPLAY_3_ADDR] - '0'], DISPLAY_3_ADDR);
  display_7segments_set_segment(digitToSegment[(int) counter[DISPLAY_2_ADDR] - '0'], DISPLAY_2_ADDR);
  display_7segments_set_segment(digitToSegment[(int) counter[DISPLAY_1_ADDR] - '0'], DISPLAY_1_ADDR);
  display_7segments_set_segment(digitToSegment[(int) counter[DISPLAY_0_ADDR] - '0'], DISPLAY_0_ADDR);
}
