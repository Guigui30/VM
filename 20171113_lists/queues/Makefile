# Makefile
 
CC = gcc -fsanitize=address
CPPFLAGS = -MMD
CFLAGS = -Wall -Wextra -std=c99 -O0 -g
LDFLAGS =
LDLIBS =
 
OBJ = queue.o tree.o
DEP = ${OBJ:.o=.d}
 
all: tree
 
tree: ${OBJ}
 
.PHONY: clean
 
clean:
	${RM} ${OBJ} ${DEP} tree
	${RM} ${OBJ} ${DEP} queue

-include ${DEP}
 
# END
