CFLAGS = -Wall -std=gnu99 `gsl-config --cflags`
LDLIBS = `gsl-config --libs`

p_logic.png p_orbit.png : plot.gpi data 	; gnuplot $<

data log 		: main 			; ./$< 1> data 2> log

clean 			: 			; $(RM) data log *.o main *.png
