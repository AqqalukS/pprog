# this is a Makefile that build all sub directories.

TARGET := all clean

SUBDIRS := $(wildcard */) 
# Wildcard is a function, that in this case, gives a list of all sub diretories (*/).
#  := saves the list 

.PHONY: $(TARGET) $(SUBDIRS)
# by declaring the sud directories as .PHONY, the sub build will stop if there is an error

$(TARGET) : $(SUBDIRS)

$(SUBDIRS):
	$(MAKE) -C $@ $(MAKECMDGOALS)
# -C changes directory, $(MAKECMDGOALS) puts the commandline input after make.
