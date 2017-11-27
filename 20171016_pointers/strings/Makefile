# Makefile
 
CC=gcc -fsanitize=address
CPPFLAGS= -MMD -D_XOPEN_SOURCE=500
CFLAGS= -Wall -Wextra -pedantic -std=c99 -O2
LDFLAGS=
LDLIBS=
 
# you should at least create empty file insert_sort.c and quick_sort.c in
# order to compile
 
SRC= mystrncpy.c
OBJ= ${SRC:.c=.o}
DEP= ${SRC:.c=.d}
 
all:
 
-include ${DEP}
 
mystrncpy: ${OBJ}
 
clean:
	rm -f ${OBJ} ${DEP} mystrncpy
 
# END
