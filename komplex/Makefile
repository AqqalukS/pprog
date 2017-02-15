CFLAGS := -Wall -std=gnu99
LDLIBS := -lm

.PHONEY : default clean

default : out4.txt out3.txt out2.txt out.txt
	cat $<

out.txt : p
	./$< > $@

out2.txt : a
	./$< > $@

out3.txt : s
	./$< > $@

out4.txt : komplex
	./$< > $@
	
clean :
	rm -f a p s komplex