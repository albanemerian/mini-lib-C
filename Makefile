##
## EPITECH PROJECT, 2025
## Asembly
## File description:
## Makefile
##


NAME = libasm.so

SRC = 	strlen.asm	\
		strchr.asm	\
		strrchr.asm	\
		strcmp.asm	\
		strncmp.asm	\
		strcasecmp.asm	\
		strstr.asm	\
		memset.asm	\
		memcpy.asm	\
		memmove.asm	\
		strcspn.asm	\
		strpbrk.asm

OBJ = $(SRC:.asm=.o)

NASM = nasm

NASMFLAGS = -f elf64

LD = ld

LDFLAGS = -shared -o

CC = gcc

CFLAGS = -L. -lasm

all: bonus $(NAME) compile_bonus

OBJ = $(SRC:.asm=.o)

$(NAME): $(OBJ)
	$(LD) $(LDFLAGS) $(NAME) $(OBJ)
	@ cp -f $(NAME) tests/

%.o: %.asm
	$(NASM) $(NASMFLAGS) $< -o $@

test: main.o $(NAME)
	$(CC) main.o -o test $(CFLAGS)

main.o: main.c
	$(CC) -c main.c -o main.o

clean:
	rm -f $(OBJ) main.o
	@ rm -rf tests/*.so

fclean: clean
	rm -f $(NAME) test
	$(MAKE) -C bonus fclean
	$(MAKE) -C tests fclean

re: fclean bonus all

compile_bonus:
	$(MAKE) -C bonus

tests: all
	$(MAKE) -C tests
	@ cd tests/ && ./test.sh && cd ..

test_run:
	$(MAKE) -C tests
