CFLAGS = -Wall -std=gnu99 -O `gsl-config --cflags`
LDLIBS = $$(gsl-config --libs)

all: plot.png

plot.png : plot.ppl data
	gnuplot $<

data log : main
	./$< 1> data 2> log 

.PHONEY : clean
clean :
	$(RM) data log main *.png 
