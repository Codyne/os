#include "std_types.h"
#include "keyboard.h"
#include "vga.h"

void kernel_entry() {
	init_vga(WHITE, BLACK);
	kprint("Loaded kernel...\n");
}
