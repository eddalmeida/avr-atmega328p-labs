MCU = atmega328p
F_CPU = 16000000UL

CC = avr-gcc
OBJCOPY = avr-objcopy

TARGET = main
SRC = src/main.c

CFLAGS = -mmcu=$(MCU) -DF_CPU=$(F_CPU) -Os -Wall

all: $(TARGET).hex

$(TARGET).o: $(SRC)
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET).elf: $(TARGET).o
	$(CC) -mmcu=$(MCU) $< -o $@

$(TARGET).hex: $(TARGET).elf
	$(OBJCOPY) -O ihex -R .eeprom $< $@

clean:
	rm -f *.o *.elf *.hex