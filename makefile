BL_O=bootloader/boot.o
KERNEL_O=kernel/*.o
OS_BIN=os.bin

all: boot kernel ld grub

boot: FORCE
	@$(MAKE) -C bootloader

kernel: FORCE
	@$(MAKE) -C kernel

ld: FORCE
	ld -m elf_i386 -T linker.ld $(BL_O) $(KERNEL_O) -o $(OS_BIN) -nostdlib

grub: FORCE
	grub-file --is-x86-multiboot $(OS_BIN)



clean: clean_boot clean_kernel
	@echo "Cleaning binaries..."
	@rm -rf isodir os.bin os.iso

clean_boot: FORCE
	@$(MAKE) clean -C bootloader

clean_kernel: FORCE
	@$(MAKE) clean -C kernel



FORCE:
