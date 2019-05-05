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

int main(void)
{

        //  Input        : interrupt PCINT4 Bit 4 della porta B (pin 12)
        //  Output       : Bit 7 della porta D (pin 7)        
  interrupt_disable();
        

        //  setup del pin 7 come output
  port_setup_set_data_direction_output_bits_port_D(0b10000000); 
  port_set_low_bits_port_D(0b01111111);

        //  setup del pin 12 come input 
  port_setup_set_data_direction_input_bits_port_B(0b11101111);
        //  Abilito pull-down                                
  port_set_high_bits_port_B(0b11101111);                                                    
        //  Abilito il Bit relativo a PCINT4 nella maschera PCMSK0
  interrupt_msk_setup_set_interrupt_0_7_bits_pcmsk_0(0b00010000);  
        //  Abilito la maschera 0 nel registro PCICR                                            
  interrupt_pcicr_setup_set_interrupt_bits_pcie(0b00000001);
  
        //  setup interrupt
  interrupt_enable();                                                                        
  
  while(1)
  { 
    _delay_ms(500);                                                                             
  }
  
}

        //  la funzione interrupt handler non ha un valore di ritorno perchè la funzione sorgente (ISR, vedi commands.h) è stata definita senza valore di ritorno in avr/interrupt.h
interrupt_handler(PCINT0_vect)
{
        //  inverte stato del bit 0 della porta B
  if(port_get_bits_port_D() == 0b10000000)
    port_set_low_bits_port_D(0b01111111);
  else
    port_set_high_bits_port_D(0b10000000);
}
