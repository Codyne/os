CC=gcc
CFLAGS=-m32 -I include/ -ffreestanding -O2 -Wall -Wextra

SRC_FILES := $(wildcard *.c)
OBJ_FILES := $(patsubst %.c,%.o,$(SRC_FILES))

all: kernel

kernel: $(OBJ_FILES)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean: FORCE
	@echo "Cleaning kernel..."
	@rm -f *.o

FORCE:
