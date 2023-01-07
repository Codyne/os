#include "vga.h"
#include "mem.h"
#include "ports.h"

#define TERM_COLS 80
#define TERM_ROWS 20

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
	return (((bg_color << 4) | fg_color) << 8) | ch;
}

void scroll_term() {
	vga_line = TERM_ROWS - 1;
	memcpy((uint8_t *)vga_buffer, (uint8_t *)(vga_buffer + TERM_COLS),
		   TERM_COLS * (TERM_ROWS - 1) * 2);
	memset((uint8_t *)(vga_buffer + (TERM_COLS * (TERM_ROWS - 1))),
		   0, TERM_COLS * 2);
}

void cur_next_line() {
	if (++vga_line >= TERM_ROWS)
		scroll_term();
	vga_idx = vga_line * TERM_COLS;
}

void print_ch(uint8_t ch) {
	if (ch == '\n') {
		cur_next_line();
	} else {
		vga_buffer[vga_idx] = vga_entry(ch, fg_c, bg_c);
		vga_idx++;

		if (vga_idx && !(vga_idx % TERM_COLS))
			cur_next_line();
	}
}

void kprint(char *str) {
	for (uint32_t i = 0; str[i]; i++)
		print_ch(str[i]);
}
