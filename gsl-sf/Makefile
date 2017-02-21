CFLAGS = -Wall -std=gnu99 -O `gsl-config --cflags`
LDLIBS = $$(gsl-config --libs)


plot.png : plot.ppl data
	gnuplot $<

data : main
	./$< > $@

plot.ppl : Makefile
	echo 'set term png' > $@
	echo 'set out "plot.png"' >> $@
	echo 'set ylabel "f(x)"' >> $@
	echo 'set xlabel "x"' >> $@
	echo 'plot \' >> $@ 
	echo ' "data" using 1:2 with lines title "J_0" \' >> $@ 
	echo ',"data" using 1:3 with lines title "J_1" ' >> $@
.PHONEY: test

test:
	echo $(CFLAGS)
	echo $(LBLIBS)

.PHONEY: clean 
clean :
	$(RM) main plot* *.png data
