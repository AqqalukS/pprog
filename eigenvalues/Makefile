CFLAGS = -Wall -std=gnu99 -O `gsl-config --cflags`
LBLIBS = $$(gsl-config --libs)

data log : main
	./< 1> data 2> log

