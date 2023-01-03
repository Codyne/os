#building the iso file
mkdir -p isodir/boot/grub
cp os.bin isodir/boot/os.bin
cp grub.cfg isodir/boot/grub/grub.cfg
grub-mkrescue -o os.iso isodir

#run it in qemu
qemu-system-x86_64 -cdrom os.iso
