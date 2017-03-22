CFLAGS = -Wall -std=gnu99 `gsl-config --cflags`
LDLIBS = `gsl-config --libs` 

#.PHONEY : data

report.pdf : report.tex plot.tex
	pdflatex ./$<
	pdflatex ./$<

plot.tex : plot.gpi data
	gnuplot ./$<

data log : main
	./$< 1> data 2> log

main : main.o integ.o

main.o integ.o : integ.h 

clean :
	$(RM) plot.tex *.o main data log *.pdf *.ps *.aux *.out *.log *.eps
