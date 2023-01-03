#include "keyboard.h"
#include "std_types.h"

uint8_t inb(uint16_t port) {
	uint8_t in;
	asm volatile("inb %1, %0" : "=a"(in) : "d"(port));
	return in;
}

void outb(uint16_t port, uint8_t out) {
	asm volatile("outb %0, %1" : "=a"(out) : "d"(port));
}

void sleep(uint32_t amt) {
	while (amt--)
		asm volatile("nop");
}
