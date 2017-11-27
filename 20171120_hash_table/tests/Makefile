# Makefile
 
CC = gcc -fsanitize=address
CPPFLAGS = -MMD
CFLAGS = -Wall -Wextra -std=c99 -O0 -g
LDFLAGS =
LDLIBS =
 
OBJ = test.o ../hash_table.o 
DEP = ${OBJ:.o=.d}
 
all: test
 
test: ${OBJ}
 
.PHONY: clean
 
clean:
	${RM} ${OBJ} ${DEP} test
	${RM} ${OBJ} ${DEP} hash_table

-include ${DEP}
 
# END
