CFLAGS = -Wall -std=gnu99
LDFLAGS = -lm
.PHONEY: default clean
	
default : out.txt
	cat out.txt

out.txt : Epsilon
	./Epsilon > out.txt # prints the terminal output into the txt out.txt

clean :
	rm -f Epsilon.o Epsilon out.txt
	
