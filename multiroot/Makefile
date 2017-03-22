CFLAGS = -Wall -std=gnu99 `gsl-config --cflags`
LDLIBS = `gsl-config --libs`

plot.pdf : plot.ps
	ps2pdf $<

plot.ps : plot.gpi data
	gnuplot $< 

data log : main
	./$< 2 3 4 6 8 1> data 2> log

main : main.o multiroot.o

main.o multiroot.o : multiroot.h

clean :
	$(RM) main data log *.o *.ps *.pdf
