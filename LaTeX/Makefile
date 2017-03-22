FLAGS = -Wall -std=gnu99 `gsl-config --cflags`
LDLIBS = `gsl-config --libs`

all: plot.pdf data.txt report.pdf

report.pdf : report.tex
	pdflatex ./$< 
	pdflatex ./$< 

plot.pdf : plot.ps
	ps2pdf ./$<

plot.ps : plot.gpi data.txt
	gnuplot $<

data.txt : main Makefile
	 ./$< -3 3 0.2 >$@

.PHONEY : clean

clean :
	$(RM) main *.ps *.pdf *.out *.log *.aux *.txt
