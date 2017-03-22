CFLAGS = -Wall -std=c99
LDLIBS = -lm

CC = gcc

.PHONEY: all clean indent test

all : out.txt			; cat $<		# "$<" is the first prerequisite
out.txt : main			; ./$< > $@		# "$@" is the target
main 				: main.o nvector.o	# build-in linking rule is used here
main.o nvector.o 		: nvector.h		# build-in compilation rule is used here
clean: 				; $(RM) out.txt main *.o *~
indent :			; indent --linux-style *.c; rm -f *.c~
