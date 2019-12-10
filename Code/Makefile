all : bin

bin : main.c
	avr-gcc -std=c99 -Os -mmcu=atmega128 main.c USART.c SPI_led.c capt_Hall.c -D F_CPU=13000000
	avr-objcopy -O binary a.out a.bin

flash : a.bin
	avrdude -c jtagmkI -P /dev/ttyUSB0 -U flash:w:a.bin:r -p m128 -B 38400

clean:
	rm -rf bin
