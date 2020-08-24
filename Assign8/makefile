#
# PROGRAM:  assign8
# AUTHOR:   Andy Olivares
# Z-ID:     z1860934
# DATE DUE: 4/25/2019
#

# Compiler variables
CCFLAGS = -Wall -std=c++11


# Rule to link object code files to create executable file
assign8: assign8.o 
	g++ $(CCFLAGS) -o assign8 assign8.o


assign8.o: assign8.cpp sorts.h quicksort.h mergesort.h
	g++ $(CCFLAGS) -c assign8.cpp
	
	

# Pseudo-target to remove object code and executable files
clean:
	-rm *.o assign8
