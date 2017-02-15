CFLAGS = -Wall -std=gnu99
LBLIBS = -lm

all: gnuplot.pdf plot.pdf

gnuplot.pdf: gnuplot.tex plot.tex
	pdflatex $<
	pdflatex $<

plot.pdf plot.tex: plot.gpi data
	gnuplot plot.gpi
	
data: main
	./main 1> data 2> log
	
.PHONEY: clean
	
clean:
	$(RM) data log *.aux *.log *.pdf plot.tex *.o *~