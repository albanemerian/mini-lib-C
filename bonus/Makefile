##
## EPITECH PROJECT, 2025
## Asembly
## File description:
## Makefile
##


NAME = libasmo.so

SRC = 	putchar.asm

OBJ = $(SRC:.asm=.o)

NASM = nasm

NASMFLAGS = -f elf64

LD = ld

LDFLAGS = -shared -o

CC = gcc
CFLAGS = -L. -lasm

all: $(NAME)

$(NAME): $(OBJ)
	$(LD) $(LDFLAGS) $(NAME) $(OBJ)
	@cp -f $(NAME) ../tests/

%.o: %.asm
	$(NASM) $(NASMFLAGS) $< -o $@

test: main.o $(NAME)
	$(CC) main.o -o test $(CFLAGS)

main.o: main.c
	$(CC) -c main.c -o main.o

clean:
	rm -f $(OBJ) main.o

fclean: clean
	rm -f $(NAME) test

re: fclean all
