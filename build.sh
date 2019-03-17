nasm -f elf32 kernel.asm -o kasm.o
gcc -m32 -c kmain.c -o kmain.o
ld -m elf_i386 -T link.ld -o kernel.bin kmain.o kasm.o
qemu-system-i386 -kernel kernel.bin
