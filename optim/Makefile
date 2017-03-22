FLAGS = -Wall -std=gnu99 `gsl-config --cflags`
LDLIBS = `gsl-config --libs`

report.pdf : report.tex plot.tex
	pdflatex ./$<
	pdflatex ./$<

plot.tex : plot.gpi data
	gnuplot ./$<

data log : main
	./$< 1> data 2> log

main : main.o optim.o

clean : 
	$(RM) main data log *.o *.log *.aux plot.tex *.eps *.pdf
