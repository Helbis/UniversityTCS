# # Define required macros here
# SHELL = /bin/sh

# OBJS = Ex6--4.o Block.o stick.o
# CFLAG = -Wall -g -std=c90
# CC = gcc
# LIBS = -lm

# hello: ${OBJ}
# 	${CC} ${CFLAGS} -o $@ ${OBJS} ${LIBS}

# clean:
# 	rm -f *.o

# .c.o:
# 	${CC} ${CFLAGS} -c $*.c


E : Block.o Ex6--4.o stick.o
	gcc Block.o Ex6--4.o stick.o -o E -lm

Block.o : Block.c 
	gcc -c Block.c

Ex6--4.o : Ex6--4.c 
	gcc -c Ex6--4.c

stick.o : stick.c 
	gcc -c stick.c

clean :
	-rm stick.o Ex6--4.o Block.o