# File:   Makefile
# Author: M. P. Hayes, UCECE
# Date:   12 Sep 2010
# Descr:  Makefile for lab2-ex5

# Definitions.
CC = avr-gcc
CFLAGS = -mmcu=atmega32u2 -Os -Wall -Wstrict-prototypes -Wextra -g -I. -I./drivers/avr -I./utils -I./drivers
OBJCOPY = avr-objcopy
SIZE = avr-size
DEL = rm


# Default target.
all: testing.out


# Compile: create object files from C source files.
testing.o: testing.c drivers/ledmat.h drivers/avr/system.h
	$(CC) -c $(CFLAGS) $< -o $@

system.o: drivers/avr/system.c drivers/avr/system.h
	$(CC) -c $(CFLAGS) $< -o $@

pio.o: drivers/avr/pio.c drivers/avr/pio.h drivers/avr/system.h
	$(CC) -c $(CFLAGS) $< -o $@

ledmat.o: drivers/ledmat.c drivers/ledmat.h  drivers/avr/pio.h drivers/avr/system.h
	$(CC) -c $(CFLAGS) $< -o $@


# Link: create ELF output file from object files.
testing.out: testing.o system.o ledmat.o pio.o
	$(CC) $(CFLAGS) $^ -o $@ -lm
	$(SIZE) $@


# Target: clean project.
.PHONY: clean
clean:
	-$(DEL) *.o *.out *.hex


# Target: program project.
.PHONY: program
program: testing.out
	$(OBJCOPY) -O ihex testing.out testing.hex
	dfu-programmer atmega32u2 erase; dfu-programmer atmega32u2 flash testing.hex; dfu-programmer atmega32u2 start
