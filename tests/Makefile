##
## EPITECH PROJECT, 2025
## Asembly
## File description:
## Makefile
##

NAMELEN = len
SRCLEN = test_strlen.c

NAMEPUT = put
SRCPUT = test_putchar.c

NAMESTRCHR = strchr
SRCSTRCHR = test_strchr.c

NAMESTRRCHR = strrchr
SRCSTRRCHR = test_strrchr.c

NAMESTRCMP = strcmp
SRCSTRCMP = test_strcmp.c

NAMESTRNCMP = strncmp
SRCSTRNCMP = test_strncmp.c

NAMESTRCASECMP = strcasecmp
SRCSTRCASECMP = test_strcasecmp.c

NAMESTRSTR = strstr
SRCSTRSTR = test_strstr.c

NAMEMEMSET = memset
SRCMEMSET = test_memset.c

NAMEMEMCPY = memcpy
SRCMEMCPY = test_memcpy.c

NAMEMEMMOVE = memmove
SRCMEMMOVE = test_memmove.c

NAMESTRCSPN = strcspn
SRCSTRCSPN = test_strcspn.c

NAMESTRPBRK = strpbrk
SRCSTRPBRK = test_strpbrk.c

all: $(NAMELEN) #$(NAMEPUT) $(NAMESTRCHR) $(NAMESTRRCHR) $(NAMESTRCMP) $(NAMESTRNCMP) $(NAMESTRCASECMP) $(NAMESTRSTR) $(NAMEMEMSET)

$(NAMELEN): $(SRCLEN)
	gcc -o $(NAMELEN) $(SRCLEN) -ldl
	gcc -o $(NAMEPUT) $(SRCPUT) -ldl
	gcc -o $(NAMESTRCHR) $(SRCSTRCHR) -ldl
	gcc -o $(NAMESTRRCHR) $(SRCSTRRCHR) -ldl
	gcc -o $(NAMESTRCMP) $(SRCSTRCMP) -ldl
	gcc -o $(NAMESTRNCMP) $(SRCSTRNCMP) -ldl
	gcc -o $(NAMESTRCASECMP) $(SRCSTRCASECMP) -ldl
	gcc -o $(NAMESTRSTR) $(SRCSTRSTR) -ldl
	gcc -o $(NAMEMEMSET) $(SRCMEMSET) -ldl
	gcc -o $(NAMEMEMCPY) $(SRCMEMCPY) -ldl
	gcc -o $(NAMEMEMMOVE) $(SRCMEMMOVE) -ldl
	gcc -o $(NAMESTRCSPN) $(SRCSTRCSPN) -ldl
	gcc -o $(NAMESTRPBRK) $(SRCSTRPBRK) -ldl

clean:
	rm -f $(NAMELEN) $(NAMEPUT) $(NAMESTRCHR) $(NAMESTRRCHR) $(NAMESTRCMP) $(NAMESTRNCMP)
	rm -f $(NAMESTRCASECMP) $(NAMESTRSTR) $(NAMEMEMSET) $(NAMEMEMCPY) $(NAMEMEMMOVE)
	rm -f $(NAMESTRCSPN) $(NAMESTRPBRK)

fclean: clean
	
re: fclean all
