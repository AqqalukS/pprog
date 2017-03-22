CFLAGS = -Wall -std=gnu99
LBLIBS = -lm
PLOT = plot.gpi
PLOTTER = gnuplot


#test.io.out.txt: main-stdio
#	echo 1 2 3 4 5 	| ./$< >$@
#	echo `seq 1 0.5 4` | ./$< >$@

#test.cmd.out.txt: main-cmdline
#	./$< echo 1 2 3 4 5 6  >$@
#	./$< echo `seq 0 0.5 2` >$@

plot.pdf 	: plot.ps 				; ps2pdf $< 

# main-stdio
io.out.txt	: input.data.txt main-stdio		; ./$(word 2,$^) < $< > $@

# main-cmdline
cmd.out.txt	: input.data.txt main-cmdline		; ./$(word 2,$^) `cat $<` > $@

input.data.txt	: Makefile				; echo `seq 0 0.2 5` > $@

plot.ps : io.out.txt cmd.out.txt Makefile
	echo 'set term postscript clip enhanced color' 			> $(PLOT)
	echo 'set out "$@"'					>> $(PLOT)
	echo 'set key out' 						>> $(PLOT)
	echo 'set xlabel "x" '						>> $(PLOT)
	echo 'set ylabel "f(x)" '					>> $(PLOT)
	echo 'plot \' 							>> $(PLOT)
	echo ' "$(word 1,$^)" with point title "cos(x) using stdio" \' 	>> $(PLOT)
	echo ',"$(word 2,$^)" with point title "sin(x) using cmdline"\'	>> $(PLOT)
	echo ',sin(x) with lines title "sin(x)" \'			>> $(PLOT)
	echo ',cos(x) with lines title "cos(x)" '			>> $(PLOT) 
	$(PLOTTER) $(PLOT)

.PHONEY: clean
	
clean:
	$(RM) *.txt  main-cmdline main-stdio *.pdf *.ps *.gpi
