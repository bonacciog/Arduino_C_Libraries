# Arduino_C_Libraries

Implementation of libraries written in C pure languague and using AVR Compiler, for devices:

  - 7 Segments Display
  - LCD Display
  - 8x8 Led Matrix
  - A simple led
  
 
 For more information:

  - https://github.com/bonacciog/Arduino_C_Libraries/blob/docs-ita/TESI-GIOVANNIBONACCIO.pdf
  - https://github.com/bonacciog/Arduino_C_Libraries/blob/docs-ita/Tesi%20Presentazione.pdf

To compile and execute:

    $ avr-gcc -Os -mmcu=atmega328p -DF_CPU=16000000UL -o led.o lampeggioLED.c commands.c
            
    $ avr-ld -o led.elf led.o
            
    $ avr-objcopy -j .text -j .data -O ihex led.o led.hex
            
    $ avrdude -F -V -c arduino -p ATMEGA328P -P /dev/ttyACM0 -b 115200 -U flash:w:led.hex


 To show the assembly code:

    $ avr-objdump -h -S led.elf>led.lst
