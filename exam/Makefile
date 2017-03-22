CFLAGS = -Wall -std=gnu99 `gsl-config --cflags`
LDLIBS = `gsl-config --libs`

all : report.pdf data

report.pdf : report.tex plot.tex
	pdflatex ./$<
	pdflatex ./$<

plot.tex : plot.gpi data
	gnuplot ./$<

data : main Makefile
	./$< -3 3 0.01 > $@ 

main : main.o my_math.o

main.o my_math.o : my_math.h

clean :
	$(RM) plot.tex *.o main data *.pdf *.ps *.aux *.out *.log *.eps
