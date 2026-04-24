MCU = atmega328p
F_CPU = 16000000UL

CC = avr-gcc
OBJCOPY = avr-objcopy
AVRDUDE = avrdude

PORT = /dev/ttyUSB0
BAUD = 115200
PROGRAMMER = arduino

TARGET = main
SRC = src/main.c src/display.c

OBJ = $(SRC:.c=.o)

CFLAGS = -mmcu=$(MCU) -DF_CPU=$(F_CPU) -Os -Wall

all: $(TARGET).hex

# Compila cada .c separadamente
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Linka tudo
$(TARGET).elf: $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

# Gera hex
$(TARGET).hex: $(TARGET).elf
	$(OBJCOPY) -O ihex -R .eeprom $< $@

# Upload
flash: $(TARGET).hex
	$(AVRDUDE) -c $(PROGRAMMER) -p $(MCU) -P $(PORT) -b $(BAUD) -U flash:w:$(TARGET).hex:i

clean:
	rm -f src/*.o *.elf *.hex
