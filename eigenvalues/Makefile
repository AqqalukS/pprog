CFLAGS = -Wall -std=gnu99 -O `gsl-config --cflags`
LDLIBS = $$(gsl-config --libs)

plot.png : plot.ppl data
	gnuplot $<

data log : main
	./$< 1> data 2> log 

plot.ppl : Makefile
	echo 'set term png' > $@
	echo 'set out "plot.png"' >> $@
	echo 'plot "data" with lines' >> $@

.PHONEY : clean
clean :
	$(RM) data log main
