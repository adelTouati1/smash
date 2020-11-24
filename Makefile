#------------------------------------------------------------------------------
#
# Makefile --- Re-usable makefile for building many simple projects
#
# Usage
#	make all	Build the released product
#	make clean	Remove build artifacts
#
# Author(s)
# 01/11/18 Epoch............................................................jrc
#
#------------------------------------------------------------------------------

#-------Define names of all the object files in this project
	OBJS = smash.o history.o

#-------Define the name of the resulting released product
	EXE = smash

#-------Define options passed by make to the compiler
	CFLAGS = -Wall -std=c99 -g

#-------Define the name of the compiler to be used
	CC = gcc

#-------Define target "all" for building the executable(s)
all:	$(EXE)

#-------Rule for linking the executable product
$(EXE): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f $(OBJS) $(EXE) *~
