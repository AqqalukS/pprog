FLAGS = -Wall -std=gnu99

.PHONEY		: default clean 
default		: out.txt		; cat ./$<
out.txt 	: hello			; ./$< > $@
clean 		:			; $(RM) hello *.txt
