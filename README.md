# Arduino_C_Libraries

Implementation of libraries written in C pure languague and using AVR Compiler, for devices:

  - 7 Segments Display
  - LCD Display
  - 8x8 Led Matrix
  - A simple led
  
 
 For more information:

  - [.git/objects/79/e108a03ca2c24d2904638d8d14d241335f72cc](http://)

To compile and execute:

    $ avr-gcc -Os -mmcu=atmega328p -DF_CPU=16000000UL -o led.o lampeggioLED.c commands.c
            
    $ avr-ld -o led.elf led.o
            
    $ avr-objcopy -j .text -j .data -O ihex led.o led.hex
            
    $ avrdude -F -V -c arduino -p ATMEGA328P -P /dev/ttyACM0 -b 115200 -U flash:w:led.hex


 To show the assembly code:

    $ avr-objdump -h -S led.elf>led.lst
