CFLAGS = -Wall -std=gnu99
LDFLAGS = -lm
.PHONEY		: default clean
	
default 	: out.txt		; cat ./$<		# cat shows the out.txt ./$< 
out.txt 	: main			; ./$< > $@		# prints the terminal output into the txt out.txt
clean		:			; $(RM) main *.txt
