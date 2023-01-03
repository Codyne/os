#include "vga.h"

uint16_t *vga_buffer;
uint32_t vga_idx;
uint32_t vga_line;

uint8_t fg_c = WHITE;
uint8_t bg_c = BLACK;

uint32_t d_ascii[10] = {
	0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39
};

void init_vga(uint8_t fg_color, uint8_t bg_color) {
	vga_buffer = (uint16_t *)VGA_ADDR;
	clear_vga_buffer(&vga_buffer, fg_color, bg_color);
}

void clear_vga_buffer(uint16_t **buff, uint8_t fg_color, uint8_t bg_color) {
	for(uint32_t i = 0; i < BUFF_SIZE; i++)
		(*buff)[i] = vga_entry(NULL, fg_color, bg_color);

	vga_idx = 0;
	vga_line = 0;
}

uint16_t vga_entry(uint8_t ch, uint8_t fg_color, uint8_t bg_color) {
	uint16_t ax = 0;
	uint8_t ah = 0, al = 0;

	ah = bg_color;
	ah <<= 4;
	ah |= fg_color;
	ax = ah;
	ax <<= 8;
	al = ch;
	ax |= al;

	return ax;
}

void print_ch(uint8_t ch) {
	if (ch == '\n') {
		vga_line++;
		vga_idx = vga_line * 80;
	} else {
		vga_buffer[vga_idx] = vga_entry(ch, fg_c, bg_c);
		vga_idx++;
	}
}

void kprint(char *str) {
	for (uint32_t i = 0; str[i]; i++)
		print_ch(str[i]);
}
