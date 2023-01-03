#ifndef VGA_H
#define VGA_H

#include "std_types.h"

#define VGA_ADDR 0xB8000
#define BUFF_SIZE 2200

enum vga_color {
	BLACK,
	BLUE,
	GREEN,
	CYAN,
	RED,
	MAGENTA,
	BROWN,
	GREY,
	DARK_GREY,
	BRIGHT_BLUE,
	BRIGHT_GREEN,
	BRIGHT_CYAN,
	BRIGHT_RED,
	BRIGHT_MAGENTA,
	YELLOW,
	WHITE,
};

void init_vga(uint8_t fg_color, uint8_t bg_color);
void clear_vga_buffer(uint16_t **buff, uint8_t fg_color, uint8_t bg_color);
uint16_t vga_entry(uint8_t ch, uint8_t fg_color, uint8_t bg_color);
void kprint(char *str);

#endif
